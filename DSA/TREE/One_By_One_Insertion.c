#include<stdio.h>
#include<malloc.h>
struct abc
{
	int no;
	struct abc *left;
	struct abc *right;
}*root=NULL;
typedef struct abc node;
node *insert(node *,int);
node *createnode(int);
void infix(node *);
void prefix(node *);
void postfix(node *);
int main()
{
	int choise,no;
anil:
	printf("\n1.insert.");
	printf("\n2.prefix order.");
	printf("\n3.infix order.");
	printf("\n4.postfix order.");
	printf("\n5.exit.");
	printf("\n\nenter your choise : ");
	scanf("%d",&choise);
	switch(choise)
	{
		case 1:
			printf("no = ");
			scanf("%d",&no);
			root=insert(root,no);
			goto anil;
		case 2:
			printf("\nprefix order : ");
			prefix(root);
			goto anil;
		case 3:
			printf("\ninfix order : ");
			infix(root);
			goto anil;
		case 4:
			printf("\npostfix order : ");
			postfix(root);
			goto anil;
		case 5:
			goto baraiya;
		default:
			printf("\nInvalide choise....\n");
			goto anil;
	}
baraiya:
	return 0;
}
void create()
{
	int a[5],i;
	for(i=0; i<5; i++)
	{
	}
	for(i=0; i<5; i++)
	{
	}
}
node *insert(node *ptr,int no)
{
	node *new1;
	if(ptr==NULL)
	{
		new1=(node *)malloc(sizeof(node));
		new1->no=no;
		new1->left=new1->right=NULL;
		return new1;
	}
	if(no > ptr->no)
	{
		ptr->right=insert(ptr->right,no);
	}
	else if(no < ptr->no)
	{
		ptr->left=insert(ptr->left,no);
	}
	else
	{
		printf("\nAlready exist in the tree....\n");
		return ptr;
	}
}
void infix(node *ptr)
{
	if(ptr==0)
	{
		return ;
	}
	infix(ptr->left);
	printf("%d ",ptr->no);
	infix(ptr->right);
}
void postfix(node *ptr)
{
	if(ptr==0)
	{
		return ;
	}
	postfix(ptr->left);
	postfix(ptr->right);
	printf("%d ",ptr->no);
}
void prefix(node *ptr)
{
	if(ptr==0)
	{
		return ;
	}
	printf("%d ",ptr->no);
	prefix(ptr->left);
	prefix(ptr->right);
}
