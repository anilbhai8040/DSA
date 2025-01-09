#include<stdio.h>
int main()
{
	int no,high,low,mid,sno,i,temp,j;
	
	printf("enter the array size : ");
	scanf("%d",&no);
	int a[no];
	
	for(i=0; i<no; i++)
	{
		printf("a[%d] : ",i);
		scanf("%d",&a[i]);
	}
	
	for(i=1; i<no; i++)
	{
		temp=a[i];
		j=i-1;
		while(j>=0 && temp<a[j])
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
	printf("\nsorted array...\n");
	for(i=0; i<no; i++)
	{
		printf("\na[%d] = %d",i,a[i]);
	}
	printf("\n\nenter search no : ");
	scanf("%d",&sno);
	
	low=0;
	high=no-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==sno)
		{
			printf("\nsearch no is in the list...");
			break;
		}
		else if(sno<a[mid])
		{
			high=mid-1;
		}
		else 
		{
			low=mid+1;
		}
	}
	if(low>high)
	{
		printf("\nsearch no not in the list....");
	}
	return 0;
}
