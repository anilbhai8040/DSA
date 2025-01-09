#include<stdio.h>
#include<malloc.h>
struct abc
{
	int no;
	struct abc *pre;
	struct abc *next;
}*lp=NULL,*rp=NULL;
typedef struct abc node;
void create(node *);
void insert_first(node *);
void insert_last(node *);
void insert_before(node *);
void insert_after(node *);
void insert_fix(node *);
void delete_first(node *);
void delete_last(node *);
void delete_before(node *);
void delete_after(node *);
void delete_fix(node *);
void change_value(node *);
void change_fix(node *);
void destroyed_link(node *);
void display(node *);
int main()
{
	int choise;
    anil:
	printf("\n1.create.");
	printf("\n2.insert_first.     7.delete_first.");
	printf("\n3.insert_last.      8.delete_last.");
	printf("\n4.insert_before.    9.delete_before.");
	printf("\n5.insert_after.     10.delete_after.");
	printf("\n6.insert_fix.       11.delete_fix.");
	printf("\n\n12.change_value.    13.change_fix.");
	printf("\n\n14.display.         15.exit.");
	printf("\n\n16.destroyed_link.");
	printf("\n\nenter your choise : ");
	scanf("%d",&choise);

	switch(choise)
	{
		case 1:
			lp=(node *)malloc(sizeof(node));
			create(lp);
			goto anil;
		case 2:
			insert_first(lp);
			goto anil;
		case 3:
			insert_last(rp);
			goto anil;
		case 4:
			insert_before(lp);
			goto anil;
		case 5:
			insert_after(lp);
			goto anil;
		case 6:
			insert_fix(lp);
			goto anil;
		case 7:
			delete_first(lp);
			goto anil;
		case 8:
			delete_last(rp);
			goto anil;
		case 9:
			delete_before(lp);
			goto anil;
		case 10:
			delete_after(lp);
			goto anil;
		case 11:
			delete_fix(lp);
			goto anil;
		case 12:
			change_value(lp);
			goto anil;
		case 13:
			change_fix(lp);
			goto anil;
		case 14:
			display(lp);
			goto anil;
		case 15:
			goto baraiya;
		case 16:
			destroyed_link(lp);
			goto anil;
		default:
			printf("your choice is incorrect....");
			goto anil;
	}
baraiya:
	return 0;
}
void create(node *ptr)
{
	int k=0;
	char ch;
	ptr->pre=NULL;
	do
	{
		printf("\nenter value of node %d  ",k+1);
		printf("\nno = ");
		scanf("%d",&ptr->no);
		fflush(stdin);
		printf("\nyou want to create new node (y/n) : ");
		ch=getchar();

		if(ch=='y' || ch=='Y')
		{
			ptr->next=(node *)malloc(sizeof(node));
			ptr->next->pre=ptr;
			ptr=ptr->next;
		}
		else
		{
			ptr->next=NULL;
			rp=ptr;
		}
		k++;

	}
	while(ch=='y' || ch=='Y');
}
void display(node *ptr)
{
	int count=0;
	printf("\ndisplay node  :   ");
	while(ptr!=NULL)
	{
		printf("%d  ",ptr->no);
		ptr=ptr->next;
		count++;
	}
	printf("\ntotal node in list : %d\n",count);
}
void insert_first(node *ptr)
{
	node *new1;
	new1=(node *)malloc(sizeof(node));
	new1->pre=new1->next=NULL;
	printf("enter value of no : ");
	scanf("%d",&new1->no);

	if(ptr==NULL)
	{
		lp=rp=new1;
	}
	else
	{
		new1->next=ptr;
		ptr->pre=new1;
		lp=new1;
	}

}
void insert_last(node *ptr)
{
	node *new1;
	new1=(node *)malloc(sizeof(node));
	new1->pre=new1->next=NULL;
	printf("enter value of no : ");
	scanf("%d",&new1->no);

	if(ptr==NULL)
	{
		lp=rp=new1;
	}
	else
	{
		rp->next=new1;
		new1->pre=rp;
		rp=new1;
	}

}
void insert_before(node *ptr)
{
	int key;
	node *new1;
	new1=(node *)malloc(sizeof(node));
	new1->pre=new1->next=NULL;
	printf("enter value of no : ");
	scanf("%d",&new1->no);
	fflush(stdin);

	printf("enter key value : ");
	scanf("%d",&key);

	if(ptr==NULL)
	{
		lp=rp=new1;
	}
	else
	{
		while(ptr->no!=key && ptr->next!=NULL)
		{
			ptr=ptr->next;
		}

		if(ptr==lp)
		{
			new1->next=ptr;
			ptr->pre=new1;
			lp=new1;
		}
		else if(ptr->no==key)
		{
			ptr->pre->next=new1;
			new1->pre=ptr->pre;
			new1->next=ptr;
			ptr->pre=new1;
		}
		else
		{
			printf("\nnode is not insert because key value not found.");
		}
	}
}
void insert_after(node *ptr)
{
	int key;
	node *new1;
	new1=(node *)malloc(sizeof(node));
	new1->pre=new1->next=NULL;
	printf("enter value of no : ");
	scanf("%d",&new1->no);
	fflush(stdin);

	printf("enter key value : ");
	scanf("%d",&key);

	if(ptr==NULL)
	{
		lp=rp=new1;
	}
	else
	{
		while(ptr->no!=key && ptr->next!=NULL)
		{
			ptr=ptr->next;
		}

		if(ptr==rp && rp->no==key)
		{
			new1->pre=ptr;
			ptr->next=new1;
			rp=new1;
		}
		else if(ptr->no==key)
		{
			ptr->next->pre=new1;
			new1->next=ptr->next;
			new1->pre=ptr;
			ptr->next=new1;
		}
		else
		{
			printf("\nnode is not insert because key value not found.");
		}
	}
}
void insert_fix(node *ptr)
{
	int p=1,key,sum;
	node *new1;
	new1=(node *)malloc(sizeof(node));
	new1->next=new1->pre=NULL;
	printf("enter the position when you want create node : ");
	scanf("%d",&key);
	printf("enter the value of no :- ");
	scanf("%d",&new1->no);
	fflush(stdin);

	if(ptr==NULL)
	{
		if(key==1)
		{
			lp=rp=new1;
		}
		else
		{
			printf("node is not inserted in the link");
		}
	}
	else
	{
		while(p!=key && ptr->next!=NULL)
		{
			ptr=ptr->next;
			p++;
		}

		if(p==key && ptr==lp)
		{
			new1->next=ptr;
			ptr->pre=new1;
			lp=new1;
		}
		else if(p==key)
		{
			ptr->pre->next=new1;
			new1->pre=ptr->pre;
			new1->next=ptr;
			ptr->pre=new1;
		}
		else if(p+1==key)
		{
			rp->next=new1;
			new1->pre=rp;
			rp=new1;
		}
		else
		{
			printf("node is not inserted in the link");
		}
	}
}
void delete_first(node *ptr)
{
	if(lp==NULL)
	{
		printf("\nlist is empty....\n");
	}
	else if(lp==rp)
	{
		lp=rp=NULL;
		free(ptr);
	}
	else
	{
		lp=lp->next;
		lp->pre=NULL;
		free(ptr);
	}
}
void delete_last(node *ptr)
{
	if(lp==NULL)
	{
		printf("\nlist is empty....\n");
	}
	else if(lp==rp)
	{
		lp=rp=NULL;
		free(ptr);
	}
	else
	{
		rp=rp->pre;
		rp->next=NULL;
		free(ptr);
	}
}
void delete_before(node *ptr)
{
	int key;
	printf("enter key value : ");
	scanf("%d",&key);

	if(lp==NULL)
	{
		printf("\nlist is empty....\n");
	}
	else if(lp->no==key)
	{
		printf("\nthis is first node...\n");
	}
	else
	{
		while(ptr->no!=key && ptr->next!=NULL)
		{
			ptr=ptr->next;
		}

		if(ptr->pre==lp && ptr->no==key)
		{
			lp=lp->next;
			free(ptr->pre);
			lp->pre=NULL;

		}
		else if(ptr->no==key)
		{
			ptr=ptr->pre;
			ptr->pre->next=ptr->next;
			ptr->next->pre=ptr->pre;
			free(ptr);
		}
		else
		{
			printf("\nkey value is not found...");
		}
	}
}
void delete_after(node *ptr)
{
	int key;
	printf("enter key value : ");
	scanf("%d",&key);

	if(lp==NULL)
	{
		printf("\nlist is empty....\n");
	}
	else if(rp->no==key)
	{
		printf("\nthis is last node...\n");
	}
	else
	{
		while(ptr->no!=key && ptr->next!=NULL)
		{
			ptr=ptr->next;
		}

		if(ptr->next==rp && ptr->no==key)
		{
			rp=rp->pre;
			free(ptr->next);
			rp->next=NULL;
			
		}
		else if(ptr->no==key)
		{
			ptr=ptr->next;
			ptr->pre->next=ptr->next;
			ptr->next->pre=ptr->pre;
			free(ptr);
		}
		else
		{
			printf("\nkey value is not found...");
		}
	}
}
void delete_fix(node *ptr)
{
	int key,p=1;
	printf("enter key value : ");
	scanf("%d",&key);

	if(lp==NULL)
	{
		printf("\nlist is empty....\n");
	}
	else if(key==1 && lp==rp)
	{
		lp=rp=NULL;
		free(ptr);
	}
	else
	{
		while(p!=key && ptr->next!=NULL)
		{
			p++;
			ptr=ptr->next;
		}

		if(p==1)
		{
			lp=lp->next;
			lp->pre=NULL;
			free(ptr);
		}

		else if(p==key && ptr==rp)
		{
			rp=rp->pre;
			rp->next=NULL;
			free(ptr);
		}
		else if(p==key)
		{
			ptr->pre->next=ptr->next;
			ptr->next->pre=ptr->pre;
			free(ptr);
		}
		else
		{
			printf("\nkey value is not found...");
		}
	}
}
void change_value(node *ptr)
{
	int key;
	if(ptr==NULL)
	{
		printf("\nlist is empty...\n");
	}
	else
	{
		printf("enter the node value you want to change : ");
		scanf("%d",&key);
		while(ptr->no!=key && ptr->next!=NULL)
		{
			ptr=ptr->next;
		}

		if(ptr->no==key)
		{
			printf("enter the new value you want to insert : ");
			scanf("%d",&ptr->no);
		}
		else
		{
			printf("\nkey value is not found....\n");
		}
	}
}
void change_fix(node *ptr)
{
	int key,p=1;
	if(ptr==NULL)
	{
		printf("\nlist is empty...\n");
	}
	else
	{
		printf("enter the position of node you want to change : ");
		scanf("%d",&key);
		while(p!=key && ptr->next!=NULL)
		{
			ptr=ptr->next;
			p++;
		}

		if(p==key)
		{
			printf("enter the new value you want to insert : ");
			scanf("%d",&ptr->no);
		}
		else
		{
			printf("\nkey value is not found....\n");
		}
	}
}
void destroyed_link(node *ptr)
{
	if(lp==NULL)
	{
		printf("\nlist is empty....\n");
	}
	else
	{
		while(ptr!=NULL)
		{
			   lp=lp->next;
			   free(ptr);
			   ptr=lp;
			   printf("\n%d",lp);		
		}
	    lp=rp=NULL;
		printf("\nlink delete successful....\n");
	}
}
