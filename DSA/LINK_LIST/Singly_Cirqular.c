#include<stdio.h>
#include<malloc.h>
int count;
struct abc
{
	int no;
	struct abc *next;
}*lp=NULL;
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
			insert_last(lp);
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
			delete_last(lp);
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
	char ch;
	do
	{
		printf("\nenter value of node %d  ",count+1);
		printf("\nno = ");
		scanf("%d",&ptr->no);
		fflush(stdin);
		printf("\nyou want to create new node (y/n) : ");
		ch=getchar();

		if(ch=='y' || ch=='Y')
		{
			ptr->next=(node *)malloc(sizeof(node));
			ptr=ptr->next;
		}
		else
		{
			ptr->next=lp;
		}
		count++;

	}
	while(ch=='y' || ch=='Y');
}
void display(node *ptr)
{
	int i=1;
	printf("\ndisplay node  :   ");
	while(i<=count*2)
	{
		printf("%d  ",ptr->no);
		ptr=ptr->next;
		i++;
	}
	printf("\ntotal node in list : %d\n",count);
}
void insert_first(node *ptr)
{
	node *new1,*temp;
	new1=(node *)malloc(sizeof(node));
	new1->next=NULL;
	printf("enter value of no : ");
	scanf("%d",&new1->no);

	if(ptr==NULL)
	{
		lp=new1;
		new1->next=lp;
	}
	else
	{
		new1->next=ptr;
		lp=new1;
		temp=ptr;
		while(ptr->next!=temp)
		{
			ptr=ptr->next;
		}
		ptr->next=lp;
	}
	count++;
}

void insert_last(node *ptr)
{
	node *new1;
	new1=(node *)malloc(sizeof(node));
	new1->next=NULL;
	printf("enter value of no : ");
	scanf("%d",&new1->no);

	if(ptr==NULL)
	{
		lp=new1;
		new1->next=lp;
	}
	else
	{
		while(ptr->next!=lp)
		{
			ptr=ptr->next;
		}
		ptr->next=new1;
        new1->next=lp;
	}
	count++;
}

void insert_before(node *ptr)
{
	int key;
	node *new1,*temp;
	new1=(node *)malloc(sizeof(node));
	new1->next=NULL;
	printf("enter value of no : ");
	scanf("%d",&new1->no);
	fflush(stdin);

	printf("enter key value : ");
	scanf("%d",&key);

	if(ptr==NULL)
	{
		lp=new1;
		new1->next=lp;
		count++;
	}
	else if(ptr->no==key)
	{
		new1->next=ptr;
		lp=new1;
		count++;
	}
	else
	{
		while(ptr->no!=key && ptr->next!=lp)
		{
			temp=ptr;
			ptr=ptr->next;
		}

		if(ptr->no==key)
		{
			temp->next=new1;
			new1->next=ptr;
			count++;
		}
		else
		{
			printf("\nnode is not insert because key value not found.");
		}
	}
	
	while(ptr->next!=lp)
	{
		ptr=ptr->next;
	}
	ptr->next=lp;	
}

void insert_after(node *ptr)
{
	int key;
	node *new1,*temp;
	new1=(node *)malloc(sizeof(node));
	new1->next=NULL;
	printf("enter value of no : ");
	scanf("%d",&new1->no);
	fflush(stdin);

	printf("enter key value : ");
	scanf("%d",&key);

	if(ptr==NULL)
	{
		lp=new1;
		new1->next=lp;
		count++;
	}
	else
	{
		while(ptr->no!=key && ptr->next!=lp)
		{
			ptr=ptr->next;
		}

		if(ptr->no==key)
		{
			temp=ptr->next;
			ptr->next=new1;
			new1->next=temp;
			count++;
		}
		else
		{
			printf("\nnode is not insert because key value not found.");
		}
	}
	ptr=lp;
	while(ptr->next!=lp)
	{
		ptr=ptr->next;
	}
	ptr->next=lp;

}

void insert_fix(node *ptr)
{
	int p=1,key;
	node *new1,*temp;
	new1=(node *)malloc(sizeof(node));
	new1->next=NULL;
	printf("enter the position when you want create node : ");
	scanf("%d",&key);
	printf("enter the value of no :- ");
	scanf("%d",&new1->no);
	fflush(stdin);

	if(ptr==NULL)
	{
		if(key==1)
		{
			lp=new1;
			new1->next=lp;
			count++;
		}
		else
		{
			printf("node is not inserted in the link");
		}
	}
	else
	{
		while(p!=key && ptr->next!=lp)
		{
			temp=ptr;
			ptr=ptr->next;
			p++;
		}

		if(p==key && ptr==lp)
		{
			new1->next=ptr;
			lp=new1;
			count++;
		}
		else if(p==key)
		{
			temp->next=new1;
			new1->next=ptr;
			count++;
		}
		else if(p+1==key)
		{
			temp=ptr->next;
			ptr->next=new1;
			new1->next=temp;
			count++;
		}
		else
		{
			printf("node is not inserted in the link");
		}
		
	    ptr=lp;
	    while(ptr->next!=lp)
	      {
		     ptr=ptr->next;
	      }
	    ptr->next=lp;
	}
	
}

void delete_first(node *ptr)
{
	node *temp;
	if(lp==NULL)
	{
		printf("\nlist is empty....\n");
	}
	else if(lp->next==lp)
	{
		lp=NULL;
		free(ptr);
		count--;
	}
	else
	{
		temp=ptr;
		lp=ptr->next;
		count--;
		
		while(ptr->next!=temp)
	    {
		    ptr=ptr->next;
	    }
	   ptr->next=lp;
	   free(temp);
	}
}

void delete_last(node *ptr)
{
	node *temp;
	if(lp==NULL)
	{
		printf("\nlist is empty....\n");
	}
	else if(lp->next==lp)
	{
		lp=NULL;
		free(ptr);
		count--;
	}
	else
	{
		while(ptr->next!=lp)
		{
			temp=ptr;
			ptr=ptr->next;
		}

		temp->next=lp;
		free(ptr);
		count--;
	}
}

void delete_before(node *ptr)
{
	int key,i=1;
	node *temp,*empty;
	
	temp=empty=NULL;

	if(lp==NULL)
	{
		printf("\nlist is empty....\n");
	}
	else
	{
		printf("enter key value : ");
		scanf("%d",&key);

		if(lp->no==key)
		{
			printf("this is first node...");
		}
		else
		{
			while(ptr->no!=key && ptr->next!=lp)
			{
				i++;
				if(i>2)
				{
					empty=temp;
				}
				temp=ptr;
				ptr=ptr->next;
			}

			if(temp==lp)
			{
				lp=lp->next;
				lp->next=lp;
				free(temp);
				count--;
			}
			else if(ptr->no==key)
			{
				empty->next=ptr;
				free(temp);
				count--;
			}
			else
			{
				printf("key not found....");
			}
		}
	}
}
void delete_after(node *ptr)
{
	int key;
	node *temp;

	if(lp==NULL)
	{
		printf("\nlist is empty....\n");
	}
	else
	{
		printf("enter key value : ");
		scanf("%d",&key);
		
		while(ptr->no!=key && ptr->next!=lp)
		{
			ptr=ptr->next;
		}
		
		if(ptr->no!=key)
		{
			printf("key not found...");
		}
		else if(ptr->next==lp && ptr->no==key)
		  {
			  printf("this is a last node....");
		  }
        else if(ptr->next->next==lp)
		{
			temp=ptr->next;
			ptr->next=lp;
			free(temp);
			count--;
		}
		else
		{
			temp=ptr->next;
			ptr->next=temp->next;
			free(temp);
			count--;
		}
	}
}
void delete_fix(node *ptr)
{
	int key,p=1;
	node *temp;

	if(lp==NULL)
	{
		printf("\nlist is empty....\n");
	}
	else
	{
		printf("enter possition of node : ");
		scanf("%d",&key);

		if(key==1 && lp->next==lp)
		{
			lp=NULL;
			free(ptr);
			count--;
		}
		else
		{
			while(p!=key && ptr->next!=lp)
			{
				p++;
				temp=ptr;
				ptr=ptr->next;
			}
			
			if(ptr->next==lp && p!=key)
			{
				printf("\nkey value is not found...");
			}
            else
            {	
		      if(key==1)
		      {
		  	     lp=lp->next;
			     free(ptr);
			     count--;
		      }
			  else
			  {
				 temp->next=ptr->next;
				 free(ptr);
				 count--;
			  }
			  
			  ptr=lp;
	          while(ptr->next!=lp)
	            {
		            ptr=ptr->next;
	            }
	          ptr->next=lp;	  
			}
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
		while(ptr->no!=key && ptr->next!=lp)
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
		while(p!=key && ptr->next!=lp)
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
	node *temp;
	if(lp==NULL)
	{
		printf("\nlist is empty....\n");
	}
	else if(lp->next==lp)
	{
		lp=NULL;
		free(ptr);
		count--;
		printf("\nlink delete successful....\n");
	}
	else
	{
		while(count>1)
		{
			lp=lp->next;	
			free(ptr);
			ptr=lp;
			count--;
     	}
     	lp=NULL;
     	free(ptr);
     	count--;
     	printf("\n%d  %d",lp,ptr);
		printf("\nlink delete successful....\n");
	}
}
