#include<iostream>
#include<vector>
#define INF 9999999
using namespace std;

int main(){
clock_t begin = clock();

int n;
cin >> n;
int **dist;
int **next;
dist=new int*[n];
next=new int*[n];
for(int i=0; i<n; i++){
	dist[i]=new int[n];
	next[i]=new int[n];
	for(int j=0; j<n; j++){
		next[i][j]=-1;
		if(i==j){
			dist[i][j]=0;				
			}		
		else dist[i][j]=INF;
		}
	}
int m;
cin >> m;
for(int i=0; i<m; i++){
	int f,t,w;
	cin >> f >> t >> w;
	dist[f][t]=w;
	next[f][t]=t;
	}
for(int k=0; k<n ;k++){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(dist[i][j]>dist[i][k]+dist[k][j]){
				dist[i][j]=dist[i][k]+dist[k][j];
				next[i][j]=next[k][j];
				}
			}
		}
	}
for(int i=0; i<n; i++){
	for(int j=0; j<n; j++){
		if(next[i][j]==-1){
			cout << endl << "the shortes path between points " << i << " and " << j << " is NULL" << endl;
			}
		else{
			vector <int> path;
			int u=i,v=j;
			while(u!=v){
				u=next[u][v];
				path.push_back(u);
				}
			cout << endl << "the Shortest path between points " << i << " and " << j << " is " << endl ;
			for(int k=0; k<path.size(); k++){
				cout << path[k] << "->";
				}
			cout << "end" << endl;
			}
		}
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
