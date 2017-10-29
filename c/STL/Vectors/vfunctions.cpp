#include<iostream>
#include<vector>
using namespace std;
int main(){
vector <int> g;
for(int i=0; i<10; i++){
	g.push_back(i);
	}
cout << g.size() << " Returns number of elements "<< endl;
cout << g.capacity() << " Size of the storage space currently allocated " << endl;
cout << g.max_size() << " Max number of elements " << endl;
cout << g.empty() << " Returns whether empty "<< endl;
return 0;
}
