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
int t;
cin >> t;
for(int z=0; z<t; z++){
	int n;
	cin >> n;
	max_money(n);
	cout << money << endl;
	money=0;
	}
return 0;
}
