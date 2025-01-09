#include<stdio.h>
#include<conio.h>
void sorting(int [],int);             //function declaration
void main()
{
   int i,a[50],no,a1[50],n;
   clrscr();
   printf("enter array size : ");
   scanf("%d",&no);
   for(i=0; i<no; i++)
    {
      printf("a[%d] = ",i);
      scanf("%d",&a[i]);
    }
    sorting(a,no);		 //function calling

    printf("\nenter array size : ");
    scanf("%d",&n);

    for(i=0; i<n; i++)
     {
       printf("a1[%d] = ",i);
       scanf("%d",&a1[i]);
     }
    sorting(a1,n);                     //function calling
    getch();
}
void sorting(int b[],int no1)              //function defination
{
   int i,temp,j;
   for(i=1; i<no1; i++)
     {
       temp=b[i];
       j=i-1;
       while(j>=0 && b[j]>temp)
	{
	  b[j+1]=b[j];      //swap logic
	  j--;
	}
       b[j+1]=temp;
     }
   printf("\nsorting array .\n");
   for(i=0; i<no1; i++)
    {
       printf("a[%d] = %d\n",i,b[i]);
    }

}
