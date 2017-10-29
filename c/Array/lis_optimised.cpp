#include<iostream>
#include<vector>
using namespace std;

int ceilindex(vector <int>& tail, int l, int r, int key){
	while(r-l>1){
		int m=l+(r-l)/2;
		if(tail[m]>=key){
			r=m;
			}
		else l=m;	
		}
	return r;
	}

int lis(int arr[],int n){
	if(n==0){
		return 0;
		}	
	vector <int> tail(n,0);
	int length=1;	
	tail[0]=arr[0];
	for(int i=1; i<n; i++){
		if(arr[i]<tail[0]){
			tail[0]=arr[i];
			}
		else if(arr[i]>tail[length-1]){
			tail[length++]=arr[i];
			}
		else{
			tail[ceilindex(tail,-1,length-1,arr[i])]=arr[i];
			}
		}
	return length;
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
