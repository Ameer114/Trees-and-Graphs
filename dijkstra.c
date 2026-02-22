#include <stdio.h>
#define MAX 10
#define INF 999

int cost[MAX][MAX], visited[MAX], src, dist[MAX], n;

int min(){
	int min=999,ind=-1;
	for(int i=0;i<n;i++){
		if(!visited[i] && dist[i]<min){
			min=dist[i];
			ind=i;
		}
	}
	return ind;
}

void dij(){
	for (int i=0;i<n;i++){
		visited[i]=0;
		dist[i]=cost[src][i];
	}
	
	for(int i=0;i<n-1;i++){
		int u=min();
		visited[u]=1;
		for(int v=0;v<n;v++){
			if(!visited[v] && cost[u][v]!=0 && dist[v]>dist[u]+cost[u][v]){
				dist[v]=dist[u]+cost[u][v];
			}
		}
		
	}
	printf("Shortest Path: \n");
	for(int i=0;i<n;i++){
		printf("%c -- %d \n",65+i, dist[i]);
	}
	
}

 
int main(){
	
	printf("enter number of vertices: ");
	scanf("%d",&n);
	printf("\n Enter the adjacency Matrix: \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&cost[i][j]);
			if(i!=j && cost[i][j]==0){
				cost[i][j]=INF;
			}
		}
	}  
	printf("\nEnter the source: ");
	scanf("%d",&src);
	dij();
	return 0;
}
