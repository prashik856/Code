#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
int gfg[]={5,6,7,7,6,5,8,8};
vector <int> g(gfg,gfg+8);
//sort(g.begin(),g.end());
for(int i=0; i<g.size() ; i++){
	cout << g[i] << " ";
	}
cout << endl;
vector <int> ::iterator lower,upper;
lower = lower_bound (g.begin(),g.end(),6);
upper = upper_bound (g.begin(),g.end(),6);
cout << "lower_bound for 6 at position " << (lower-g.begin()) << endl;
cout << "upper_bound for 6 at position " << (upper-g.begin()) << endl;
return 0;
}
