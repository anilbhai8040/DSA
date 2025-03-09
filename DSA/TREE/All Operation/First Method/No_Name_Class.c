#include<stdio.h>
#include<string.h>
#include<malloc.h>
struct abc
{
	int no;
	char name[50];
	char class_name;
	struct abc *left;
	struct abc *right;
}*root=NULL;

typedef struct abc node;

void search(node *,int,node *);
node *insert(node *,int,char [],char);
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
	char name1[50],class_name1;

anil:
	printf("\n1.insert.");
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
			fflush(stdin);
			printf("Name = ");
			gets(name1);
			printf("Class (A/B) : ");
			class_name1=getchar();
			root=insert(root,no,name1,class_name1);   // call insert function and pass data
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
			printf("\nEnter Search number : ");
			scanf("%d",&no);
			search(root,no,root);
			goto anil;
		case 6:
			printf("\nEnter Delete number : ");
			scanf("%d",&no);
			root=delete_node(root,no);
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

node *insert(node *ptr,int no,char name1[],char class_name1)
{
	node *new1;
	if(ptr==NULL)
	{
		new1=(node *)malloc(sizeof(node));
		new1->no=no;
		strcpy(new1->name,name1);
		new1->class_name=class_name1;
		new1->left=new1->right=NULL;
		return new1;
	}
	if(no>ptr->no)
	{
		ptr->right=insert(ptr->right,no,name1,class_name1);
	}
	else
	{
		if(no<ptr->no)
		{
			ptr->left=insert(ptr->left,no,name1,class_name1);
		}
		else
		{
			printf("\n%d is already exist in tree....",no);
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
	printf("\n\nNo : %d\n",ptr->no);
	printf("Name : ");
	puts(ptr->name);
	printf("Class : %c\n",ptr->class_name);
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
	printf("\n\nNo : %d\n",ptr->no);
	printf("Name : ");
	puts(ptr->name);
	printf("Class : %c\n",ptr->class_name);
}
void prefix(node *ptr)
{
	if(ptr==0)
	{
		return ;
	}
	printf("\n\nNo : %d\n",ptr->no);
	printf("Name : ");
	puts(ptr->name);
	printf("Class : %c\n",ptr->class_name);
	prefix(ptr->left);
	prefix(ptr->right);
}
void search(node *ptr,int sno,node *temp)
{
	int no;
	char name[50],class_name;
	char ch;
	node *temp1,*temp2;
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
			printf("Name : ");
			puts(ptr->name);
			printf("Class : %c\n",ptr->class_name);

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
							fflush(stdin);
							printf("Name = ");
							gets(ptr->name);
							printf("Class (A/B) : ");
							ptr->class_name=getchar();
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
							fflush(stdin);
							printf("Name = ");
							gets(ptr->name);
							printf("Class (A/B) : ");
							ptr->class_name=getchar();
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
						if(no < ptr->right->no && no > ptr->left->no) 
						{
							ptr->no=no;
							fflush(stdin);
							printf("Name = ");
							gets(ptr->name);
							printf("Class (A/B) : ");
							ptr->class_name=getchar();
						}
						else
						{
							printf("\nnumber must be grater than %d",ptr->left->no);
							printf("\nnumber must be less than %d",ptr->right->no);
							goto asd;
						}
				    }
				}
				else if(ptr->left != NULL)  // if parent have left child node only
				{
					temp2=maxnode(ptr->left);
					if(no<=temp2->no)
					{
						printf("\nnumber must be grater than %d",temp2->no);
						goto asd;
					}
					else
					{
						if(no > ptr->left->no)
						{
							ptr->no=no;
							fflush(stdin);
							printf("Name = ");
							gets(ptr->name);
							printf("Class (A/B) : ");
							ptr->class_name=getchar();
						}
						else
						{
							printf("\nnumber must be greter than %d",ptr->left->no);
							goto asd;
						}
					}
				}
				else if(ptr->right != NULL) // if parent have right child node only
				{
					temp1=minnode(ptr->right);
					if(no>=temp1->no)
					{
						printf("\nnumber must be less than %d",temp1->no);
						goto asd;
					}
					else
					{
						if(no < ptr->right->no && no > temp->no)
						{
							ptr->no=no;
							fflush(stdin);
							printf("Name = ");
							gets(ptr->name);
							printf("Class (A/B) : ");
							ptr->class_name=getchar();
						}
						else
						{
							printf("\nnumber must be less than %d",ptr->right->no);
							printf("\nnumber must be greter than %d",temp->no);
							goto asd;
						}
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
							fflush(stdin);
							printf("Name = ");
							gets(ptr->name);
							printf("Class (A/B) : ");
							ptr->class_name=getchar();
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
							fflush(stdin);
							printf("Name = ");
							gets(ptr->name);
							printf("Class (A/B) : ");
							ptr->class_name=getchar();
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
						if(no > ptr->left->no && no < ptr->right->no)
						{
							ptr->no=no;
							fflush(stdin);
							printf("Name = ");
							gets(ptr->name);
							printf("Class (A/B) : ");
							ptr->class_name=getchar();
						}
						else
						{
							printf("\nnumber must be grater than %d",ptr->left->no);
							printf("\nnumber must be less than %d",ptr->right->no);
							goto asd;
						}
				    }
				}
				else if(ptr->left != NULL)  // if parent have left child node only
				{
					temp2=maxnode(ptr->left);
					if(no<=temp2->no)
					{
						printf("\nnumber must be grater than %d",temp2->no);
						goto asd;
					}
					else
					{
						if(no > ptr->left->no && no < temp->no)
						{
							ptr->no=no;
							fflush(stdin);
							printf("Name = ");
							gets(ptr->name);
							printf("Class (A/B) : ");
							ptr->class_name=getchar();
						}
						else
						{
							printf("\nnumber must be grater than %d",ptr->left->no);
							printf("\nnumber must be less than %d",temp->no);
							goto asd;
						}
					}
				}
				else if(ptr->right != NULL) // if parent have right child node only
				{
					temp1=minnode(ptr->right);
					if(no>=temp1->no)
					{
						printf("\nnumber must be less than %d",temp1->no);
						goto asd;
					}
					else
					{
						if(no < ptr->right->no)
						{
							ptr->no=no;
							fflush(stdin);
							printf("Name = ");
							gets(ptr->name);
							printf("Class (A/B) : ");
							ptr->class_name=getchar();
						}
						else
						{
							printf("\nnumber must be less than %d",ptr->right->no);
							goto asd;
						}
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
					fflush(stdin);
					printf("Name = ");
					gets(ptr->name);
					printf("Class (A/B) : ");
					ptr->class_name=getchar();
				}
				else if(ptr->left != NULL && ptr->right != NULL) //when root node of tree have two child node
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
						if(no > ptr->left->no && no < ptr->right->no)
						{
							ptr->no=no;
							fflush(stdin);
							printf("Name = ");
							gets(ptr->name);
							printf("Class (A/B) : ");
							ptr->class_name=getchar();
						}
						else
						{
							printf("\nnumber must be grater than %d",ptr->left->no);
							printf("\nnumber must be less than %d",ptr->right->no);
							goto asd;
						}
				    }
				}
				else if(ptr->left != NULL)  //when root node of tree have left child node only
				{
					temp2=maxnode(ptr->left);
					if(no<=temp2->no)
					{
						printf("\nnumber must be grater than %d",temp2->no);
						goto asd;
					}
					else
					{
						if(no > ptr->left->no)
						{
							ptr->no=no;
							fflush(stdin);
							printf("Name = ");
							gets(ptr->name);
							printf("Class (A/B) : ");
							ptr->class_name=getchar();
						}
						else
						{
							printf("\nnumber must be grater than %d",ptr->left->no);
							goto asd;
						}
					}
				}
				else if(ptr->right != NULL)  //when root node of tree have right child node only
				{
					temp1=minnode(ptr->right);
					if(no>=temp1->no)
					{
						printf("\nnumber must be less than %d",temp1->no);
						goto asd;
					}
					else
					{
						if(no < ptr->left->no)
						{
							ptr->no=no;
							fflush(stdin);
							printf("Name = ");
							gets(ptr->name);
							printf("Class (A/B) : ");
							ptr->class_name=getchar();
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
}
node *delete_node(node *ptr,int no1)
{
	node *temp;
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
			printf("\nwhich tree is insert (Left/Right) : ");
			ch=getchar();
			if(ch=='r' || ch=='R')          // insert right side tree smallest node
			{
				temp=minnode(ptr->right);

				// copy data from right side tree smallest node to search node
				ptr->no=temp->no;
				strcpy(ptr->name,temp->name);
				ptr->class_name=temp->class_name;

				ptr->right=delete_node(ptr->right,ptr->no);  // delete right side tree smallest node
			}
			else                            // insert left side tree biggest node
			{
				temp=maxnode(ptr->left);

				// copy data from lest side tree biggest node to search node
				ptr->no=temp->no;
				strcpy(ptr->name,temp->name);
				ptr->class_name=temp->class_name;

				ptr->left=delete_node(ptr->left,ptr->no);    // delete lest side tree biggest node
			}
		}
		else if(ptr->left != NULL)    // if only left child
		{
			temp=ptr->left;
			free(ptr);
			return temp;
		}
		else if(ptr->right != NULL)  // if only right child
		{
			temp=ptr->right;
			free(ptr);
			return temp;
		}
	}
}
node *minnode(node *ptr)
{
	node *temp;
	temp=ptr;
	// find max no of right tree
	while(temp->left!=NULL)
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
	while(temp->right!=NULL)
	{
		temp=temp->right;
	}
	return temp; // return address of max node
}
