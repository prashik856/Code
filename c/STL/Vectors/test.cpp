#include<iostream>
#include<vector>
using namespace std;
int main(){
//Direct defined
vector <int> g(10,0);
cout << "before modification\n";
for(int i=0;i<g.size(); i++){
	cout << g[i] << " " ;
	}
cout << endl;
cout << "after modification\n";
for(int i=0; i<g.size(); i++){
	g[i]=i;
	cout << g[i] << " ";
	}
cout << endl;

cout << "For strings" << endl;

string a;
a="Hello there";
cout << a << endl;
cout << a[0] << " " << a[2] << endl;
int l=a.length();
cout << l << endl;

string c;
getline(cin,c);
cout << c << endl;
cout << c[0] << endl;
//gets(d);
//cout << d << endl;
return 0;
}
