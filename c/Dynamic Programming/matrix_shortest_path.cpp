#include<iostream>
using namespace std;

int getmin(int a, int b, int c){
	int min=999999;
	int arr[3]={a,b,c};
	for(int i=0; i<3; i++){
		if(arr[i]!=0 && arr[i]<min){
			min=arr[i];
			}
		}
	if(min==999999){
		return 0;		
		}
	else{
		return min;
		}
	}	

void shortest_path(int **arr,int n, int m,int **L){
	for(int i=n-1 ; i>=0; i--){
		for(int j=m-1 ; j>=0; j--){
			L[i][j] = arr[i][j] + getmin(L[i][j+1],L[i+1][j],L[i+1][j+1]);
			//cout << L[i][j] << "\t";
			}
		//cout << endl;
		}
	for(int i=0; i<=n; i++){
			for(int j=0; j<=m; j++){
				cout << L[i][j] << " ";
				}
			cout << endl;
			}
	cout << endl << "the sum of shortest path is " << L[0][0] << endl;
	}

int main(){
clock_t begin = clock();

int n,m;
cin >> n >> m;
int **arr;
int **L;
arr=new int*[n];
L=new int *[n+1];
for(int i=0; i<=n; i++){
	if(i<n){
		arr[i]=new int[m];
		}
	L[i]=new int[m+1];
	for(int j=0; j<=m; j++){
		L[i][j]=0;
		if(j<m){
		cin >> arr[i][j];
			}
		}
	}
for(int i=0; i<n; i++){
	for(int j=0; j<m; j++){
		cout << arr[i][j] << " ";
		}
	cout << endl;
	}
cout << endl;
for(int i=0; i<=n; i++){
			for(int j=0; j<=m; j++){
				cout << L[i][j] << " ";
				}
			cout << endl;
			}

cout << endl << "After function is called" << endl;
shortest_path(arr,n,m,L);

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
