#include<iostream>
#include<cmath>
using namespace std;

bool subset_sum(int arr[],int n,int sum){
	if(sum==0) return true;
	if(n==0 && sum!=0) return false;
	if(arr[n-1]>sum) subset_sum(arr,n-1,sum);
	return subset_sum(arr,n-1,sum) || subset_sum(arr,n-1,sum-arr[n-1]);
	}

int main(){
clock_t begin = clock();

int t;
cin >> t;
for(int z=0; z<t; z++){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
		}
	int sum;
	cin >> sum;
	cout << endl << "The given array is " << endl;

	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
		}

	bool A=subset_sum(arr,n,sum);
	if(A==true) cout << endl << "Is possible" << endl;
	else if(A==false) cout << endl << "Not possible" << endl;
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
