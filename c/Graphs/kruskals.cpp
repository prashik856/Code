#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

void addedge(vector < vector <int> >& al,int from,int to){
al[from].push_back(to);
}

int gaun(vector < vector <int> >& al, vector <bool>& visited,int temp){
	for(int i=0; i<al[temp].size(); i++){
		if(visited[al[temp][i]]==false){
			return al[temp][i];
			}
		}
return -1;
}

bool iscyclic(vector < vector <int> >& al, vector <bool>& visited){
	for(int i=0; i<al.size() ; i++){
		stack <int> s;
		s.push(i);
		while(!s.empty()){
			int temp=s.top();
			int a=gaun(al,visited,temp);
			if(a==i){
				return true;
				}
			else if(a!=-1){
				visited[a]=true;
				s.push(a);
				}
			else if(a==-1){
				s.pop();
				}
			}
		visited.assign(al.size(),false);
		}
return false;
}

int main(){
int n;
cin >> n;
vector < vector <int> > al;
//vector < vector <int> > al2;
al.resize(n);
//al2.resize(n);
vector <bool> visited;
visited.assign(n,false);
int m;
cin >> m;
vector < vector <int> > edges;
edges.resize(m);
for(int i=0; i<m; i++){
	int from,to,weight;
	cin >> from;
	cin >> to;
	cin >> weight;
	edges[i].push_back(weight);
	edges[i].push_back(from);
	edges[i].push_back(to);
	}
sort(edges.begin(),edges.end());

for(int i=0; i<m; i++){
	for(int j=0; j<edges[i].size(); j++){
		cout << edges[i][j] << " ";
		}
	cout << endl;
	}


//We have our sorted edges
int count=0;
cout << endl << "Our Graph is " << endl;
for(int i=0; i<m && count<n-1; i++){
	addedge(al,edges[i][1],edges[i][2]);
	if(iscyclic(al,visited)){
		al[edges[i][1]].erase(al[edges[i][1]].end());
		}
	else{
		cout << edges[i][1] << "->" << edges[i][2] << " W:" << edges[i][0]<< "\t";
		count++;
		}
	}
cout << endl;
return 0;
}
