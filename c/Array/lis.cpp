#include<iostream>
#include<vector>
using namespace std;

int subl(int arr[],int n, int *max_ref){
	if(n==1){
		return 1;
		}
	int res,meh=1;
	for(int i=1; i<n; i++){
		res=subl(arr,i,max_ref);
		if(arr[i-1]<arr[n-1] && res+1>meh){
			meh=res+1;
			}
		}
	if(*max_ref < meh){
		*max_ref=meh;
		}
	return meh;
	}

void lis(int arr[],int n){
	int max=1;
	subl(arr,n,&max);
	cout << endl << max << endl;
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
	lis(arr,n);
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
