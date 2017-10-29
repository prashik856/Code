#include<iostream>
using namespace std;

int fib(int n){
if(n==1){
	return 1;
	}
if(n==2){
	return 1;
	}
if(n>2){
	int sum=0;
	int temp1=1;
	int temp2=1;
	while(n>2){
		sum=temp1+temp2;
		temp1=temp2;		
		temp2=sum;
		n--;
		}
	return sum;
	}
return -1;
}

int main(){
clock_t begin = clock();

int n;
cin >> n;
int f=fib(n);
cout << endl << n << "th fibonacci number is " << f << endl;

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
