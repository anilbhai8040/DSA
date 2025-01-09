#include<stdio.h>
#include<malloc.h>
struct abc 
{
	int no;
	struct abc *left;
	struct abc *right;
}*root=NULL;
typedef struct abc node;

//struct abc *create();
node * create();
void infix(node *);
void prefix(node *);
void postfix(node *);
int main()
{
	int choise;
	anil:
	printf("\n1.create.");
	printf("\n2.prefix order.");
	printf("\n3.infix order.");
	printf("\n4.postfix order.");
	printf("\n5.exit.");
	printf("\n\nenter your choise : ");
	scanf("%d",&choise);
	switch(choise)
	{
		case 1:
			root=create();
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
//struct abc * create()
node * create()
{
	int x;
	node *new1;
	printf("\nvalue of node (-1 for no node) : ");
	scanf("%d",&x);
	if(x==-1)
	{
		return 0;
	}
	new1=(node *)malloc(sizeof(node));
	new1->no=x;
	printf("\nenter left child of %d ",x);
	new1->left=create();
	printf("\nenter right child of %d ",x);
	new1->right=create();
	return new1;
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
