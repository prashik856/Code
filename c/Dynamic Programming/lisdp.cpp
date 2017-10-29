#include<iostream>
using namespace std;

int lis(int arr[],int n){
	int list[n],max=0;
	for(int i=0; i<n; i++){
		list[i]=1;
		}
	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){
			if(arr[j]<arr[i] && list[i]<list[j]+1){
				list[i]=list[j]+1;
				}
			}
		}
	for(int i=0; i<n; i++){
		if(max<list[i]){
			max=list[i];
			}		
		}
	return max;
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
	int l=lis(arr,n);
	cout << endl << l << endl;
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
