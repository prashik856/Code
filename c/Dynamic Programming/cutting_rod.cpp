#include<iostream>
using namespace std;

int cutting_rod(int *arr,int n){
	int v[n+1]={0};
	v[0]=0;
	
	for(int i=1; i<=n; i++){
		int maxv=0;
		for(int j=0; j<i; j++){
			maxv=max(maxv,arr[j]+v[i-j-1]);
			}
		v[i]=maxv;
		}
	return v[n];
	}

int main(){
clock_t begin = clock();

int t;
cin >> t;
for(int z=0; z<t; z++){
	int n;
	cin >> n;
	int arr[n];
	for(int j=0; j<n ;j++){
		cin >> arr[j];
		}
	int l=cutting_rod(arr,n);
	cout << endl << l << endl;
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
