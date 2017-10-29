#include<iostream>
using namespace std;

int getmin(int *mk,int k){
	int min=9999999;
	for(int i=0; i<k; i++){
		if(mk[i]<min){
			min=mk[i];
			}
		}
	return min;
	}

int superuglynum(int n, int *p, int k){
	int *sugly;
	sugly=new int[n];
	sugly[0]=1;	
	int *ik;
	ik=new int[k];
	int *mk;
	mk=new int[k];
	//Initializing them
	for(int i=0; i<k; i++){
		ik[i]=0;
		mk[i]=p[i];
		}
	int nun=1;
	for(int i=1; i<n; i++){
		nun=getmin(mk,k);
		sugly[i]=nun;
		for(int j=0; j<k; j++){
			if(nun==mk[j]){
				ik[j]++;
				mk[j]=sugly[ik[j]]*p[j];
				}		
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
	int k;
	cin >> k;
	int *p;
	p=new int[k];
	for(int i=0; i<k; i++){
		cin >> p[i];
		}
	int l=superuglynum(n,p,k);
	cout << endl << n << "th superugly number for the given prime array is " << l << endl;
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
