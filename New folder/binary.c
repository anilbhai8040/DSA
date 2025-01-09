#include<stdio.h>
void search(int [],int );
int main()
{
	int i,no,a[10];
	printf("no = ");
	scanf("%d",&no);
	
	for(i=0;i<no;i++)
	{
		printf("a[%d] = ",i);
		scanf("%d",&a[i]);
	}
	
	search(a,no);
	
	 return 0;
}
void search(int a[],int no)
{
	int key,high,low,mid,flag=0;
	high=no-1;
	low=0;
	printf("enter key = ");
	scanf("%d",&key);
	while(low<high)
	{
		mid=(low+high)/2;
		if(a[mid]==key)
		{
			printf("search is sucess...");
			break;
		}
		else if(a[mid]<key)
		{
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
	if(low>high)
	{
		printf("\nsearch is unsucess...");
	}
}
