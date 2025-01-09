//QUEUE USING LINK LIST
#include<stdio.h>
#include<malloc.h>
struct abc
{
	int no;
	struct abc *next;
}*lp=NULL;
int count;
typedef struct abc node;
void enqueue(node *);
void dequeue(node *);
void peek(node *);
void display(node *);
int main()
{
	int choise;
	anil:
	printf("\n1.enqueue.");
	printf("\n2.dequeue.");
	printf("\n3.peek.");
	printf("\n4.display.");
	printf("\n5.exit.");
	printf("\n\nEnter your choise : ");
	scanf("%d",&choise);
	
	switch(choise)
	{
		case 1:
			enqueue(lp);
			goto anil;
		
		case 2:
			dequeue(lp);
			goto anil;
		
		case 3:
			peek(lp);
			goto anil;
			
		case 4:
			display(lp);
			goto anil;
			
		case 5:
			goto baraiya;
		
		
		default:
			printf("\ninvalid choise....\n");
			goto anil;
	}
	
	baraiya:
	return 0;
}

void enqueue(node *ptr)
{
	node *new1;
	new1=(node *)malloc(sizeof(node));
	new1->next=NULL;
	printf("no = ");
	scanf("%d",&new1->no);
	if(ptr==NULL)
	{
		lp=new1;
	}
	else
	{
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=new1;
	}
	count++;
}

void dequeue(node *ptr)
{
	if(ptr==NULL)
	{
		printf("\nqueue is empty...\n");
	}
	else if(ptr->next==NULL)
	{
		lp=NULL;
		count--;
		free(ptr);
	}
	else
	{
		lp=lp->next;
		free(ptr);
		count--;
	}
}

void peek(node *ptr)
{
	if(lp==NULL)
	{
		printf("\nqueue is empty...\n");
	}
	else
	{
		printf("\n%d  \n",lp->no);
	}
}

void display(node *ptr)
{
	if(lp==NULL)
	{
		printf("\nqueue is empty....\n");
	}
	else
	{
		printf("\nDisplay queue node : ");
		while(ptr!=NULL)
		{
			printf("%d  ",ptr->no);
			ptr=ptr->next;
		}
		printf("\ntotal node in queue = %d\n",count);
	}
}
