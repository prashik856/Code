#include<iostream>
using namespace std;

void display(int *a, int n){
cout << endl;
for(int i=0; i<n; i++){
	cout << a[i] << " ";
	}
cout << endl;
}

void heapify(int *a, int n, int i){
int largest=i;
int l=2*i+1;
int r=2*i+2;
if(l<n && a[l]>a[largest]){
	largest=l;
	}
if(r<n && a[r]>a[largest]){
	largest=r;
	}

if(largest!=i){
	int temp=a[i];
	a[i]=a[largest];
	a[largest]=temp;
	heapify(a,n,largest);
	}
}

int main(){
clock_t begin = clock();

int n;
cin >> n;
int *a;
a=new int[n];
for(int i=0; i<n; i++){
	cin >> a[i];
	}
//display(a,n);
for(int i=(n/2)-1 ; i>=0; i--){
	heapify(a,n,i);
	}
for(int i=n-1; i>=0; i--){
	int temp=a[i];
	a[i]=a[0];
	a[0]=temp;
	heapify(a,i,0);
	}
display(a,n);


clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
