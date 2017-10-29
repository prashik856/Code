#include<iostream>
#define MAX 99999999
using namespace std;

void addedge(int **am,int from,int to){
	am[from][to]=1;
	am[to][from]=1;
	}

int getmindist(int *dist,bool *visited,int n){
	int minv=MAX;
	int mini=0;
	for(int i=0; i<n; i++){
			if(dist[i]<minv && visited[i]==false){
				minv=dist[i];
				mini=i;
				}
		}
	return mini;
	}

int dijktras(int **am,int n, int src,int l){
	int *dist;
	bool *visited;
	dist=new int[n];
	visited=new bool[n];
	for(int i=0; i<n; i++){
		dist[i]=MAX;
		visited[i]=false;
		}
	dist[src]=1;
	for(int i=0; i<n; i++){
		int u=getmindist(dist,visited,n);
		visited[u]=true;
		for(int j=0; j<n; j++){
			if(visited[j]==false && am[u][j]==1 && dist[u]!=MAX && dist[u]+am[u][j]<dist[j]){
				dist[j]=dist[u]+am[u][j];
				}
			}
		}
	int count=0;
	for(int i=0; i<n; i++){
		if(dist[i]<=l){
			count++;
			}	
		}
	return count;
	}

int main(){
clock_t begin = clock();
int t;
cin >> t;
for(int z=0; z<t; z++){
	int n,m,r,c,l;
	cin >> n >> m >> r >> c >> l;

	int **a;
	a=new int*[n];
	for(int i=0; i<n; i++){
		a[i]=new int[m];
		}

	int **am;
	am=new int*[n*m];
	for(int i=0; i<n*m; i++){
		am[i]=new int[n*m]();
		}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> a[i][j];
			if(a[i][j]==1){
				if(i>0){
					if(a[i-1][j]==1 || a[i-1][j]==3 || a[i-1][j]==4 || a[i-1][j]==5){
						addedge(am,m*i+j,m*(i-1)+j);
						}
					}
				if(j>0){
					if(a[i][j-1]==1 || a[i][j-1]==2 || a[i][j-1]==5 || a[i][j-1]==7){
						addedge(am,m*i+j,m*i+j-1);
						}
					}
				}
			if(a[i][j]==2){
				if(j>0){
					if(a[i][j-1]==1 || a[i][j-1]==2 || a[i][j-1]==5 || a[i][j-1]==7){
						addedge(am,m*i+j,m*i+j-1);
						}

					}
				}
			if(a[i][j]==3){
				if(i>0){
					if(a[i-1][j]==1 || a[i-1][j]==3 || a[i-1][j]==4 || a[i-1][j]==5){
						addedge(am,m*i+j,m*(i-1)+j);
						}
					}
				}
			if(a[i][j]==4){
				if(j>0){
					if(a[i][j-1]==1 || a[i][j-1]==2 || a[i][j-1]==5 || a[i][j-1]==7){
						addedge(am,m*i+j,m*i+j-1);
						}

					}
				}
			if(a[i][j]==6){
				if(i>0){
					if(a[i-1][j]==1 || a[i-1][j]==3 || a[i-1][j]==4 || a[i-1][j]==5){
						addedge(am,m*i+j,m*(i-1)+j);
						}
					}
				if(j>0){
					if(a[i][j-1]==1 || a[i][j-1]==2 || a[i][j-1]==5 || a[i][j-1]==7){
						addedge(am,m*i+j,m*i+j-1);
						}

					}
				}
			if(a[i][j]==7){
				if(i>0){
					if(a[i-1][j]==1 || a[i-1][j]==3 || a[i-1][j]==4 || a[i-1][j]==5){
						addedge(am,m*i+j,m*(i-1)+j);
						}
					}
				}
			}
		}
	//check adjacent matrix
	for(int i=0; i<n*m; i++){
		for(int j=0; j<n*m; j++){
			cout << am[i][j] << " ";
			}
		cout << endl;
		}
	cout << endl;
	int b=dijktras(am,n*m,m*r+c,l);
	cout << b << endl << endl << endl;	
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
