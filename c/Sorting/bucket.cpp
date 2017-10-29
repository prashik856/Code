#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include <ctime>

using namespace std;

void display(float *a,int n){
cout << endl;
for(int i=0; i<n; i++){
	cout << a[i] << " ";
	}
cout << endl;
}

void bucket(float *a, int n){
vector < vector <float> > b;
b.resize(n);
for(int i=0; i<n; i++){
	int c=a[i]*n;
	b[c].push_back(a[i]);
	}

for(int i=0; i<b.size(); i++){
	sort(b[i].begin(),b[i].end());
	}

int count=0;
for(int i=0; i<b.size(); i++){
	for(int j=0; j<b[i].size(); j++){
		a[count++]=b[i][j];
		}
	}

display(a,n);
}

int main(){
clock_t begin = clock();

int n;
cin >> n;
float *a;
a=new float[n];
for(int i=0; i<n; i++){
	cin >> a[i];
	}
//display(a,n);
bucket(a,n);

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;

return 0;
}
