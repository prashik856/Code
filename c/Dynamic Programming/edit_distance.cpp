#include<iostream>
using namespace std;

int edit_distance(string a, string b){
	int L[a.length()+1][b.length()+1];
	for(int i=0; i<=a.length(); i++){
		for(int j=0; j<=b.length(); j++){
			if(i==0) L[i][j]=j;
			else if(j==0) L[i][j]=i;
			else if(a[i-1] == b[j-1]) L[i][j]=L[i-1][j-1];
			else L[i][j]= 1 + min(min(L[i][j-1],L[i-1][j]),L[i-1][j-1]);
			}		
		}
	return L[a.length()][b.length()];
	}

int main(){
clock_t begin = clock();

int t;
cin >> t;
for(int z=0; z<t; z++){
	string a;
	string b;
	cin >> a >> b;
	int l=edit_distance(a,b);
	cout << endl << l << endl;
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
