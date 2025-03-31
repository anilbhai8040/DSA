#include<stdio.h>
int main()
{
	FILE *ptr;
	ptr=fopen("input.txt","w");
	
	fclose(ptr);
	return 0;
}
