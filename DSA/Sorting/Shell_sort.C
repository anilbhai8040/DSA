#include<stdio.h>
#include<conio.h>
void main()
{
  int no,i,j,temp,a[30],gap;
  clrscr();
  printf("enter array size : ");
  scanf("%d",&no);

  for(i=0; i<no; i++)
   {
      printf("a[%d] = ",i);
      scanf("%d",&a[i]);

   }

  for(gap=no/2; gap>=1; gap/=2)
   {
     for(j=gap; j<no; j++)
       {
	 for(i=j-gap; i>=0; i-=gap)
	   {
	      if(a[i+gap]>a[i])
	       {
		  break;
	       }
	      else
	      {
		temp=a[i+gap];
		a[i+gap]=a[i];
		a[i]=temp;
	      }

	   }
       }
   }
  printf("\nsorted array. \n");
  for(i=0; i<no; i++)
    {
       printf("\na[%d] = %d",i,a[i]);
    }
  getch();
}