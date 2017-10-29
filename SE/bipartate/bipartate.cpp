#include<iostream>
#define MAX 1000
using namespace std;

struct node{
int color;
bool visited;
};

struct node *listnode[MAX];
int vc=0;

int *que1;
int *que2;
int rear1=-1,rear2=-1;
int front1=0,front2=0;
int qic1=0,qic2=0;

void push(int index,int color){
	que1[++rear1]=index;
	que2[++rear2]=color;
	qic1++; qic2++;
	}

void pop(){
	front1++;
	front2++;
	qic1--;
	qic2--;
	}

bool iqe(){
	return qic1==0;
	}

void initialize(){
	que1=new int[MAX];
	que2=new int[MAX];
	rear1=-1; rear2=-1; front1=0; front2=0; qic1=0; qic2=0; vc=0; 
	}

void insertnode(){
	struct node *p=new struct node;
	p->color=-1;
	p->visited=false;
	listnode[vc++]=p;
	}

void addedge(int **am,int n,int from,int to){
	am[from][to]=1;
	am[to][from]=1;
	}

bool isbipartate(int **am,int n){
	listnode[0]->visited=true;
	listnode[0]->color=1;
	push(0,1);
	while(!iqe()){
		int tempi=que1[front1];
		int tempc=que2[front2];
		for(int i=0; i<n; i++){
			if(am[tempi][i]!=0){
				if(listnode[i]->visited==false){
					listnode[i]->visited=true;
					listnode[i]->color=1-tempc;
					push(i,listnode[i]->color);
					}
				else if(listnode[i]->visited==true){
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
for(int z=0; z<t; z++){
	initialize();
	int n,m;
	cin >> n >> m;
	int **am;
	am=new int*[n];
	for(int i=0; i<n; i++) am[i]=new int[n]();
	for(int i=0; i<n; i++) insertnode();
	for(int i=0; i<m; i++){
		int from,to;
		cin >> from >> to;
		addedge(am,n,from,to);
		}
	if(isbipartate(am,n)) cout << endl << "The given graph is bipartate" << endl;
	else cout << endl << "The given graph is not bipartate" << endl;
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
