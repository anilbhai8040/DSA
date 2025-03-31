#include<stdio.h>
int main()
{
	char ch,sch,k;
	int count=0;
	FILE *ptr;
	ptr=fopen("input.txt","w");
	printf("Write in file : ");
	ch=getchar();
	while(ch!=EOF)
	{
		fputc(ch,ptr);
		ch=getchar();
	}
	fclose(ptr);
	
	ptr=fopen("input.txt","r");
	printf("\nEnter search charecter : ");
	scanf("%c",&sch);
	k=sch;
	if(k>='A' && k<='Z')
	    k+=32;
	else if(k>='a' && k<='z')
	    k-=32;
	ch=fgetc(ptr);
	while(ch!=EOF)
	{
		if(ch==k || ch==sch)
		{
			count++;
		}
		ch=fgetc(ptr);
	}
	if(isalpha(ch))
	    printf("\n%c and %c is %d times repeted in file....",sch,k,count);
	else
	    printf("\n%c is %d times repeted in file....",sch,count);

	    
	fclose(ptr);
	return 0;
}
