#include<iostream>
#include<vector>
using namespace std;
int main(){
vector <int> g(3,10);
vector <int> ::iterator it;
it=g.begin();
it=g.insert(it,20);
g.insert(it,5,30);
it=g.begin();
vector <int> g2(2,40);
g.insert(it+2,g2.begin(),g2.end());
int gq[]={50,60,70};
g.insert(g.begin(), gq,gq+3);
cout << "g contains = " ;
for(it=g.begin(); it<g.end(); it++){
	cout << *it << ' ';
	}
cout << endl;
return 0;
}
