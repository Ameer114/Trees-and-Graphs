#include<stdio.h>
#define MAX 10
int adj[MAX][MAX];
int queue[MAX];
int visited[MAX];
int ft=0, r=-1;

void enque(int i){
	queue[++r]=i;
}

int deque(){
	return queue[ft++];
}

void bfs(int start, int n){
	for(int i=0;i<n;i++)
	visited[i]=0;
	
	enque(start);
	visited[start]=1;
	printf("\n nodes reachable from %d .\n",start);
	while(ft<=r){
		int a=deque();
		printf("\n %d",a);
		for(int i=0;i<n;i++)
		{
			if(adj[a][i]&&!visited[i])
			{
				enque(i);
				visited[i]=1;
			}
			
		}
	}
	
}


void main(){
	int n,e,start;
	printf("enter the number of edges: ");
	scanf("%d",&e);
	printf("\nenter the number of vertices: ");
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			adj[i][j]=0;
		}
	}
	printf("\nenter the adjacency matrix like u v , meaning u->v: ");
	for(int i=0;i<e;i++){
		int u,v;
		scanf("%d %d", &u, &v);
		if(u>=0 && v>=0 && v<=n && u<=n){
			adj[u][v]=1;			
		}
	}
	printf("Enter the starting vertex: ");
	scanf("%d", &start);
	bfs(start, n);
	
}
