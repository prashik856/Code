#include<iostream> 
using namespace std;

int uglynum(int n){
if(n==1){
	return 1;
	}
else if(n>1){
	int ucount=1;
	int num=1;
	for(int i=2; ucount<n; i++){
		int temp=i;
		while(temp%2==0){
			temp=temp/2;
			}
		while(temp%3==0){
			temp=temp/3;
			}
		while(temp%5==0){
			temp=temp/5;
			}
		if(temp==1){
			ucount++;
			}
		if(ucount==n){
			num=i;
			}
		}
	return num;
	}

}

int main(){
clock_t begin = clock();

int t;
cin >> t;
for(int z=0; z<t; z++){
	int n;
	cin >> n;
	cout << endl << n << "th ugly number is " << uglynum(n) << endl;
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
