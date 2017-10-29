#include<iostream>
#include<vector>
using namespace std;
int main(){
vector <int> g1;
vector <int> g2;
vector <int> :: iterator i;
g1.push_back(10);
g1.push_back(20);
g2.push_back(30);
g2.push_back(40);
cout << endl << "before swaping" << endl;
for(i=g1.begin(); i!=g1.end(); i++){
	cout << *i << " ";
	}
cout << endl;
for(i=g2.begin(); i!=g2.end(); i++){
	cout << *i << " ";
	}
cout << endl;

swap(g1,g2);

cout << endl << "After swaping" << endl;

for(i=g1.begin(); i!=g1.end(); i++){
	cout << *i << " ";
	}
cout << endl;
for(i=g2.begin(); i!=g2.end(); i++){
	cout << *i << " ";
	}
cout << endl;

g1.clear();
g1.push_back(1000);
cout << g1.front();
g2.clear();
g2.push_back(0);
cout << endl << g2.front() << endl;

return 0;
}
