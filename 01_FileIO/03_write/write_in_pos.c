#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>


/*
 * ./write_in_pos 1.txt
 * argc = 2
 * argv[0] = "./write_in_pos"
 * argv[1] = "1.txt"
 *
 * 注意文件权限umask,002:000 000 010,其他用户没有写w权限，是系统保护措施
 * mode & ~umask
 * 使用lseek函数，从特定pos写入，覆盖当前位置
 */

int main(int argc, char **argv)
{
	int fd;
	int i;
	int len;
	
	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return -1;
	}
	fd = open(argv[1], O_RDWR | O_CREAT, 0644);
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

	printf("lseek to offset 3 from file head\n");
	lseek(fd, 3, SEEK_SET);
	write(fd, "123", 3);
	
	
	close(fd);
	return 0;
}
