#include<stdio.h>
#include<conio.h>
int main()
{
  int i,min,j,no,swap=1,count=0;
  //clrscr();
  printf("enter size of array : ");
  scanf("%d",&no);
  printf("\n");
  int a[10];
  for(i=0; i<no; i++)
   {
     printf("a[%d] = ",i);
     scanf("%d",&a[i]);
   }
  while(swap)
  {
	swap=0;
    for(i=0; i<no-1; i++)
      {
	 j=i+1;
	 if(a[i]>a[j])
	   {
	     min=a[i];
	     a[i]=a[j];
	     a[j]=min;
	     swap=1;
	   }
      }

  }

   printf("\nacending order.\n\n");
   for(i=0; i<no; i++)
   {
     printf("a[%d] = %d\n",i,a[i]);
   }
   //getch();
}
