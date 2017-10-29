#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#define MAX 50
#define INF 999999

using namespace std;

struct node {
int data;
bool visited;
};

struct node *listnode[MAX];
int vc=0;

void display( vector< vector <int> >& am){
	for(int i=0; i<vc; i++){
		for(int j=0; j<am[i].size() ; j++){
			cout << am[i][j] << " ";
			}
		cout << endl;
		}
}

void insert(int a){
struct node *p=new struct node;
p->data=a;
p->visited=false;
listnode[vc]=p;
vc=vc+1;
}

void addedge( vector < vector <int> >& am , int from, int to,int weight){
am[from][to]=weight;
am[to][from]=weight;	
//cout << am[from].size() << " " << am[to].size() << endl;
}

int get_min(vector <int>& dist,vector <int>& mstset){
	int min=999999,min_index;
	for(int i=0; i<dist.size(); i++){
		if(dist[i]<min && mstset[i]==0){
			min=dist[i];
			min_index=i;
			}
		}
	return min_index;
	}

void prims(vector < vector <int> >& am, int src){
vector <int> dist;
vector <int> mstset;
vector <int> parent;
dist.assign(am.size(),999999);
parent.assign(am.size(),0);

dist[src]=0;
parent[src]=-1;

//cout << src << "->";
mstset.assign(am.size(),0);
//mstset[src]=1;

for(int i=0; i<am.size()-1; i++){
	//for(int i=0; i<dist.size(); i++){
	//	cout << dist[i] << " ";
	//	}
	//cout << endl;
	int u=get_min(dist,mstset);
	mstset[u]=1;
	//cout << u << "->";
	int pivot = u;
	for(int j=0; j<am.size() ; j++){
		if(dist[u]!=INF && am[u][j]!=0 && mstset[j]==0 && dist[u]+am[u][j]<dist[j]){ //use am[u][j]<dist[j];dist[j]=am[u][j];parent[j]=u;
			parent[j]=u;			
			dist[j]=dist[u]+am[u][j];
			//pivot=u;
			//cout << pivot << "->" ;
			}
		}
	}
for(int i=0; i<am.size(); i++){
	if(i!=src){
		cout << parent[i] << "-" << i << "\t" << am[i][parent[i]] << endl;
		}
	}
cout << endl;
}

int main(){
int n;
cin >> n;
for(int i=0; i<n; i++){
	int t;	
	cin >> t;
	insert(t);
	}
cout << endl;

for(int i=0; i<vc; i++){	
	cout << listnode[i]->data << " ";
	}
cout << endl;
//make an adjacency list
vector < vector<int> > am;
am.resize(n);
for(int i=0; i<n; i++){
	am[i].resize(n,0);
	} 
//cout << am[0].size() << endl;
int m;
cin >> m;
for(int i=0; i<m ; i++){
	int from,to,weight;
	cin >> from;
	cin >> to;
	cin >> weight;
	//cout << i << " ";
	addedge(am,from,to,weight);
	}
//cout << "\ndone" << endl;
//print our adjacency list

cout << endl << "Our Adjacency list is" << endl;
display(am);

//Prims algo
cout << endl << "The shortest path to every algo by prims algo is" << endl;
cout << am.size() << endl;
int src;
cin >> src;
prims(am,src);
return 0;
}
