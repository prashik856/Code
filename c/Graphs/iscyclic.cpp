#include<iostream>
#define MAX 50
#include<vector>
#include<stack>
using namespace std;

void addedge( vector < vector <int> >& al, int from ,int to){
	al[from].push_back(to);
}

int gan(vector <vector <int> >& al,vector <bool> visited,int temp){
	for(int i=0; i<al[temp].size(); i++){
		if(visited[al[temp][i]]==false){
			return al[temp][i];
			}
		}
return -1;
}	

bool iscyclic(vector < vector <int> >& al,vector <bool>& visited){
	for(int i=0; i<al.size(); i++){
		stack <int> s;
		s.push(i);
		while(!s.empty()){
			int temp=s.top();
			int a=gan(al,visited,temp);	
			if(a==i){
				return true;			
				}
			else if(a!=-1){
				s.push(a);
				visited[a]=true;
				}
			else if(a==-1){
				s.pop();
				}
			}
		visited.assign(visited.size(),false);
		}
	return false;
	}

int main(){
int t;
cin >> t;
for(int zo=0; zo<t; zo++){
	int n;
	cin >> n;
	vector < vector <int> > al;
	vector <bool> visited(n,false);
	al.resize(n);
	int m;
	cin >> m;
	for(int i=0; i<m; i++){
		int from,to;
		cin >> from;
		cin >> to;
		addedge(al,from,to);
		}
	//display our adjacent list
	for(int i=0; i<n; i++){
		for(int j=0; j<al[i].size(); j++){
			cout << al[i][j] << " ";
			}
		cout << endl;
		}
	if(iscyclic(al,visited)){
			cout << endl <<  "The Graph is cyclic" << endl;
			}
	else{
		cout << endl << "The Graph is acyclic" << endl;
		}
	}

return 0;
}
