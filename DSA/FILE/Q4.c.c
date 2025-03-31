#include<stdio.h>
int main()
{
	char ch,name[50];
	FILE *ptr;
	ptr=fopen("input.txt","r");
	
	//using fgets
	printf("read file using fgets.....\n");
	while(!feof(ptr))
	{
		fgets(name,50,ptr);
		printf("%s",name);
	}
	fseek(ptr,0,0);
	
	//using fgets
	printf("read file using fgets only.....\n");
	while(fgets(name,50,ptr))
	{
		printf("%s",name);
	}
	fseek(ptr,0,0);
	
	//using fgetc
	printf("read file using fgetc.....\n");
	while(!feof(ptr))
	{
		ch=fgetc(ptr);
		printf("%c",ch);
	}
	fseek(ptr,0,0);
		
	//using fscanf
	printf("read file using fscanf.....\n");
	while(!feof(ptr))
	{
		fscanf(ptr,"%[^\n]\n",name);
		printf("\n%s",name);
	}
	fseek(ptr,0,0);
	
	//using EOF
	printf("\n\nread file using EOF.....\n");
	ch=fgetc(ptr);
	while(ch!=EOF)
	{
		printf("%c",ch);
		ch=fgetc(ptr);
	}
	fclose(ptr);	
	return 0;
}
