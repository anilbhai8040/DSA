//STACK USING LINK LIST
#include<stdio.h>
#include<malloc.h>
struct abc
{
	int no;
	struct abc *next;
}*lp=NULL;
int count;
typedef struct abc node;
void push(node *);
void pop(node *);
void peep(node *);
void display(node *);
int main()
{
	int choise;
	anil:
	printf("\n1.push.");
	printf("\n2.pop.");
	printf("\n3.peep.");
	printf("\n4.display.");
	printf("\n5.exit.");
	printf("\n\nEnter your choise : ");
	scanf("%d",&choise);
	
	switch(choise)
	{
		case 1:
			push(lp);
			goto anil;
		
		case 2:
			pop(lp);
			goto anil;
		
		case 3:
			peep(lp);
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

void push(node *ptr)
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

void pop(node *ptr)
{
	node *temp;
	if(ptr==NULL)
	{
		printf("\nstack is empty...\n");
	}
	else if(ptr->next==NULL)
	{
		lp=NULL;
		count--;
		free(ptr);
	}
	else
	{
		while(ptr->next!=NULL)
		{
			temp=ptr;
			ptr=ptr->next;
		}
		temp->next=NULL;
		free(ptr);
		count--;
	}
}

void peep(node *ptr)
{
	int key,flag=0;
	if(lp==NULL)
	{
		printf("\nstack is empty....\n");
	}
	else
	{
		printf("\nenter search value (no) : ");
		scanf("%d",&key);
		
		while(ptr!=NULL)
		{
			if(ptr->no==key)
			{
				flag++;
			}
			ptr=ptr->next;
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

void display(node *ptr)
{
	if(lp==NULL)
	{
		printf("\nstack is empty....\n");
	}
	else
	{
		printf("\nDisplay stack node : ");
		while(ptr!=NULL)
		{
			printf("%d  ",ptr->no);
			ptr=ptr->next;
		}
		printf("\ntotal node in stack = %d\n",count);
	}
}
