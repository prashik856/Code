#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 50
struct node{
int data;
int color;
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
qic--;
front++;
}

void insertn(int data){
struct node* p= (struct node*)malloc(sizeof(struct node));
p->data=data;
p->color=-1;
listnode[vc++]=p;
}

void addedge(int **am, int from, int to){
am[from][to]=1;
}

bool bipartate(int **am, int src){
listnode[src]->color=1;
pushn(src);
while(qic!=0){
	int u=que[front];
	popn();
	if(am[u][u]==1){
		return false;	
		}
	for(int i=0; i<vc; i++){
		if(am[u][i]==1 && listnode[i]->color==-1){
			listnode[i]->color=1-listnode[u]->color;
			pushn(i);
			}
		if(am[u][i]==1 && listnode[i]->color==listnode[u]->color){
			return false;
			}
		}
		
	}
	
return true;
}

int main(){
int n;
scanf("%d",&n);
int **am;
am=(int **)malloc(n*sizeof(int*));
for(int i=0; i<n; i++){
	insertn(i);
	am[i]=(int*)calloc(n,sizeof(int));
	}

int m;
scanf("%d",&m);
for(int i=0; i<m; i++){
	int from, to;
	scanf("%d %d",&from, &to);
	addedge(am,from,to);
	}
int src;
scanf("%d",&src);
bool a=bipartate(am,src);
printf("%d",a);
if(a==true){
	printf("YES\n");
	}
else{
	printf("NO\n");}
return 0;
}
