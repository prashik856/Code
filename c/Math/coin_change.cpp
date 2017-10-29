#include<iostream>
using namespace std;

int coin_change(int arr[],int k,int n){
	if(n==0) return 1;
	if(n<0) return 0;
	if(k<=0 && n>=1) return 0;
	return coin_change(arr,k-1,n)+coin_change(arr,k,n-arr[k-1]);
	}

int main(){
clock_t begin = clock();

int t;
cin >> t;
for(int z=0; z<t; z++){
	int n;
	cin >> n;
	int k;
	cin >> k;
	int arr[k];
	for(int i=0; i<k; i++){
		cin >> arr[i];
		}
	int l=coin_change(arr,k,n);
	cout << l << endl;
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
