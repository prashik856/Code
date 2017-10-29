#include<iostream>
#define MAX 10000
#define INF 99999
using namespace std;

struct node{
int data;
bool visited;
};

struct node *listnode[MAX];
int vc;

void initialize(){
	vc=0;
	}

void insert(int data){
	struct node *p=new struct node;
	p->data=data;
	p->visited=false;
	listnode[vc++]=p;
	}

void addedge(int **am, int from, int to){
	am[from][to]=1;
	am[to][from]=1;
	}

int getmax2(int *dist,int n){
	int maxv=0;
	for(int i=0; i<n ; i++){
		if(dist[i]>maxv){
			maxv=dist[i];
			}
		}
	return maxv;
	}

int getmax(int *dist,int n, int empty,int m){
	int arr[4];	
	arr[0]=empty-1;
	arr[1]=empty+1;
	arr[2]=empty-m;
	arr[3]=empty+m;
	int maxv=0;
	for(int i=0; i<4; i++){
		if(dist[arr[i]]>maxv){
			maxv=dist[arr[i]];
			}	
		}
	return maxv;
	}

int getmin(int *dist, int n){
	int min_node=0;
	int min_dist=INF;	
	for(int i=0; i<n; i++){
		if( dist[i]!=0 && dist[i] < min_dist && listnode[i]->visited == false){
			min_dist=dist[i];
			min_node=i;
			}
		}
	return min_node;
	}

void bfs(int **am, int n, int src, int empty,int m){
	int *dist;
	int count1=0;
	int count2=0;
	dist=new int[n];
	for(int i=0; i<n; i++){
		dist[i]=INF;
		if(listnode[i]->data==0){
			dist[i]=0;
			listnode[i]->visited=true;
			}
		}
	dist[src]=1;
	for(int i=0; i<n-1; i++){
		int u=getmin(dist,n);
		listnode[u]->visited=true;
		for(int j=0; j<n ;j++){
			if(dist[u]!=INF && am[u][j]!=0 && listnode[j]->visited==false && dist[j]!=0 && dist[u]+am[u][j]<dist[j]){
				dist[j]=dist[u] + am[u][j];
				}
			}
		}
	//We got our distance
	count2=getmax(dist,n,empty,m);
	if(count2==INF){
		cout << "-1" << " " << "-1" << endl;
		}
	else if(count2!=INF){
		count1=getmax2(dist,n);
		if(count1==INF){
			cout << count2 << " " << "-1" << endl;
			}
		else{
			cout << count2 << " " << count1 << endl;
			}
		}
	//cout << count2 << " " << count1 << endl;
	}

int main(){
clock_t begin = clock();

int t;
cin >> t;
for(int zo=0; zo<t; zo++){
	initialize();
	cout << "#" << zo << endl;
	int n,m;
	cin >> n >> m;
	
	//Defining our array
	int **arr;
	arr=new int*[n];
	for(int i=0; i<n; i++) arr[i]=new int[m]();
	
	int r,c;
	cin >> r >> c;
	
	//Defining our adjacent matrix;
	int **am;
	am=new int*[n*m];
	for(int i=0; i<n*m; i++) am[i]=new int[m]();
	
	//For storing point C type
	int rc,cc;	
	
	// 0-stone 1-metal 2-space
	//Reading input
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> arr[i][j];
			insert(arr[i][j]);
			if(arr[i][j]==2){
				rc=i; cc=j;
				}
			//up
			if(i-1>=0){
				if(arr[i][j]==1 && arr[i-1][j]==1){
					addedge(am,m*(i-1)+j,m*i+j);
					}
				}
			//left
			if(j-1>=0){
				if(arr[i][j]==1 && arr[i][j-1]==1){
					addedge(am,m*i+j,m*i+j-1);
					}
				}
			}
		}
		
	//Construction of adjacent matrix is done
	int src=m*r+c;
	int empty=m*rc+cc;
	bfs(am,n*m,src,empty,m);
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
