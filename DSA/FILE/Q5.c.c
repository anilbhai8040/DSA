#include<stdio.h>
int main()
{
	char ch,name[50];
	int no;
	FILE *ptr;
	ptr=fopen("input.txt","a");
	
	do
	{
		printf("\nRoll No : ");
		scanf("%d",&no);
		
		fflush(stdin);
		printf("Name : ");
		gets(name);
		
		printf("Class : ");
		scanf("%c",&ch);
		
		fprintf(ptr,"ROLL No    : %d\n",no);
		fprintf(ptr,"NAME       : %s\n",name);
		fprintf(ptr,"Class Nmae : %c\n\n",ch);

		fflush(stdin);
		printf("\nYou want insert new record (Y/N) : ");
		ch=getchar();
	}while(ch=='Y' || ch=='y');
	fclose(ptr);
	
	ptr=fopen("input.txt","r");
	while(!feof(ptr))
	{
		fgets(name,50,ptr);
		printf("%s",name);
	}
	fclose(ptr);
		
	return 0;
}
