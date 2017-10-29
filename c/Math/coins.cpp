#include<iostream>
using namespace std;
long int money=0;

void max_money(int n){
	int x2,x3,x4;
	x2=n/2;
	x3=n/3;
	x4=n/4;
	if(x2+x3+x4>n){
		max_money(x2);
		max_money(x3);
		max_money(x4);
		}
	else{
		money=money+n;	
		}
	}

int main(){
clock_t begin = clock();

int t;
cin >> t;
for(int z=0; z<t; z++){
	int n;
	cin >> n;
	max_money(n);
	cout << endl << money << endl;
	money=0;
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
