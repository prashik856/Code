#include<iostream>
using namespace std;

void printboard(int **board,int n){
	cout << endl;
	for(int i=0; i<n; i++){
		for(int j=0 ;j<n; j++){
			cout << board[i][j] << " ";
			}
		cout << endl;
		}
	cout << endl;
	}

bool check(int **board,int n,int curc,int curr){
	//check left
	for(int j=curc-1; j>=0; j--){
		if(board[curr][j]==1) {
			return false;
			}
		}
	
	//upper left
	for(int i=curr+1,j=curc-1; j>=0 && i<n; j--,i++){
		if(board[i][j]==1){
			return false;
			}
		}

	//lower left
	for(int i=curr-1,j=curc-1; j>=0 && i>=0; j--,i--){
		if(board[i][j]==1){
			return false;
			}
		}
	return true;
	}

bool solveit(int **board, int n,int col){
	if(col>=n) return true;
	for(int i=0; i<n; i++){
		if(check(board,n,col,i)){
			board[i][col]=1;
			if(solveit(board,n,col+1)) return true;
			board[i][col]=0; //backtrack;
			}
		}
	return false;
	}

bool putqueens(int **board,int n){
	//Making a recursive function
	if(solveit(board,n,0))return true;
	return false;
	}

int main(){
clock_t begin = clock();
int t;
cin >> t;
for(int z=0; z<t; z++){
	int n;
	cin >> n;
	int **board;
	board=new int*[n];
	for(int i=0; i<n; i++) board[i]=new int[n];
	
	//Initializing
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			board[i][j]=0;
			}
		}
	if(putqueens(board,n)){
		cout << endl << "The solution exists" ;
		printboard(board,n);
		}
	else{
		cout << endl << "The solution does not exist";
		}
	//cout << endl << "The board is " << endl;
	//printboard(board,n);
	cout << endl;
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
