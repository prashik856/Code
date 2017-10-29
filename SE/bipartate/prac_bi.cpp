#include<iostream>
#define MAX 1000
using namespace std;
struct node{
int data;
int color;
bool visited;
};

struct node **listnode;
int vc;
int *que1,*que2,rear,front,qic;

void initialize(){
	listnode=new struct node*[MAX];
	que1=new int[MAX];
	que2=new int[MAX];
	vc=0;
	rear=-1;front=0;qic=0;
	}

void insertnode(int data){
	struct node *p=new struct node;
	p->data=data;
	p->color=-1;
	p->visited=false;
	listnode[vc++]=p;
	}

void push(int node,int color){
	++rear;
	que1[rear]=node;
	que2[rear]=color;
	qic++;
	}

void pop(){
	front++;
	qic--;	
	}

bool bipartate(int **am,int n){
	int src=0;
	listnode[src]->visited=true;
	listnode[src]->color=1;
	push(src,1);
	while(qic!=0){
		int tempn=que1[front];
		int tempc=que2[front];
		for(int i=0; i<n; i++){
			if(am[tempn][i]==1){
				if(listnode[i]->visited==false){
					listnode[i]->visited=true;
					listnode[i]->color=1-tempc;
					push(i,1-tempc);
					}
				else{
				if(listnode[i]->color==tempc){
					return false;
					}
				}
				}
			}
		pop();
		}
	return true;
	}

int main(){
clock_t begin = clock();
int t;
cin >> t;
for(int z=0;z<t; z++){
	initialize();
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		insertnode(i);
		}
	int **am;
	am=new int*[n];
	for(int i=0;i<n; i++){
		am[i]=new int[n];
		}
	
	int m;
	cin >> m;
	for(int i=0; i<m;i++){
		int from,to;
		cin >> from >> to;
		am[from][to]=1;
		am[to][from]=1;
		}
	if(bipartate(am,n)) cout << "Graph is bipartate" << endl;
	else cout << "Graph is not bipartate" << endl;
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
