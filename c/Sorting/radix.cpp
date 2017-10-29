#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

void display(int *a, int n){
cout << endl;
for(int i=0; i<n; i++){
	cout << a[i] << " ";
	}
cout << endl;
}

int getmax(int *a,int n){
int max=0;
for(int i=0; i<n; i++){
	if(a[i]>max){
		max=a[i];	
		}
	}
return max;
}

void radix(int *a, int n){
int b=10;
int d=1;
vector < vector <int> > c;
c.resize(10);
int max=getmax(a,n);

while((max/b)>0){
	for(int i=0; i<n ; i++){
		int temp=a[i]%b;
		temp=temp/d;
		cout << endl << temp << endl;
		c[temp].push_back(a[i]);
		}
	int count=0;
	for(int i=0; i<c.size(); i++){
		sort(c[i].begin(),c[i].end());
		}
	for(int i=0; i<c.size(); i++){
		for(int j=0; j<c[i].size(); j++){
			a[count++]=c[i][j];
			//c[i].erase(c[i].begin()+j);
			}
			//c.erase(c.begin()+i);
		}
	b=b*10;
	d=d*10;
	display(a,n);
	c.resize(10);
	}
}

int main(){
clock_t begin = clock();

int n;
cin >> n;
int *a;
a=new int[n];
for(int i=0; i<n;i++){
	cin >> a[i];
	}
display(a,n);
radix(a,n);
display(a,n);

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
