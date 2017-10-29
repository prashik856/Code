#include<iostream>
using namespace std;

void rotate90(int **arr, int n){
	//for every fucking square	
	for(int i=0; i<n/2; i++){
		for(int j=i; j<n-i-1; j++){
			int temp=arr[i][j];
			arr[i][j]=arr[j][n-i-1];
			arr[j][n-1-i]=arr[n-1-i][n-1-j];
			arr[n-1-i][n-1-j]=arr[n-1-j][i];
			arr[n-1-j][i]=temp;
			}
		}
	}

void printmatrix(int **arr,int n){
	cout << endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << arr[i][j] << " ";
			}
		cout << endl;
		}
	cout << endl;
	}

int main(){
clock_t begin = clock();

int t;
cin >> t;
for(int z=0; z<t; z++){
	int n;
	cin >> n;
	int **arr;
	arr=new int*[n];
	for(int i=0; i<n; i++) arr[i]=new int[n];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i][j];
			}
		}
	cout << endl << "Our Original Matrix is" << endl;
	printmatrix(arr,n);
	rotate90(arr,n);
	cout << endl << "our rotated matric is " << endl;
	printmatrix(arr,n);
	cout << endl;
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
