#include<iostream>
using namespace std;

int coin_change(int arr[],int k,int n){
	int top[n+1]={0};	
	top[0]=1;
	for(int i=0; i<k; i++){
		for(int j=arr[i] ; j<=n; j++){
			top[j]=top[j]+top[j-arr[i]];
			//cout << top[i] << " " ;
			}
		//cout << endl;
		}
	//cout << endl << endl;
	return top[n];
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
