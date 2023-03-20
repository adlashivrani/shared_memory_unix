#include "protocol.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	char buff[SIZE] = "hellooo its a message!";
	char buf[SIZE] = "helloo this is a news!";
	int fd = shm_open(NAME, O_CREAT | O_EXCL | O_RDWR, 0666);
	ftruncate(fd, SIZE); //fixing the size
	char *data = (char *)mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	printf("Sender mapped address: %p\n", data);
	printf("Sender mapped address: %p\n", data + 10);
	strcpy(data, buff);
	strcpy(data + 25, buf);
	//munmap(data, SIZE);
	close(fd);
	return 0;
}
