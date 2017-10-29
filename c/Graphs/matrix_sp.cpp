#include<iostream>
using namespace std;

int cost=999999;

int subprob(int **arr,int n, int m ,int i, int j,int cost2){
	if(i>=n || j>=n){
		return 0;
		}
	else if(i<n && j<n){
		if(i==n-1 && j==m-1){
			cost2=cost2+arr[i][j];
			if(cost2<cost){
				cost=cost2;
				}
			return 0;
			}
		else{
			cost2=cost2+arr[i][j];	
			subprob(arr,n,m,i+1,j,cost2);
			subprob(arr,n,m,i,j+1,cost2);
			subprob(arr,n,m,i+1,j+1,cost2);
			}
		}
	}

void minpath(int **arr, int n , int m){
	int i=0,j=0;
	int cost2=0;
	subprob(arr,n,m,i,j,cost2);
	cout << endl << cost << endl;
	}

int main(){
clock_t begin = clock();

int n,m;
cin >> n >> m;
int **arr;
arr=new int*[n];
for(int i=0; i<n; i++){
	arr[i]=new int[m];
	for(int j=0; j<m ;j++){
		cin >> arr[i][j];
		}
	}
minpath(arr,n,m);

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
