#include<iostream>
using namespace std;

long long int a=0;
int permute(string s,int c, int l){
	if(c==l-1){
		a++;
		//cout << s << endl;
		}
	else{
		for(int i=c; i<l ; i++){
			char t=s[i];
			s[i]=s[c];
			s[c]=t;
			permute(s,c+1,l);
			t=s[i];
			s[i]=s[c];
			s[c]=t;
			}
		}
	}

int main(){
clock_t begin = clock();
int t;
cin >> t;
for(int z=0; z<t; z++){
	string s;
	cin >> s;
	permute(s,0,s.length());
	cout << endl << a;
	cout << endl << endl << z << "th finished" << endl;

	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
