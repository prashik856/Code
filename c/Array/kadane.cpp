#include<iostream>
using namespace std;

void max_sum(int *a, int n){
int max_end=0,max_sofar=0;
int minn=-99999;
int flagz=0;
int l,h,s=0;
int minn_i;
int z_i=0;
for(int i=0; i<n; i++){
	max_end=max_end+a[i];
	//l=i;
	if(max_end<0){
		s=i+1;
		max_end=0;
		}
	else if(max_end>0 && max_sofar<max_end){
		//l=i;
		h=i;
		l=s;
		max_sofar=max_end;
		}
	if(a[i]<0 && a[i]>minn){
		minn=a[i];
		minn_i=i;
		}
	if(a[i]==0){
		flagz=1;
		z_i=i;
		}
	}
if(max_sofar!=0){
	cout << endl << max_sofar << endl;
	for(int i=l; i<=h; i++){
		cout << a[i] << " ";
		}	
	cout << endl;
	}
if(max_sofar==0 && flagz==1){
	cout << endl << max_sofar << endl;
	cout << a[z_i] << endl;
	}
if(max_sofar==0 && flagz==0){
	cout << endl << minn << endl;
	cout << a[minn_i] << endl;
	}

}

int main(){
int t;
cin >> t;
for(int x=0; x<t ; x++){
	int n;
	cin >> n;
	int *a;
	a=new int[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
		}
	max_sum(a,n);
	}
return 0;
}
