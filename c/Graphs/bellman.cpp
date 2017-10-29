#include<iostream>
#include<vector>
#define INF 999999
using namespace std;

void printpath(int src, int *pre,int n,int i){
	if(i==src){
		cout << src << "->" ;
		}
	else{
		printpath(src,pre,n,pre[i]);
		cout << i << "->";
		}
	}

int main(){
clock_t begin = clock();

int n;
cin >> n;
int src;
cin >> src;
int *dist;
int *pre;
dist=new int[n];
pre=new int[n];
for(int i=0; i<n; i++){
	dist[i]=INF;
	pre[i]=-1;
	}
dist[src]=0;
int m;
cin >> m;
vector < vector <int> > edges;
edges.resize(m);
for(int i=0; i<m; i++){
	//edges[i].resize(3);
	int f,t,w;
	cin >> f >> t >> w;
	edges[i].push_back(f);
	edges[i].push_back(t);
	edges[i].push_back(w);
	}
for(int i=0; i<n-1; i++){
	for(int j=0; j<edges.size(); j++){
		if(dist[edges[j][0]]+edges[j][2] < dist[edges[j][1]]){
			dist[edges[j][1]]=edges[j][2]+dist[edges[j][0]];
			pre[edges[j][1]]=edges[j][0];
			}
		}
	}

for(int i=0; i<m ; i++){
	if(dist[edges[i][0]]+edges[i][2]<dist[edges[i][1]]){
		cout << endl << "Error, there is a negative cycle in the graph" << endl;
		}
	}

cout << endl << "The distance between source to all other nodes is " << endl;
for(int i=1; i<n; i++){
	cout << src << "->" << i << " Distance = " << dist[i] << endl; 
	}

cout << endl << "The pre array is " << endl;
for(int i=0; i<n; i++){
	cout << i << "->" << pre[i] << " ";
	}
cout << endl;

cout << endl << "The Path to all other nodes from source is " << endl;
for(int i=1; i<n; i++){
	int u=pre[i];
	cout << i << "<-" << u << "<-";
	while(u!=src){
		u=pre[u];
		cout << u << "<-";
		}
	cout << "start" << endl;
	}

cout << endl << "The Path from start to end is " << endl;
for(int i=0; i<n; i++){
	printpath(src,pre,n,i);
	cout << "end" << endl;
	}


clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
