#include<iostream>
using namespace std;

int step=99999;

void subprob(int arr[],int n, int current_location,int current_jump, int max_jump){
	if(current_location>=n){
		return;
		}
	if(current_location==n-1){
		if(current_jump<step){
			step=current_jump;
			}
		}
	if(current_location<n-1){
		for(int i=1; i<=max_jump; i++){
			subprob(arr,n,current_location+i,current_jump+1,arr[current_location+i]);
			}
		}
	}

void minstep(int arr[],int n){
	int current_location=0,current_jump=0,max_jump=arr[0];
	subprob(arr,n,current_location,current_jump,max_jump);
	}

int main(){
clock_t begin = clock();

int n;
cin >> n;
int arr[n];
for(int i=0; i<n; i++){
	cin >> arr[i];
	}
minstep(arr,n);
cout << endl << step << endl;


clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
