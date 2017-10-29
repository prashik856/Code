#include<iostream>
#define MAX 100000
using namespace std;

struct node{
int data;
bool visited;
};

struct node *listnode[MAX];
int vc=0;

int *que;
int rear,front,qic;

void initialize(){
que=new int[MAX];
vc=0;
rear=-1;
front=0;
qic=0;
}	

void push(int data){
	que[++rear]=data;
	qic++;
	}

void pop(){
	front++;
	qic--;
	}

void insert(int data){
struct node *p=new struct node;
p->data=data;
p->visited=false;
listnode[vc++]=p;
}

bool iscyclic(int **am, int n){
	for(int i=0; i<n; i++){
		listnode[i]->visited=true;
		push(i);
		int src=i;
		while(qic!=0){
			int temp=que[front];
			for(int j=0; j<n; j++){
				if(am[temp][j]==1 && listnode[j]->visited==false){
					listnode[j]->visited=true;
					push(j);
					}
				else if(am[temp][j]==1 && listnode[j]->visited==true){
					if(j==src){
						return true;
						}
					}
				}
			pop();
			}
		for(int j=0; j<vc; j++){
			listnode[j]->visited=false;
			}
		}
	return false;
	}

int main(){
clock_t begin = clock();

int t;
cin >> t;
for(int z=0; z<t; z++){
	initialize();
	int n;
	cin >> n;
	int **am;
	am=new int*[n];	
	for(int i=0; i<n; i++){
		insert(i);
		am[i]=new int[n]();
		}
	int m;
	cin >> m;
	for(int i=0; i<m; i++){
		int from,to;
		cin >> from >> to;
		am[from][to]=1;
		}
	
	/*cout << endl << "Reading input done" << endl;

	//displaying our adjacent matrix	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << am[i][j] << " ";
			}
		cout << endl;
		}	
	*/
	
	if(iscyclic(am,n)) cout << endl << "The graph is cyclic" << endl;
	else cout << endl << "The graph is not cyclic" << endl;

	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
