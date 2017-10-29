#include<iostream>
using namespace std;

int maxv=0;

void subprob(int *arr,int l, int cl, int cp, int i){
	if(cl==l){
		if(cp > maxv){
			maxv=cp;
			}
		}
	else if(cl>l){
		return;
		}
	else if(cl < l){
		cl=cl+i;
		cp=cp+arr[i-1];
		for(int j=0; j<l ; j++){
			subprob(arr,l,cl,cp,j+1);
			}
		}
	}

void cutting_rod(int *arr,int n){
		
	for(int i=0; i<n; i++){
		int cl=0,cp=0;
		subprob(arr,n,cl,cp,i+1);
		}
	}

int main(){
clock_t begin = clock();

int t;
cin >> t;
for(int z=0 ; z<t; z++){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
		}
	cutting_rod(arr,n);
	cout << endl << maxv << endl;
	maxv=0;
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
