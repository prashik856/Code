#include<iostream>
#include<vector>
using namespace std;
int main(){
vector <int> g;
g.push_back(50);
g.push_back(199);
cout << g[0] << endl;
cout << g[1] << endl;
g.pop_back();
cout << "after pop\n"<< g[0] << endl;
int sum=0;
g.push_back(83);
while(!g.empty()){
	sum +=g.back();
	g.pop_back();
	}
cout << "\n value of sum is " << sum << endl;
return 0;
}
