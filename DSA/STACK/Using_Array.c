// STACK USING ARRAY
#include<stdio.h>
int a[5];
int top=-1;
void push();
void pop();
void peep();
void peek();
void display();
int main()
{
	int choise;
	
	anil:
		
	printf("\n1.push.");
	printf("\n2.pop.");
	printf("\n3.peep.");
	printf("\n4.display.");
	printf("\n5.exit.");
	printf("\n6.peek.");
	printf("\n\nenter your choise : ");
	scanf("%d",&choise);
	
	switch(choise)
	{
		case 1:
			push();
			goto anil;
			
		case 2:
			pop();
			goto anil;
		
		case 3:
			peep();
			goto anil;
		
		case 4:
			display();
			goto anil;
			
		case 5:
			goto baraiya;
			
		case 6:
			peek();
			goto anil;
		
		default:
			printf("\ninvalid choise......\n");
			goto anil;
	}
	baraiya:
	return 0;	
}

void push()
{
	if(top>=5-1)
	{
		printf("\nstack is full.....\n");
	}
	else
	{
		top++;
		printf("a[%d] = ",top);
		scanf("%d",&a[top]);
	}
	
}

void display()
{
   int i=-1;
   if(top==-1)
   {
   	  printf("\nstack is empty.\n");
   }
   else
   {
   	    while(top!=i)
   	    {
   	    	i++;
   	    	printf("\na[%d] = %d",i,a[i]);
		}
   }	
}

void pop()
{
	if(top==-1)
	{
		printf("\nstack is empty...\n");
	}
	else
	{
		a[top]=0;
		top--;
	}
}

void peep()
{
	int flag=0,i,key;
	if(top==-1)
	{
		printf("\nstack is empty...\n");
	}
	else
	{
		printf("\nEnter search number : ");
		scanf("%d",&key);
		for(i=0; i<=top; i++)
		{
			if(a[i]==key)
			{
				flag++;
			}
		}
		if(flag==0)
		{
			printf("\n%d is not found in stack....\n",key);
		}
		else
		{
			printf("\n %d is %d times repeat in stack...\n",key,flag);
		}
	}

}

void peek()
{
	if(top==-1)
	{
		printf("\nstack is empty...\n");
	}
	else
	{
		printf("\n  %d ",a[top]);
	}
}
