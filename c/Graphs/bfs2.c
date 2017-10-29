#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50


struct node{
int data;
bool visited;
};

struct node *listnode[MAX];
int vc=0;

int que[MAX];
int rear=-1,front=0,qc=0;

int stacn[MAX];
int sptr=0,sc=0;

void pushs(int data){
stacn[sptr]=data;
sptr++;
sc++;
}

void pops(){
sptr--;
sc--;
}

bool ise(){
return sc==0;
}

void pushn(int n){
rear++;
que[rear]=n;
qc++;
}

void popn(){
qc--;
front++;
}

bool iqe(){
return qc==0;
}

void insertnode(int data){
struct node *p=(struct node*)malloc(sizeof(struct node));
p->data=data;
p->visited=false;
listnode[vc]=p;
vc++;
}

void addedge(int **am,int from, int to){
am[from][to]=1;
am[to][from]=1;
}

int gaun(int **am, int temp){
for(int i=0; i<vc;  i++){
	if(am[temp][i]==1 && listnode[i]->visited==false){
		return i;	
		}
	}
return -1;
}

void bfs(int **am, int root){
listnode[root]->visited=true;
printf("%d->",listnode[root]->data);
pushn(root);
while(!iqe()){
	int temp=que[front];
	int a=gaun(am,temp);
	if(a!=-1){
		listnode[a]->visited=true;
		printf("%d->",listnode[a]->data);
		pushn(a);	
		}
	if(a==-1){
		popn();
		}
	}
printf("end\n");
for(int i=0; i<vc; i++){
	listnode[i]->visited=false;
	}
}

void dfs(int **am, int root){
listnode[root]->visited=true;
printf("%d->",listnode[root]->data);
pushs(root);
while(!ise()){
	int temp=stacn[sptr-1];
	int a=gaun(am,temp);
	if(a!=-1){
		listnode[a]->visited=true;
		printf("%d->",listnode[a]->data);
		pushs(a);	
		}

	if(a==-1){
		pops();	
		}
	}


for(int i=0; i<vc; i++){
	listnode[i]->visited=false;
	}
printf("end\n");
}

void bfs2(int **am,int root,int **aj){
int count1=0;
int count2=0;
listnode[root]->visited=true;
printf("%d->",listnode[root]->data);
aj[count1][count2]=root;
count2++;
while(!iqe()){
	int temp=aj[count1][count2];
	int a=gaun(temp);
	if(a!=-1){
	listnode[a]->visited=true;
	printf("%d->",listnode[a]->data);
	aj[count1][count2]=a;
		}

	if(a==-1){
		popq();
			
		}	
	}
}

void disp(int a**){
printf("\n");
for(int i=0; i<vc; i++){
	for(int j=0; j<vc; j++){
		printf("%d ",a[i][j]);
		}
	printf("\n");
	}
printf("\n");
}

int main(){
int n;
printf("\nEnter number of nodes:\n");
scanf("%d",&n);
printf("\nNumber of nodes are %d\n",n);

//defining our nodes
for(int i=0; i<n; i++){
	insertnode(i+1);
	printf("%d ",listnode[i]->data);
	}

//defining our edges
int m;
printf("\nEnter number of edges:\n");
scanf("%d",&m);

//Adjacent matrix
int **am;
am=(int **)malloc(n*sizeof(int*));
for(int i=0; i<n; i++){
	am[i]=(int*)calloc(n,sizeof(int));
	}

//Adjacency matrix
int **aj;
aj=(int **)malloc(n*sizeof(int*));
for(int i=0; i<n; i++){
	am[i]=(int*)malloc(n*sizeof(int));
	for(int j=0; j<n; j++){
		am[i][j]=-1;		
		}
	}

//Function to print our adjacency matrix
//disp(aj);

printf("\nEnter the edges:\n");
for(int i=0; i<m; i++){
	int from,to;
	scanf("%d %d",&from,&to);
	addedge(am,from,to);
	printf("\n%d-%d\n",from,to);
	}
//Our graph is ready

printf("\nEnter the root node\n");
int root;
scanf("%d",&root);
printf("\nRoot node is %d \n",root+1);
printf("\nFor BFS\n");
bfs(am,root);
printf("\nFor DFS\n");
dfs(am,root);

return 0;
}
