#include "protocol.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
 
int main()
{
	int fd = shm_open(NAME, O_RDWR, 0666);
	char *data = mmap(0, SIZE,PROT_READ, MAP_SHARED, fd,0);
	printf("RECEIVER MAPPED ADDRESS: %p\n", data);
	printf("%s\n", data);
	munmap(data, SIZE);
	close(fd);
//	shm_unlink(NAME);
	return 0;
}
