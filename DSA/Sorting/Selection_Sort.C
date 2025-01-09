#include<stdio.h>
#include<conio.h>
void main()
{
  int i,j,min,temp,no,a[50];
  clrscr();
  printf("enter array size : ");
  scanf("%d",&no);

  for(i=0; i<no; i++)
   {
     printf("a[%d] = ",i);
     scanf("%d",&a[i]);
   }
  for(i=0; i<no-1; i++)
   {
     min=i;
     for(j=i; j<no; j++)
      {
	if(a[min]>a[j])
	 {
	    min=j;
	 }

      }
      if(min!=i)
      {
	 temp=a[i];
	 a[i]=a[min];
	 a[min]=temp;
      }
   }
  printf("\nsorted array.\n");
  for(i=0; i<no; i++)
   {
      printf("a[%d] = %d\n",i,a[i]);
   }
  getch();
}