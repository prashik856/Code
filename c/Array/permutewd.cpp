#include<iostream>
using namespace std;

int x=1;
int findceil(string s, char first, int l, int h){
	int ceilindex=l;
	for(int i=l+1; i<h; i++){
		if(s[i]>first && s[i]<s[ceilindex]) ceilindex=i;
		}
	return ceilindex;
	}

void sort(string s,int start,int finish){
	for(int i=start; i<finish; i++){
		for(int j=i+1; j<=finish; j++){
			if(s[i]>s[j]){
				char t=s[i];
				s[i]=s[j];
				s[j]=t;
				}
			}
		}
	}

void permute(string s){
	int size=s.length();
	sort(s,0,size);
	bool isFinished=false;
	while(!isFinished){
		cout << endl << x++ << "->" << s;
		int i;	
		for(i=size-2; i>=0; i--){
			if(s[i]<s[i+1]) break;
			}
		if(i==-1) isFinished=true; //No such character exist
		else{
			int ceilindex=findceil(s,s[i],i+1,size);
			char t=s[i];
			s[i]=s[ceilindex];
			s[ceilindex]=t;
			sort(s,i+1,size-i-1);
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
	permute(s);
	cout << endl << z << "th Finished" << " and it has " << x-1 << " combinations."<< endl ;
	x=1;
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
