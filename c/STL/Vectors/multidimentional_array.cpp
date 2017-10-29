#include<iostream>
#include<vector>
using namespace std;

void display(vector < vector <int> > array2d){
int row=array2d.size();
int col=array2d[0].size();
cout << endl;
for(int i=0; i<row; i++){
	for(int j=0; j<col; j++){
		cout << array2d[i][j] << " ";
		}
	cout << endl;
	}
cout << endl;
}

int main(){
vector < vector <int> > array2d;
int row,col;
cin >> row;
cin >> col;
array2d.resize(row);

for(int i=0; i<row; i++){
	array2d[i].resize(col);
	}

for(int i=0; i<row; i++){
	for(int j=0; j<col; j++){
		cin >> array2d[i][j];
		}
	}
int a=array2d.size();
int b=array2d[0].size();
cout << a << " " << b  << " " << endl;
display(array2d);
}
