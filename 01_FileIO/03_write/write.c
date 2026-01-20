#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>


/*
 * ./write 1.txt str1 str2
 * argc = 2
 * argv[0] = "./write"
 * argv[1] = "1.txt"
 *
 * 注意文件权限umask,002:000 000 010,其他用户没有写w权限，是系统保护措施
 * mode & ~umask
 */

int main(int argc, char **argv)
{
	int fd;
	int i;
	int len;
	
	if (argc < 3)
	{
		printf("Usage: %s <file> <string1> <string2> ...\n", argv[0]);
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

	for(i=2; i<argc; i++)
	{
		len = write(fd, argv[i], strlen(argv[i]));
		if(len != strlen(argv[i]))
		{
			perror("write");
			break;
		}
		write(fd, "\r\n", 2);
	}
	close(fd);
	return 0;
}
