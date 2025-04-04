#include<stdio.h>
#include<malloc.h>
struct abc
{
	int no;
	struct abc *left;
	struct abc *right;
}*root=NULL;

typedef struct abc node;
int min=0,max=0;
void input();
void search(node *,int,int,int);
node *insert(node *,int);
node *delete_node(node *,int);
node *minnode(node *);
node *maxnode(node *);
void infix(node *);
void prefix(node *);
void postfix(node *);
void minmax(node *,node *);
int main()
{
	int choise,no;
anil:
	printf("\n1.input.");
	printf("\n2.prefix order.");
	printf("\n3.infix order.");
	printf("\n4.postfix order.");
	printf("\n5.search and update.");
	printf("\n6.delete node.");
	printf("\n7.exit.");
	printf("\n\nenter your choise : ");
	scanf("%d",&choise);
	switch(choise)
	{
		case 1:
			printf("no = ",no);
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
			if(root==NULL)
			{
			    printf("\ntree is empty.....");
			}
			else
			{
			    printf("\nEnter Search number : ");
			    scanf("%d",&no);
	            minmax(root,root);
		   	    search(root,no,min,max);
			}
			goto anil;
		case 6:
			if(root==NULL)
			{
			    printf("\ntree is empty.....");
			}
			else
			{
				printf("\nEnter Delete number : ");
				scanf("%d",&no);
				root=delete_node(root,no);
			}
			goto anil;
		case 7:
			goto baraiya;
		default:
			printf("\nInvalide choise....\n");
			goto anil;
	}
baraiya:
	return 0;
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
	else if(no>ptr->no)
	{
		ptr->right=insert(ptr->right,no);
	}
	else if(no<ptr->no)
	{
		ptr->left=insert(ptr->left,no);
	}
	else
	{
		printf("\n%d is already exist in tree....",no);
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
	printf("\nNo : %d\n",ptr->no);
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
	printf("\nNo : %d",ptr->no);
}
void prefix(node *ptr)
{
	if(ptr==0)
	{
		return ;
	}
	printf("\nNo : %d\n",ptr->no);
	prefix(ptr->left);
	prefix(ptr->right);
}
void search(node *ptr,int sno,int min,int max)
{
	int no;
	char ch;
	node *temp1,*temp2;
	if(ptr==NULL)
	{
		printf("search is unsucess......");
	}
	else if(sno < ptr->no)
	{
		max=ptr->no;
		search(ptr->left,sno,min,max);
	}
	else if(sno > ptr->no)
	{
		min=ptr->no;
		search(ptr->right,sno,min,max);
	}
	else if(sno == ptr->no)
	{
		printf("\nSearch is Success.....\n");
asd:
		fflush(stdin);
		printf("\nYou want Change Data (Y/N) : ");
		ch=getchar();
		if(ch=='Y' || ch=='y')
		{
			printf("\nOld Data....\n\n");

			printf("No : %d\n",ptr->no);

			printf("\n\nEnter New Data...\n\n");
			printf("No = ");
			scanf("%d",&no);
			
			if(ptr->left != NULL && ptr->right != NULL) //when node have two child node
			{
				temp1=minnode(ptr->right);
				temp2=maxnode(ptr->left);

				if(no>=temp1->no || no<=temp2->no)
				{
					printf("\nnumber must be grater than %d",temp2->no);
					printf("\nnumber must be less than %d",temp1->no);
					goto asd;
				}
				else
				{
					ptr->no=no;
				}
			}
			else if(ptr->left==NULL && ptr->right==NULL) //when node is leaf
			{
				if(root->no==sno)    // root node of tree
				{
				   ptr->no=no;
				}
				else if(min==sno)   // smallest node of tree
				{
					if(no<max)
						ptr->no=no;
					else
					    printf("\nnumber must be less than %d",max);   
					    goto asd;
				}
				else if(max==sno)   // largest node  of tree
				{
					if(no>min)
					    ptr->no=no;
					else
					    printf("\nnumber must be greter than %d",min);
					    goto asd;
			    }
				else if(no<max && no>min)  //other leaf node
				{
					ptr->no=no;
				}
				else
				{
					printf("\nnumber must be greter than : %d...",min);
					printf("\nnumber must be less than   : %d...",max);
					goto asd;
				}
			}
			else if(ptr->left != NULL)   // node have only left node
			{
				// max is nearest bigest node
				temp2=maxnode(ptr->left);
				if(ptr->no==max) // root node
				{
					if(no > temp2->no)
					    ptr->no=no;
					else
					    printf("\nnumber must be greter than %d",temp2->no);
						goto asd;
				}
				else if(no > temp2->no && no<max)   // new value is greter than temp2 but less than max value
				{
					ptr->no=no;
				}
				else
				{
					printf("\nnumber must e greter than %d",temp2);
					printf("\nnumber must be less than %d",max);
					goto asd;
				}
			}
			else if(ptr->right != NULL)  //node have only right child
			{
				// min is nearest smallest element
				temp1=minnode(ptr->right);
				if(ptr->no==min)  //root node
				{
					if(no < temp1->no)
					    ptr->no=no;
					else
					    printf("\nnumber must be less than %d",temp1->no);
					    goto asd;
				}
				else if(no < temp1->no && no > min) // new value is less than temp1 but greter than min value
				{
					ptr->no=no;
				}
				else
				{
				    printf("\nnumber must be less than %d",temp1->no);
				    printf("\nnumber must be greter than %d",max);
				    goto asd;
				}
			}
		}
	}
}
node *delete_node(node *ptr,int no1)
{
	node *temp1,*temp2;
	char ch;
	if(ptr==NULL)
	{
		printf("search is unsucess......");
		return 0;
	}
	else if(no1 < ptr->no)       // search no is less than ptr->no
	{
		ptr->left=delete_node(ptr->left,no1);
	}
	else if(no1 > ptr->no)       // search no is greter than ptr->no
	{
		ptr->right=delete_node(ptr->right,no1);
	}
	else if(no1 == ptr->no)      // search no is equal ptr->no
	{
		printf("\nSearch is Success.....\n");
		if(ptr->left==NULL && ptr->right==NULL)    // if leaf node
		{
			free(ptr);
			return 0;
		}
		else if(ptr->left != NULL && ptr->right != NULL)   // if two child
		{
			fflush(stdin);
			printf("\nwhich tree is insert (L/R) : ");
			ch=getchar();
			if(ch=='r' || ch=='R')          // insert right side tree smallest node
			{
				temp1=ptr;
				temp2=ptr->right;
				ptr=ptr->right;
				while(ptr->left!=NULL)
				{
					ptr=ptr->left;
				}
				ptr->left=temp1->left;
				free(temp1);
				return temp2;				
			}
			else                            // insert left side tree biggest node
			{
				temp1=ptr;
				temp2=ptr->left;
				ptr=ptr->left;
				while(ptr->right!=NULL)
				{
					ptr=ptr->right;
				}
				ptr->right=temp1->right;
				free(temp1);
				return temp2;
			}
		}
		else if(ptr->left != NULL)    // if only left child
		{
			temp1=ptr->left;
			free(ptr);
			return temp1;
		}
		else if(ptr->right != NULL)  // if only right child
		{
			temp1=ptr->right;
			free(ptr);
			return temp1;
		}
	}
}
// find minimum node
node *minnode(node *ptr)
{
	while(ptr->left!=NULL)
	{
		ptr=ptr->left;
	}
	return ptr;
}
// find maximum node
node *maxnode(node *ptr)
{
	while(ptr->right!=NULL)
	{
		ptr=ptr->right;
	}
	return ptr; 
}

// find tree largest node and smallest node
void minmax(node *ptr1,node *ptr2)
{
	while(ptr1->left!=NULL)
	{
		ptr1=ptr1->left;
	}
	min=ptr1->no;
	
	while(ptr2->right!=NULL)
	{
		ptr2=ptr2->right;
	}
	max=ptr2->no;
}
