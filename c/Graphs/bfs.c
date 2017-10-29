#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

//Define all global variables
struct node{
int data;
bool visited;
};

struct node **listnode;
int vc=0;

int *que;
int qptr=0, rear=-1,front=0,qic=0;

int *stac;
int sptr=0,sic=0;

void initque(int n){
qptr=0; rear=-1; front=0;qic=0;
que=(int*)malloc(n*sizeof(int));
}

void inits(){
stac=(int*)malloc(vc*sizeof(int));
sptr=0; sic=0;
}

void pushs(int data){
stac[sptr]=data;
sptr++;
sic++;
}

void pops(){
sptr--;
sic--;
}

bool ise(){
return sic==0;
}

void insertn(int data){
struct node *p=(struct node*)malloc(sizeof(struct node));
p->data=data;
p->visited=false;
listnode[vc]=p;
vc++;
}

void addedge(int from, int to, int **am){
am[from][to]=1;
am[to][from]=1;
}

void pushq(int n){
rear++;
que[rear]=n;
qic++;
}

void popq(){
qic--;
front++;
}

bool iqe(){
return qic==0;
}

int gaun(int temp, int **am){
int i;
for(i=0; i<vc ; i++){
	if(am[temp][i]==1 && listnode[i]->visited==false){
		return i;
		}
	}
return -1;
}

void bfs(int src, int **am , int n){
initque(n);
listnode[src]->visited=true;
printf("%d ",listnode[src]->data);
pushq(src);
int parent=1;
int child=0;
int count=1;
printf("count=%d ",count);
while(!iqe()){
	int temp=que[front];
	int a=gaun(temp,am);
	
	if(a!=-1){
	listnode[a]->visited=true;
	printf("%d ",listnode[a]->data);
	pushq(a);
	child++;
	}

	if(a==-1){
	if(parent>0){
		parent--;
		popq();
		}
	if(parent==0){
		parent=child;
		child=0;
		//popq();
		count++;
		printf("count=%d ",count);
		}
	}
}


int i; 
for(i=0; i<vc; i++){
	listnode[i]->visited=false;
	}

printf("\n");
}

void dfs(int src, int **am){
inits();
listnode[src]->visited=true;
printf("%d ",listnode[src]->data);
pushs(src);
while(!ise()){
	int temp=stac[sptr-1];
	int a=gaun(temp,am);
	if(a!=-1){
	listnode[a]->visited=true;
	printf("%d ",listnode[a]->data);
	pushs(a);
	}

	if(a==-1){
	pops();
	}
}

int i;
for(i=0 ; i<vc; i++){
listnode[i]->visited=false;
}

printf("\n");

}

int main(){
int n,m;
scanf("%d %d",&n, &m);

//Initialize our listnode and adjacent matrix and insert all nodes and edges
int **am=(int**)malloc(n*sizeof(int*));
listnode=(struct node **)malloc(n*sizeof(struct node*));
int i;
for(i=0; i<n; i++){
	insertn(i);
	am[i]=(int*)malloc(n*sizeof(int));
	}

for(i=0; i<m ; i++){
	int n1, n2;
	scanf("%d %d",&n1,&n2);
	addedge(n1,n2,am);
}

//get source
int src;
scanf("%d",&src);
bfs(src,am,n);
//dfs(src,am);


vc=0;
return 0;
}
