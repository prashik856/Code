#include<iostream>
#include<vector>
using namespace std;
int main(){
vector <int> g1;
vector <int> g2;
vector <int> g3;
g1.assign(5,10);
vector <int> :: iterator it;
it=g1.begin()+1;
g2.assign(it,g1.end()-1);
//Assigning using an array
int gquiz[]={1,2,3};
g3.assign(gquiz,gquiz+2);

for(int i=0; i<g1.size(); i++){
	cout << g1[i] << " " << endl;
	}
cout << endl;
for(int i=0; i<g2.size(); i++){
	cout << g2[i] << " " << endl;
	}
cout << endl;
for(int i=0; i<g3.size(); i++){
	cout << g3[i] << " " << endl;
	}
return 0;
}
