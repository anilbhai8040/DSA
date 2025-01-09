#include<stdio.h>
#include<conio.h>
void sorting(int [],int);             //function declaration
void mearge(int[],int,int[],int,int[]);
void display(int [],int);
void main()
{
   int a1[50],b1[50],no1,n1,c1[100],p,q;
   clrscr();
   printf("enter array size : ");
   scanf("%d",&no1);
   printf("\n");
   for(p=0; p<no1; p++)
    {
      printf("a[%d] = ",p);
      scanf("%d",&a1[p]);
    }
    sorting(a1,no1);		 //function calling

    printf("\n\nenter array size : ");
    scanf("%d",&n1);
     printf("\n");

    for(q=0; q<n1; q++)
     {
       printf("b[%d] = ",q);
       scanf("%d",&b1[q]);
     }
    sorting(b1,n1);
    mearge(a1,no1,b1,n1,c1);
    getch();
}
void mearge(int a[],int no,int b[],int n,int c[])
{
     int i=0,j=0,k=0,x=0,l;
     while(i<no && j<n)
     {
	if(a[i]<b[j])
	{
	  c[k++]=a[i++];
	}
	else if(a[i]>b[j])
	{
	  c[k++]=b[j++];
	}
	else
	{
	  c[k++]=b[j++];
	  x++;
	  i++;
	}

     }
     while(i<no)
      {
	 c[k++]=a[i++];
      }
     while(j<n)
      {
	c[k++]=b[j++];
      }
    l=n+no-x;
    display(c,l);
}
void sorting(int z[],int no2)              //function defination
{
   int o,temp,m;
   for(o=1; o<no2; o++)
     {
       temp=z[o];
       m=o-1;
       while(m>=0 && z[m]>temp)
	{
	  z[m+1]=z[m];      //swap logic
	  m--;
	}
       z[m+1]=temp;
     }
   display(z,no2);
}
void display(int d[], int d1)
{
   int v;
   printf("\n\nsorting array .\n\n");
   for(v=0; v<d1; v++)
    {
       printf("  %d",d[v]);
    }
}
