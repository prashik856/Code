#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 999999
void addedge(int **am, int from, int to){
am[from][to]=1;
am[to][from]=1;
}

void display(int **am,int n){
printf("\n");
for(int i=0; i<n; i++){
	for(int j=0; j<n; j++){
		printf("%d ",am[i][j]);
		}
	printf("\n");
	}
}

int minindex(int *dist,bool *visited, int n){
int min=MAX,min_index;
for(int i=0; i<n ;i++){
	if(visited[i]==false && dist[i]<=min){
		min=dist[i];
		min_index=i;	
		}
	}
//printf("\n%d\n",min_index);
return min_index;
}

void mindist(int **am, int n, int src, int dest){
bool *visited;
visited=(bool *)malloc(n*sizeof(bool));
int *dist;
dist=(int *)malloc(n*sizeof(int));
for(int i=0; i<n; i++){
	visited[i]=false;
	dist[i]=MAX;
	}
dist[src]=0;
for(int i=0; i<(n-1); i++){
	int u=minindex(dist,visited,n);
	//printf("\nI am here\n");
	visited[u]=true;
	for(int j=0; j<n; j++){
		if(visited[j]==false && am[u][j]!=0 && dist[u]!=MAX && dist[u]+am[u][j]<dist[j]){
			dist[j]=dist[u]+am[u][j];
			}
		}
	}


for(int i=0; i<n; i++){
	if(i==dest){
		printf("\n%d \n",dist[i]);
		}
	}
}

int main(){
int n;
scanf("%d",&n);

int **am;
am=(int **)malloc(n*sizeof(int*));
for(int i=0; i<n; i++){
	am[i]=(int *)calloc(n,sizeof(int));
	}

int m;
scanf("%d",&m);
for(int i=0; i<m; i++){
	int from, to;
	scanf("%d %d",&from, &to);
	addedge(am,from,to);
	}

int src,dest;
scanf("%d %d",&src,&dest);

display(am,n);

mindist(am,n,src,dest);
return 0;
}
