#include<stdio.h>
int main()
{
	char ch,name[50];
	int no;
	FILE *ptr;
	ptr=fopen("input.txt","r");
	
	//using fscanf
	fscanf(ptr,"%d\n",&no);
	printf("Roll No : %d",no);
	
	//using fgets
	fflush(stdin);
	fgets(name,50,ptr);
	printf("\nName : %s",name);
	
	//using fgetc
	ch=fgetc(ptr);
	printf("Class : %c",ch);
	fclose(ptr);
	return 0;
}
