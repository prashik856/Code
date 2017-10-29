#include <iostream>
#define INF 99999999
using namespace std;

void addedge(int **am, int n, int from, int to){
    am[from][to]=1;
    am[to][from]=1;
    }

void displaymat(int **arr, int m, int n){
	cout << endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
            }
	cout << endl;
        }
        cout << endl;
    }

void displayadj(int **am,int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << am[i][j] << " ";
        }
	cout << endl;
    }
    cout << endl;
    }

int getmin(int *dist,bool *visited, int n){
    int minv=INF;
    int min_index=0;
    for(int i=0; i<n; i++){
        if(visited[i]==false && dist[i]<minv){
            minv=dist[i];
            min_index=i;
        }
    }
    return min_index;
    }

void dijktras(int **am,int n, int src,int l){
    int *dist;
    bool *visited;
    dist=new int[n];
    visited=new bool[n];
    for(int i=0; i<n; i++){
        dist[i]=INF;
        visited[i]=false;
    }
    dist[src]=0;
    for(int i=0; i<n-1 ; i++){
        int u=getmin(dist,visited,n);
        visited[u]=true;
        for(int j=0; j<n; j++){
            if(dist[u]!=INF && am[u][j]!=0 && visited[j]==false && dist[u]+am[u][j]<dist[j]){
                dist[j]=dist[u]+am[u][j];
            }
        }
    }
    int count=0;
	cout << endl; 
    for(int i=0; i<n; i++){
	cout << dist[i] << " ";
        if(dist[i]<=l){
            count++;
        }
    }
    cout << endl << count << endl;

    }

int main()
{
    int t;
    cin >> t;
    for(int z=0; z<t; z++){
        int m,n,r,c,l;
        cin >> m >> n >> r >> c >> l;

        int **am;
        am=new int*[m*n];
        //defining and initializing our adjacent matrix
        for(int i=0; i<m*n; i++){
            am[i]=new int[m*n]();
        }
	
	//Defining our pipes matrix
        int **arr;
        arr=new int*[m];
        for(int i=0; i<m; i++){
            arr[i]=new int[n]();
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                    cin >> arr[i][j];
		    //cout << arr[i][j] << " ";
			
                    if(arr[i][j]==1){
                        if(i-1>=0){
				if(arr[i-1][j]==1 || arr[i-1][j]==3 || arr[i-1][j]==4 || arr[i-1][j]==5) addedge(am,n*m,n*i+j,n*(i-1)+j);
                        }
                        if(j-1>=0){
				if(arr[i][j-1]==1 || arr[i][j-1]==2 || arr[i][j-1]==5 || arr[i][j-1]==7) addedge(am,n*m,n*i+j-1,n*i+j);
                        }
                    }
			
                    if(arr[i][j]==2){
                        if(j-1>=0){
				if(arr[i][j-1]==1 || arr[i][j-1]==2 || arr[i][j-1]==5 || arr[i][j-1]==7) addedge(am,n*m,n*i+j-1,n*i+j);
                        }
                    }
			
                    if(arr[i][j]==3){
                        if(i-1>=0){
				if(arr[i-1][j]==1 || arr[i-1][j]==3 || arr[i-1][j]==4 || arr[i-1][j]==5) addedge(am,n*m,n*i+j,n*(i-1)+j);
                        }
                    }
		
                    if(arr[i][j]==4){
                        if(j-1>=0){
				if(arr[i][j-1]==1 || arr[i][j-1]==2 || arr[i][j-1]==5 || arr[i][j-1]==7) addedge(am,n*m,n*i+j-1,n*i+j);
                        }
                    }
			
                    if(arr[i][j]==6){
                        if(i-1>=0){
				if(arr[i-1][j]==1 || arr[i-1][j]==3 || arr[i-1][j]==4 || arr[i-1][j]==5) addedge(am,n*m,n*i+j,n*(i-1)+j);
                        }
                        if(j-1>=0){
				if(arr[i][j-1]==1 || arr[i][j-1]==2 || arr[i][j-1]==5 || arr[i][j-1]==7) addedge(am,n*m,n*i+j-1,n*i+j);
                        }
                    }
			
                    if(arr[i][j]==7){
                        if(i-1>=0){
				if(arr[i-1][j]==1 || arr[i-1][j]==3 || arr[i-1][j]==4 || arr[i-1][j]==5) addedge(am,n*m,n*i+j,n*(i-1)+j);
                        }
                    }
		//All conditions end here
                }
		//cout << endl;
            }
	
	//cout << endl;
        displaymat(arr,m,n);
        cout << endl;
        displayadj(am,n*m);
        cout << endl;

        //We got our adjacent matrix
        int src=n*r+c;
        dijktras(am,n*m,src,l);

    }
    return 0;
}
