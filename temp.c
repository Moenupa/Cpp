#include <unistd.h>
#include <stdio.h>

int main () {
	int a=0;
	printf("Lx: %d\n",a);
	if (fork()==0)
		a=a+1;
	printf("Ly: %d\n",a);
	if (fork()==0)
		a=a+2;
	printf("Lz: %d\n",a);
}