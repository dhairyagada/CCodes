#include <stdio.h>
#include <stdlib.h>

void allocateMemory(unsigned int size)
{
	unsigned char *myAddress=0;

	//Allocate Memory
	myAddress = (unsigned char*)malloc(size * sizeof(unsigned char));
	printf("Address of the allocated memory %p  : %d\n",myAddress,size);

	free(myAddress);

}
int main()
{

	setvbuf(stdout, NULL, _IONBF, 0);

	for(int i=1;i<=100;i++){
		allocateMemory(i*1024);
	}


}

