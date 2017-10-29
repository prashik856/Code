#include<iostream>
using namespace std;

int max_sum(int arr[],int n){
	int msum[n];
	for(int i=0; i<n; i++){
		msum[i]=arr[i];
		}
	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){
			if(arr[i]>arr[j] && msum[i] < msum[j]+arr[i]){
				msum[i]=msum[j]+arr[i];
				}
			}
		}
	int max=0;
	for(int i=0; i<n; i++){
		if(max<msum[i]){
			max=msum[i];
			}
		}
	return max;
	}

int main(){
int t;
cin >> t;
for(int z=0; z<t; z++){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n ; i++){
		cin >> arr[i];
		}
	int s=max_sum(arr,n);
	cout << endl << s << endl;
	}

return 0;
}
