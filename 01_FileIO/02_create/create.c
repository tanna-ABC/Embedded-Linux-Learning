#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>


/*
 * ./create 1.txt
 * argc = 2
 * argv[0] = "./creat"
 * argv[1] = "1.txt"
 * 还是使用open函数，新增 O_RDWR | O_CREAT | O_TRUNC，以及文件权限
 * 注意文件权限umask,002:000 000 010,其他用户没有写w权限，是系统保护措施
 * mode & ~umask
 */

int main(int argc, char **argv)
{
	int fd;
	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return -1;
	}
	fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		printf("can not open file %s\n", argv[1]);
		printf("errno = %d\n", errno);
		printf("err: %s\n", strerror(errno));
		perror("open");
	}
	else
	{
		printf("fd = %d\n", fd);
	}
	while(1)
	{
		sleep(10);
	}
	close(fd);
	return 0;
}
