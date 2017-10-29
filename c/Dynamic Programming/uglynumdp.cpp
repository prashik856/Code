#include<iostream>
using namespace std;

int uglynum(int n){
	int *ugly;
	ugly=new int[n];
	ugly[0]=1;
	int i2=0,i3=0,i5=0;
	int nmo2=ugly[i2]*2;
	int nmo3=ugly[i3]*3;
	int nmo5=ugly[i5]*5;
	int nun=1;
	for(int i=1; i<n; i++){
		nun=min(nmo2,min(nmo3,nmo5));
		ugly[i]=nun;
		if(nun == nmo2){
			i2++;	
			nmo2=ugly[i2]*2;
			}
		if(nun == nmo3){
			i3++;
			nmo3=ugly[i3]*3;
			}
		if(nun == nmo5){
			i5++;
			nmo5=ugly[i5]*5;
			}
		}
	return nun;
	}

int main(){
clock_t begin = clock();

int t;
cin >> t;
for(int z=0; z<t; z++){
	int n;
	cin >> n;
	int l=uglynum(n);
	cout << endl << n << "th ulgy number is " << l << endl;
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
