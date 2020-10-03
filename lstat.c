#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argc ,char *argv[])
{
	struct stat sbuf;
	lstat(argv[1],&sbuf);
	printf("file size:%ld\n",sbuf.st_size);
	
	if(S_ISREG(sbuf.st_mode))
	{
	printf("it's a regular\n");
	} else if(S_ISDIR(sbuf.st_mode)){
		printf("it's a dir\n");
	} else if(S_ISFIFO(sbuf.st_mode)){
		printf("it's a pipe\n");
	} else if(S_ISLNK(sbuf.st_mode)){
		printf("it's a sym link\n");
	}
	return 0;
}
