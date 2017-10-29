#include<iostream>
#include<vector>
using namespace std;

int lcs(string a, string b){
int la=a.length();
int lb=b.length();
int **L;
L=new int*[la+1];
for(int i=0; i<=la; i++){
	L[i]=new int[lb+1];
	}
for(int i=la ;i>=0; i--){
	for(int j=lb; j>=0 ; j--){
		if(a[i]=='\0' || b[j]=='\0'){
			L[i][j]=0;
			}
		else if(a[i]==b[j]){
			L[i][j]=1+L[i+1][j+1];
			}
		else{
			L[i][j]=max(L[i+1][j],L[i][j+1]);
			}
		}	
	}
vector <char> s;
int i=0,j=0;
while(i<la && j<lb){
	if(a[i]==b[j]){
		s.push_back(a[i]);
		i++;j++;
		}
	else if(L[i+1][j]>=L[i][j+1]){
		i++;		
		}
	else j++;
	}
cout << endl << "The subsequence is ->";
for(int i=0 ; i<s.size(); i++){
	cout << s[i];
	}
cout << "<-" << endl;
return L[0][0];
}

int main(){
clock_t begin = clock();

string a,b;
getline(cin,a);
getline(cin,b);
int l=lcs(a,b);
cout << endl << "The max length of sub is " << l << endl;

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
