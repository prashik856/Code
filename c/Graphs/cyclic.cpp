#include<iostream>
#include<vector>
using namespace std;

bool cycle(vector < vector < int > >& adj, bool *visited, bool *stack, int node){
	if(visited[node]==false){
		visited[node]=true;
		stack[node]=true;
		for(int i=0; i<adj[node].size(); i++){
			int v=adj[node][i];
			if(visited[v]==false && cycle(adj,visited,stack,v)) return true;
			else if(stack[v]) return true;
			}
		}
	stack[node]=false;
	return false;
	}

bool iscyclic(vector < vector < int > >& adj){
	int n=adj.size();
	bool *visited= new bool[n];
	bool *stack= new bool[n];
	for(int i=0; i<n; i++){
		visited[i]=false;
		stack[i]=false;
		}
	for(int i=0; i<n; i++){
		if(cycle(adj,visited,stack,i)){ 
			return true;
			}
		}
	return false;
	}

int main(){
clock_t begin = clock();

int n;
cin >> n;
vector < vector < int > > adj;
adj.resize(n);
int m;
cin >> m;
for(int i=0; i<m; i++){
	int from,to;
	cin >> from >> to;
	adj[from].push_back(to);
	}
cout << endl << "Our adjacent matrix is as follows" << endl;
for(int i=0; i<n; i++){
	for(int j=0; j<adj[i].size(); j++){
		cout << adj[i][j] << " ";
		}
	cout << endl;
	}

if(iscyclic(adj)){
	cout << endl << "The Graph contains cycle" << endl ;
	}
else{ 
	cout << endl << "The Graph does not contain a cycle" << endl;
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
