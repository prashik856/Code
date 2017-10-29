#include<iostream> 
#define NIL -1
#define MAX 100
using namespace std;

int lookup[MAX];

void initialize(){
	for(int i=0; i<MAX; i++){
		lookup[i]=NIL;
		}
	}

int fib(int n){
	if(lookup[n]==NIL){
		if(n<=1){
			lookup[n]=n;
			}
		else{
			lookup[n]=fib(n-1)+fib(n-2);
			}
		}	
	return lookup[n];	
	}
	

int main(){
clock_t begin = clock();
initialize();


int n;
cin >> n;
int f=fib(n);
cout << n << "th fibonacci number is " << f << endl;

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
