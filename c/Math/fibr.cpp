#include<iostream>
using namespace std;

int fib(int n){
	if(n<=1){
		//cout << n << " ";
		return n;
		}
	return fib(n-1)+fib(n-2);
	}

int main(){
clock_t begin = clock();

int n;
cin >> n;
cout << endl;
int f=fib(n);
cout << n << "th fibonachi number is " << f << endl ;

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
