#include<iostream>
using namespace std;

int secondstep(string a, string b, int **L,int i, int j){
	if(L[i][j]==-1){
		if(a[i]=='\0' || b[j]=='\0'){
			L[i][j]=0;
			}
		else if(a[i]==b[j]){
			L[i][j]=1+secondstep(a,b,L,i+1,j+1);
			}
		else{
			L[i][j]=max(secondstep(a,b,L,i+1,j),secondstep(a,b,L,i,j+1));		
			}
		}
		return L[i][j]; 
	}

void lcs(string a, string b){
int **L;
int la=a.length();
int lb=a.length();
int m=max(la,lb);
L=new int*[m+1];
for(int i=0; i<m+1 ; i++){
	L[i]=new int[m+1];
	for(int j=0; j<=m; j++){
		L[i][j]=-1;
		}
	}
int i=0,j=0;
int l=0;
l=secondstep(a,b,L,i,j);
cout << endl << "max string length is " << l << endl;
}

int main(){
clock_t begin = clock();

string a,b;
getline(cin,a);
getline(cin,b);
cout << endl << "Input strings are:" << endl << a << endl << b << endl;
lcs(a,b);

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
