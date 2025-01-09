//QUEUE USING ARRAY
#include<stdio.h>
int a[5];
int front=-1;
int rear=-1;
void enqueue();
void dequeue();
void peek();
void peep();
void display();
int main()
{
	int choise;
	
	anil:
		
	printf("\n1.enqueue.");
	printf("\n2.dequeue.");
	printf("\n3.peek.");
	printf("\n4.peep.");
	printf("\n5.display.");
	printf("\n6.exit.");
	printf("\n\nenter your choise : ");
	scanf("%d",&choise);
	
	switch(choise)
	{
		case 1:
			enqueue();
			goto anil;
			
		case 2:
			dequeue();
			goto anil;
		
		case 3:
			peek();
			goto anil;
			
		case 4:
			peep();
			goto anil;
		case 5:
			display();
			goto anil;
			
		case 6:
			goto baraiya;
		
		default:
			printf("\ninvalid choise......\n");
			goto anil;
	}
	baraiya:
	return 0;	
}

void enqueue()
{
	if(rear>=5-1)
	{
		printf("\nqueue is full.....\n");
	}
	else
	{
		front=0;
		rear++;
		printf("a[%d] = ",rear);
		scanf("%d",&a[rear]);
	}
}

void display()
{
   int i;
   if(rear==-1)
   {
   	  printf("\nqueue is empty.\n");
   }
   else
   {
   	    for(i=front; i<=rear; i++)
   	    {
   	    	printf("\na[%d] = %d",i,a[i]);
		}
   }	
}

void dequeue()
{
	if(front==-1)
	{
		printf("\nqueue is empty...\n");
	}
	else
	{
		front++;
		if(front>rear)
		{
			rear=-1;
			front=-1;
		}
	}
}

void peek()
{
	if(front==-1)
	{
		printf("\nqueue is empty...\n");
	}
	else
	{
		printf("\n%d  \n",a[front]);
	}
}

void peep()
{
	int flag=0,i,key;
	if(rear==-1)
	{
		printf("\nqueue is empty...\n");
	}
	else
	{
		printf("\nEnter search number : ");
		scanf("%d",&key);
		for(i=front; i<=rear; i++)
		{
			if(a[i]==key)
			{
				flag++;
			}
		}
		if(flag==0)
		{
			printf("\n%d is not found in queue....\n",key);
		}
		else
		{
			printf("\n %d is %d times repeat in queue...\n",key,flag);
		}
	}
}
