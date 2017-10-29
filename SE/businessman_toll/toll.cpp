#include<iostream>
using namespace std;

int money=99999999;

void solve(int **rate,int n, int cc,int cm,int cfc,int *qual){
	if(cc==n){
		money=min(money,cm);
		return;
		}
	else{
		if(cfc>0){

			}

		else{
			solve(rate,n,cc+1,cm+rate[cc][1],cfc,qual);
			//buy fruits once
			qual[cc]=qual[cc]+rate[cc][0];
			cm=cm+rate[cc][1]*2;
			solve(rate,n,cc+1,cm,cfc+qual[cc],qual);
			//twice			
			qual[cc]=qual[cc]+rate[cc][0];
			cm=cm+rate[cc][1]*2;
			solve(rate,n,cc+1,cm,cfc+qual[cc],qual);
			//thrice
			
			}
		}
	}

void toll(int **rate,int n){
	int *qual;
	qual=new int[n]();	
	int cc=0;
	int cm=0;
	int cfc=0;
	solve(rate,n,cc,cm,cfc,qual);
	}

int main(){
clock_t begin = clock();
//Input is no of test cases. For each test case we have number of cities, and for each city we have quantity and tax values
int t;
cin >> t;
for(int z=0; z<t; z++){
	int n;
	cin >> n;
	int **rate;
	rate=new int*[n];
	for(int i=0; i<n; i++){
		rate[i]=new int[2];
		}	
	for(int i=0;i<n; i++){
		cin >> rate[i][0] >> rate[i][1];
		}
	toll(rate,n);
	cout << money << endl;
	money=0;
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
