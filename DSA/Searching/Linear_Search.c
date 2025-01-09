#include<stdio.h>
int main()
{
	int no,i,sno,count=0;
	
	printf("enter array limit : ");
	scanf("%d",&no);
	int a[no];
	
	for(i=0; i<no; i++)
	{
		printf("a[%d] = ",i);
		scanf("%d",&a[i]);
	}
	
	printf("\nenter the search no : ");
	scanf("%d",&sno);
	
	for(i=0; i<no; i++)
	{
		if(sno==a[i])
		{
			printf("\na[%d] = %d",i,sno);
			count++;
		}
	}
	if(count==0)
	{
		printf("\n\nsearch number is not in the list....\n");
	}
	else
	{
		printf("\n\ntotal %d times search number repeted.",count);
	}
	
	return 0;
}
