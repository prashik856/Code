#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
int main(){
int *a;
a=(int *)malloc(10*sizeof(int));
vector <int> g;
for(int i=0; i<10; i++){
	g.push_back(i*10);
	}
for(int i=0; i<10; i++){
	cout << g[i] << " ";
	}
cout << endl;
cout << "g.front()="<< g.front() << endl;
cout << "g.back()=" << g.back() << endl;
cout << "g.at(i)=" << g.at(2) << endl;
return 0;
}
