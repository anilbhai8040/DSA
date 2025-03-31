#include<stdio.h>
int main()
{
	char ch,name[50];
	int no;
	FILE *ptr;
	ptr=fopen("input.txt","w");
	
	//using fprintf
	printf("Roll No : ");
	scanf("%d",&no);
	fprintf(ptr,"%d\n",no);
	
	//using fputs
	fflush(stdin);
	printf("Name : ");
	gets(name);
	fputs(name,ptr);
	
	//using fputc
	printf("Class : ");
	scanf("%c",&ch);
	fprintf(ptr,"\n");
	fputc(ch,ptr);
	fclose(ptr);
	return 0;
}
