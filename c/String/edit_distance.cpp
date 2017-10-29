#include<iostream>
using namespace std;

int edit_distance(string a, string b,int n,int m){
	if(n==0) return m;
	if(m==0) return n;
	if(a[n-1]==b[m-1]) return edit_distance(a,b,n-1,m-1);
	return 1+min( min( edit_distance(a,b,n,m-1)  //Insert
	 , edit_distance(a,b,n-1,m) //Remove 
	) , edit_distance(a,b,n-1,m-1) ); //Replace
	}

int main(){
clock_t begin = clock();

int t;
cin >> t;
for(int z=0; z<t; z++){
	string a,b;
	cin >> a;
	cin >> b;
	cout << endl << edit_distance(a,b,a.length(),b.length()) << endl;
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
