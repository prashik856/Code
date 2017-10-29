#include<iostream>
#define MAX 2500
using namespace std;
struct node{
int data;
bool visited;
};

struct node **listnode;
int vc;
int *stack;
int sptr,sic;

void initialize(){
	listnode=new struct node*[MAX];
	vc=0;
	stack=new int[MAX];
	sptr=0;
	sic=0;
	}

void insertnode(int data){
	struct node *p=new struct node;
	p->data=data;
	p->visited=false;
	listnode[vc++]=p;
	}	

void addedge(int **am,int from, int to){
	am[from][to]=1;
	am[to][from]=1;
	}

void push(int data){
	stack[sptr++]=data;
	sic++;
	}

void pop(){
	sptr--;
	sic--;
	}

int gaun(int temp,int **am,int n){
	for(int i=0; i<n; i++){
		if(am[temp][i]==1 && listnode[i]->visited==false){
			return i;
			}
		}
	return -1;
	}

bool dfs(int **am,int n,int src,int dest){
	listnode[src]->visited=true;
	//cout << "visited " << src << endl;
	push(src);
	while(sic!=0){
		int tempn=stack[sptr-1];
		if(tempn==dest){
			return true;
			}
		int a=gaun(tempn,am,n);
		if(a!=-1){
			listnode[a]->visited=true;
			push(a);
			}
		else{
			pop();
			}
		}

	for(int i=0; i<vc; i++){
		listnode[i]->visited=false;
		}
	cout << endl;
	return false;
	}

int main(){
clock_t begin = clock();
int t;
cin >>t;
for(int z=0;z<t; z++){
	initialize();
	int n,m;
	cin >> n >> m;
	
	int **map;
	map=new int*[n];
	for(int i=0; i<n; i++){
		map[i]=new int[m]();
		}
	
	int **am;
	am=new int*[n*m];
	for(int i=0; i<n*m; i++){
		am[i]=new int[n*m]();
		}
	
	int src,dest;
	src=m*(n-1);

	//cout << "Our Input matrix is " << endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> map[i][j];
			//cout << map[i][j] << " ";
			insertnode(map[i][j]);
			if(map[i][j]==3){
				dest=m*i+j;
				}
			if(j>0){
				if(map[i][j]>0 && map[i][j-1]>0){
					addedge(am,m*i+j,m*i+j-1);
					}
				}
			}
		//cout << endl;
		}
	//cout << "Source is " << src << " " << "and destination is " << dest << endl;	

	//cout << endl << "Our Initial adjacent matrix is" << endl;
	//for(int i=0; i<n*m; i++){
	//	for(int j=0; j<n*m; j++){
	//		cout << am[i][j] << " ";
	//		}
	//	cout << endl;
	//	}
	//cout << endl;
	
	int level=1;
	int flag=0;
	while(level<n && flag==0){
		for(int i=level; i<n; i++){
			for(int j=0; j<m; j++){
				if(map[i-level][j]>0 && map[i][j]>0){
					addedge(am,m*(i-level)+j,m*i+j);
					}
				}
			}
		//cout << endl << "Our adjacent matrix in " << level << " level is" << endl;
		//for(int i=0; i<n*m; i++){
		//	for(int j=0; j<n*m; j++){
		//		cout << am[i][j] << " ";
		//		}
		//	cout << endl;
		//	}
		//cout << endl;

		if(dfs(am,n*m,src,dest)){
			cout << level << endl;
			flag=1;
			}
		else{
			level++;
			}
		}
	if(flag==0){
		cout << "-1" << endl;
		}
	//end of all queries
	cout << endl;
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
