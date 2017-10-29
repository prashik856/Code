#include<iostream>
using namespace std;


int subproblem(string a, string b, int i, int j){
	if(a[i]=='\0' || b[j]=='\0'){
		return 0;
		}
	else if(a[i]==b[j]){
		return 1+subproblem(a,b,i+1,j+1);
		}
	else{
		return max(subproblem(a,b,i+1,j),subproblem(a,b,i,j+1));
		}
	}

int lcs_string(string a, string b){
int c=subproblem(a,b,0,0);
return c;
}


int main(){
clock_t begin = clock();

string a;
string b;
getline(cin,a);
getline(cin,b);
cout << endl << "Input strings are" << endl;
cout << endl << a << endl << b << endl;
int f=lcs_string(a,b);
cout << endl << "Max length of substring is " << f << endl;

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
