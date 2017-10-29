#include<iostream>
using namespace std;

bool subset_sum(int arr[],int n, int sum){
	bool subset[n+1][sum+1];
	//Sum is zero, answer is true
	for(int i=0; i<=n; i++){
		subset[i][0]=true;
		}
	//n is zero but sum is greater than 1, answer is false
	for(int i=1; i<=sum ; i++){
		subset[0][i]=false;
		}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=sum; j++){
			if(j<arr[j-1]) subset[i][j]=subset[i-1][j];
			if(j>=arr[j-1]) subset[i][j]=subset[i-1][j] || subset[i-1][j-arr[i-1]];
			}
		}
	return subset[n][sum];
	}

int main(){
clock_t begin = clock();

int t;
cin >> t;
for(int z=0; z<t; z++){
	int n;
	cin >> n;
	int arr[n];
	cout << endl << "Given array is " << endl;
	for(int i=0; i<n; i++){
		cin >> arr[i];
		cout << arr[i] << " ";
		}
	cout << endl;
	int sum;
	cin >> sum;
	bool A=subset_sum(arr,n,sum);
	if(A==true) cout << endl << "subset sum is equal to given sum" << endl;
	else cout << "Subset sum is not equal" << endl;
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
