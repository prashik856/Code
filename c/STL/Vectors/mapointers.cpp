#include<iostream>
using namespace std;

void display(int **p,int row,int col){
cout << endl;
for(int i=0; i<row; i++){
	for(int j=0; j<col ; j++){
		cout << p[i][j] << " ";
		}
	cout << endl;
	}
cout << endl;
}

int main(){
int **p;
int row,col;
cin >> row >> col ;
p= new int*[row];
for(int i=0 ; i<row ; i++){
	p[i]=new int[col];
	}
for(int i=0; i<row; i++){
	for(int j=0; j<col ;j++){
		cin >> p[i][j];
		}
	}
display(p,row,col);
return 0;
}
