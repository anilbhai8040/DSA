#include<stdio.h>
#include<malloc.h>
struct abc
{
	int no;
	struct abc *left;
	struct abc *right;
}*root=NULL;

typedef struct abc node;

void input();
void search(node *,int,node *);
node *insert(node *,int);
node *createnode(int);
node *delete_node(node *,int);
node *minnode(node *);
node *maxnode(node *);
void infix(node *);
void prefix(node *);
void postfix(node *);
int main()
{
	int choise,no;

anil:
	printf("\n1.input.");
	printf("\n2.prefix order.");
	printf("\n3.infix order.");
	printf("\n4.postfix order.");
	printf("\n5.exit.");
	printf("\n6.search and update.");
	printf("\n7.delete node.");
	printf("\n\nenter your choise : ");
	scanf("%d",&choise);
	switch(choise)
	{
		case 1:
			input();
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
		case 6:
			printf("\nEnter Search number : ");
			scanf("%d",&no);
			search(root,no,root);
			goto anil;
		case 7:
			printf("\nEnter Delete number : ");
			scanf("%d",&no);
			root=delete_node(root,no);
			goto anil;
		default:
			printf("\nInvalide choise....\n");
			goto anil;
	}
baraiya:
	return 0;
}
void input()   // only used for input data
{
	int no,i;

	printf("no = ",no);
	scanf("%d",&no);
	root=insert(root,no);   // coll insert function and pass data
}
node *insert(node *ptr,int n)
{
	node *new1;
	if(ptr==NULL)
	{
		new1=(node *)malloc(sizeof(node));
		new1->no=n;
		new1->left=new1->right=NULL;
		return new1;
	}
	if(n>ptr->no)
	{
		ptr->right=insert(ptr->right,n);
	}
	else
	{
		if(n<ptr->no)
		{
			ptr->left=insert(ptr->left,n);
		}
		else
		{
			printf("\n%d is already exist in tree....",n);
			return ptr;
		}
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
void search(node *ptr,int sno,node *temp)
{
	int no;
	char ch;
	if(ptr==NULL)
	{
		if(root == NULL)
		{
			printf("\nTree is Empty.....\n");
		}
		else
		{
			printf("search is unsucess......");
		}
	}
	else if(sno < ptr->no)
	{
		search(ptr->left,sno,ptr);
	}
	else if(sno > ptr->no)
	{
		search(ptr->right,sno,ptr);
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

			if(sno > root->no)     // search no is greater than root node of tree
			{
				printf("No = ");
				scanf("%d",&no);

				if(no <= root->no)  // when new number is less than root node of tree
				{
					printf("\nnumber must be greater than %d (root node)...",root->no);
					goto asd;
				}

				if(ptr->left==NULL && ptr->right==NULL)  // if leaf node
				{
					if(ptr->no < temp->no)   // when left leaf of root node
					{
						if(no < temp->no)
						{
							ptr->no=no;
						}
						else
						{
							printf("\nnumber must be less than %d",temp->no);
							goto asd;
						}
					}
					else    // when right leaf of root node
					{
						if(no > temp->no)
						{
							ptr->no=no;
						}
						else
						{
							printf("\nnumber must be greter than %d",temp->no);
							goto asd;
						}
					}
				}
				else if(ptr->left != NULL && ptr->right != NULL)  // if parent node have two child node
				{
					if(no < ptr->right->no && no > ptr->left->no)
					{
						ptr->no=no;
					}
					else
					{
						printf("\nnumber must be grater than %d",ptr->left->no);
						printf("\nnumber must be less than %d",ptr->right->no);
						goto asd;
					}
				}
				else if(ptr->left != NULL)  // if parent have left child node only
				{
					if(no > ptr->left->no)
					{
						ptr->no=no;
					}
					else
					{
						printf("\nnumber must be greter than %d",ptr->left->no);
						goto asd;
					}
				}
				else if(ptr->right != NULL) // if parent have right child node only
				{
					if(no < ptr->right->no && no > temp->no)
					{
						ptr->no=no;
					}
					else
					{
						printf("\nnumber must be less than %d",ptr->right->no);
						printf("\nnumber must be greter than %d",temp->no);
						goto asd;
					}
				}
			}
			else if(sno < root->no)    // search no is less than root node of tree
			{
				printf("No = ");
				scanf("%d",&no);

				if(no >= root->no)   // when new number is greater than root node of tree
				{
					printf("\nnumber must be less than %d (root node)...",root->no);
					goto asd;
				}

				if(ptr->left==NULL && ptr->right==NULL)  // if leaf node
				{
					if(ptr->no < temp->no) // when left leaf of root node
					{
						if(no < temp->no)
						{
							ptr->no=no;
						}
						else
						{
							printf("\nnumber must be less than %d",temp->no);
							goto asd;
						}
					}
					else  // when right leaf of root node
					{
						if(no > temp->no)
						{
							ptr->no=no;
						}
						else
						{
							printf("\nnumber must be greter than %d",temp->no);
							goto asd;
						}
					}
				}
				else if(ptr->left != NULL && ptr->right != NULL) // if parent node have two child node
				{
					if(no > ptr->left->no && no < ptr->right->no)
					{
						ptr->no=no;
					}
					else
					{
						printf("\nnumber must be grater than %d",ptr->left->no);
						printf("\nnumber must be less than %d",ptr->right->no);
						goto asd;
					}
				}
				else if(ptr->left != NULL)  // if parent have left child node only
				{
					if(no > ptr->left->no && no < temp->no)
					{
						ptr->no=no;
					}
					else
					{
						printf("\nnumber must be grater than %d",ptr->left->no);
						printf("\nnumber must be less than %d",temp->no);
						goto asd;
					}
				}
				else if(ptr->right != NULL) // if parent have right child node only
				{
					if(no < ptr->right->no)
					{
						ptr->no=no;
					}
					else
					{
						printf("\nnumber must be less than %d",ptr->right->no);
						goto asd;
					}
				}
			}
			else if(sno == root->no)  // search no is equal to root node of tree
			{
				printf("No = ");
				scanf("%d",&no);

				if(ptr->left==NULL && ptr->right==NULL)  //when root node of tree not have any child node
				{
					ptr->no=no;
				}
				else if(ptr->left != NULL && ptr->right != NULL) //when root node of tree have two child node
				{
					if(no > ptr->left->no && no < ptr->right->no)
					{
						ptr->no=no;
					}
					else
					{
						printf("\nnumber must be grater than %d",ptr->left->no);
						printf("\nnumber must be less than %d",ptr->right->no);
						goto asd;
					}
				}
				else if(ptr->left != NULL)  //when root node of tree have left child node only
				{
					if(no > ptr->left->no)
					{
						ptr->no=no;
					}
					else
					{
						printf("\nnumber must be grater than %d",ptr->left->no);
						goto asd;
					}
				}
				else if(ptr->right != NULL)  //when root node of tree have right child node only
				{
					if(no < ptr->left->no)
					{
						ptr->no=no;
					}
					else
					{
						printf("\nnumber must be less than %d",ptr->right->no);
						goto asd;
					}
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
		if(root == NULL)
		{
			printf("\nTree is Empty.....\n");
		}
		else
		{
			printf("search is unsucess......");
			return 0;
		}
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
node *minnode(node *ptr)
{
	node *temp;
	temp=ptr;
	// find max no of right tree
	while(temp!=0 && temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp;  //return address of min node
}
node *maxnode(node *ptr)
{
	node *temp;
	temp=ptr;
	// find max no of left tree
	while(temp!=0 && temp->right!=NULL)
	{
		temp=temp->right;
	}
	return temp; // return address of max node
}
