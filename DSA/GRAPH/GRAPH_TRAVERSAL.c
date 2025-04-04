#include <stdio.h>
#define MAX 100
int visited[MAX];

int Total_Vertices;
int arr[MAX][MAX];
void insert_edge(int,int);
void insert_vertex(int);
void remove_edge(int,int);
void remove_vertex(int);
void display();
void dfs(int);
void bfs(int);
int main()
{
	int start,end,choice,no,i,count,start_vertex;
anil:
	printf("\n1.Insert_vertex.");
	printf("\n2.Insert_edge.");
	printf("\n3.Remove_vertex.");
	printf("\n4.Remove_edge.");
	printf("\n5.Display.");
	printf("\n6.Depth First Search (DFS).");
	printf("\n7.Breadth First Search (BFS).");
	printf("\n8.Exit.");
	printf("\n\nEnter your choise : ");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:
			printf("\nEnter the No of Vertex you want to insert(%d avilable) : ",MAX-Total_Vertices);
			scanf("%d",&no);
			insert_vertex(no);
			goto anil;

		case 2:
			printf("\nEnter starting vertex : ");
			scanf("%d",&start);
			printf("\nEnter Ending vertex : ");
			scanf("%d",&end);
			insert_edge(start,end);
			goto anil;

		case 3:
			printf("\nEnter the No of Vertex you want to delete(0 to %d avilable) : ",Total_Vertices-1);
			scanf("%d",&no);
			remove_vertex(no);
			goto anil;

		case 4:
			printf("\nEnter starting vertex : ");
			scanf("%d",&start);
			printf("\nEnter Ending vertex : ");
			scanf("%d",&end);
			remove_edge(start,end);
			goto anil;

		case 5:
			printf("\nDisplay Adjency Matrix......\n\n");
			display();
			goto anil;

		case 6:

			printf("\nEnter the starting vertex for DFS:");
			scanf("%d",&start_vertex);
			for (i = 0; i < Total_Vertices; i++)
			{
				visited[i] = 0;
			}
			dfs(start_vertex);
			printf("\n");
			goto anil;

		case 7:
			printf("Enter the starting vertex for BFS: ");
			scanf("%d",&start_vertex);
			for (i = 0; i < Total_Vertices; i++)
			{
				visited[i] = 0;
	    	}
			bfs(start_vertex);
			printf("\n");
			goto anil;

		case 8:
			printf("\nExit.....\n");
			goto baraiya;

		default:
			printf("\nInvalide choice.......\n");
			goto anil;
	}
baraiya:
	return 0;
}
// Add vertices to the graph
void insert_vertex(int no)
{
	int i;
	if(Total_Vertices + no <= MAX)
	{
		for(i=0; i<no; i++)
		{
			Total_Vertices++;
		}
		printf("\n%d vertices added successfully total vertices : %d ....\n",no,Total_Vertices);
	}
	else
	{
		printf("\nGraph contains olny %d vertex.....\n",MAX);
	}
}
// Add an edge to the graph
void insert_edge(int start,int end)
{
	if(start < Total_Vertices && end < Total_Vertices && start >= 0 && end >= 0)
	{
		arr[start][end] = 1;
		arr[end][start] = 1;
		printf("\nEdge added between %d and %d.....\n",start,end);
	}
	else
	{
		printf("\nInvalide Vertices.....\n");
	}
}
// Remove an edge from the graph
void remove_edge(int start,int end)
{
	if(start < Total_Vertices && end < Total_Vertices && start >= 0 && end >= 0)
	{
		arr[start][end] = 0;
		arr[end][start] = 0;
		printf("\nEdge removed between %d and %d.....\n",start,end);
	}
	else
	{
		printf("\nInvalide Vertices.....\n");
	}
}
// Remove a vertex from the graph
void remove_vertex(int Vno)
{
	int i,j;
	if(Vno < Total_Vertices && Vno >= 0)
	{
		for(i=Vno; i <= Total_Vertices - 2; i++)
		{
			for(j=0; j <= Total_Vertices - 1; j++)
			{
				arr[i][j] = arr[i + 1][j];
			}
		}
		for(i=Vno; i <= Total_Vertices - 2; i++)
		{
			for(j=0; j <= Total_Vertices - 1; j++)
			{
				arr[j][i] = arr[j][i + 1];
			}
		}

		for(i=0; i <= Total_Vertices - 1; i++)
		{
			arr[Total_Vertices - 1][i] = 0;
			arr[i][Total_Vertices - 1] = 0;
		}
		Total_Vertices--;
		printf("\nVertex %d is removed Successfully.....\n",Vno);
	}
	else
	{
		printf("\nInvalid vertex.....\n");
	}
}
// Display the adjacency matrix of the graph
void display()
{
	int i,j;
	if(Total_Vertices == 0)
	{
		printf("\nGraph is Empty......\n");
	}
	else
	{
		if(Total_Vertices >= 11)
    		printf("  ");
    	else
    	    printf("   ");
		for(i = 0; i <= Total_Vertices - 1; i++)
		{
			if(Total_Vertices >= 11)
    		    printf("  %d",i);
         	else
			    printf(" %d ",i);
		}
		for(i = 0; i <= Total_Vertices - 1; i++)
		{
			printf("\n%2d ",i);
			for(j = 0; j <= Total_Vertices - 1; j++)
			{
				if(j>=11)
				    printf("  %d ",arr[i][j]);
				else
				    printf(" %d ",arr[i][j]);
			}
		}
	}
}
// Depth First Search (DFS)
void dfs(int start_vertex)
{
	if(start_vertex > Total_Vertices|| start_vertex < 0)
	{
		printf("\nvertex not found.....\n");
		return ;
	}
	
	int i;
	printf("%d ",start_vertex);
	visited[start_vertex] = 1;
	for (i = 0; i < Total_Vertices; i++)
	{
		if (arr[start_vertex][i] == 1 && !visited[i])
		{
			dfs(i);
		}
	}
}
// Breadth First Search (BFS)
void bfs(int start_vertex)
{
	if(start_vertex > Total_Vertices || start_vertex < 0)
	{
		printf("\nvertex not found.....\n");
		return ;
	}
	
	int queue[MAX], front = 0, rear = 0,i;
	queue[rear++] = start_vertex;
	visited[start_vertex] = 1;
	while (front < rear)
	{
		int currentVertex = queue[front++];
		printf("%d ",currentVertex);
		for (i = 0; i < Total_Vertices; i++)
		{
			if (arr[currentVertex][i] == 1 && !visited[i])
			{
				queue[rear++] = i;
				visited[i] = 1;
			}
		}
	}
}

