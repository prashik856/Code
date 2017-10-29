#include<iostream>
#include<vector>
using namespace std;
int main(){
vector <int> g;
for(int i=1; i<=10; i++){
	g.push_back(i*2);
	}
g.erase(g.begin()+4);
g.erase(g.begin(),g.begin()+5);
for(int i=0 ;i<g.size(); ++i){
	cout << g[i] << " ";
	}
cout << endl;
return 0;
}
