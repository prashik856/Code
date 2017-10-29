#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 50
struct node{
int data;
bool visited;
};

struct node *listnode[MAX];
int vc=0;

int que[MAX];
int rear=-1,front=0,qic=0;

void pushn(int data){
que[++rear]=data;
qic++;
}

void popn(){
front++;
qic--;
}

bool iqe(){
return qic==0;
}

void insertn(int data){
struct node *p=(struct node*)malloc(sizeof(struct node));
p->data=data;
p->visited=false;
listnode[vc++]=p;
}

void addedge(int **am,int from,int to){
am[from][to]=1;
am[to][from]=1;
}

int gaun(int **am, int temp){
for(int i=0; i<vc; i++){
	if(am[temp][i]==1 && listnode[i]->visited==false){
		return i;
		}
	}
return -1;
}

void bfs(int src, int dest, int**am){
int *pr;
pr=(int*)malloc(vc*sizeof(int));
listnode[src]->visited=true;
pushn(src);
while(!iqe()){
	int temp=que[front];
	int a=gaun(am,temp);
	if(a!=-1){
		pr[a]=temp;
		listnode[a]->visited=true;
		pushn(a);
		}
	if(a==-1){
		popn();
		}
	}

int i=pr[dest];
int count=0;
while(i!=src){
	count++;
	i=pr[i];
	}

printf("%d\n",count);

}

int main(){
int n;
scanf("%d",&n);
for(int i=0; i<n;i++){
	insertn(i);
	}

int **am;
am=(int **)malloc(n*sizeof(int*));
for(int i=0; i<n; i++){
	am[i]=(int*)calloc(n,sizeof(int));
	}

int m;
scanf("%d",&m);

for(int i=0; i<m; i++){
	int from,to;
	scanf("%d %d",&from,&to);
	addedge(am,from,to);
	}

int src,dest;
scanf("%d %d",&src,&dest);

bfs(src,dest,am);

return 0;
}
