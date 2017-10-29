#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 50
struct node{
	int data;
	bool visited;
};

struct node *listnode[MAX];
int vc=0;

void insertn(int data){
	struct node *p=(struct node *)malloc(sizeof(struct node));
	p->data=data;
	p->visited=false;
	listnode[vc]=p;
	vc++;
}

void addedge(int **am,int from, int to){
am[from][to]=1;
am[to][from]=1;
}

void display(int **am){
printf("\n");
for(int i=0; i<vc; i++){
	for(int j=0; j<vc; j++){
		printf("%d ",am[i][j]);
		}
	printf("\n");
	}
printf("\n");
}

void printall(int u, int d, int **am, int *path, int *pi){
listnode[u]->visited=true;
path[*pi]=u;
*pi=*pi+1;
if(u==d){
	for(int i=0; i<vc;i++){
		if(path[i]!=d){
			printf("%d->",path[i]);
			}		
		if(path[i]==d){
			printf("%d->",path[i]);
			printf("end\n");
			break;
			}
		}
	printf("\n");
	}
else{
	//int a;
	//int temp=path[*pi-1];
	for(int i=0; i<vc; i++){
		if(am[u][i]==1 && listnode[i]->visited==false){
			printall(i,d,am,path,pi);
			}
		}
	}
*pi=*pi-1;
listnode[u]->visited=false;
}

int main(){
int n;
scanf("%d",&n);
for(int i=0; i<n; i++){
	insertn(i+1);
	}

int **am;
am=(int **)malloc(n*sizeof(int *));
for(int i=0; i<n; i++){
	am[i]=(int*)calloc(n,sizeof(int));
	}

int m;
scanf("%d",&m);
for(int i=0; i<m; i++){
	int a,b;
	scanf("%d %d",&a,&b);
	addedge(am,a,b);
	}
//Graph defination done

int s,d;
scanf("%d %d",&s,&d);

int *path;
path=(int *)malloc(n*sizeof(int));
int path_index=0;
int *pi=&path_index;
for(int i=0; i<n; i++){
path[i]=-1;
}

printall(s,d,am,path,pi);


display(am);


return 0;
}

