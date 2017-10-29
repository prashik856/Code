#include<iostream>
using namespace std;

int fib(int n){
int f[n+1];
f[0]=0;
f[1]=1;
for(int i=2 ; i<=n ; i++){
	f[i]=f[i-1]+f[i-2];
	}
return f[n];
}

int main(){
clock_t begin = clock();

int n;
cin >> n;
int f=fib(n);
cout << n << "th fibonacci number is " << f << endl;

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
