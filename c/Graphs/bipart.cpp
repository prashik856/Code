#include<iostream>
#include<vector>
#include<queue>
#define MAX 50
using namespace std;

struct node{
int color;
bool visited;
};
struct node *listnode[MAX];
int vc=0;


bool isbipartate(vector < vector < int > >& adj){
	int src=0;
	queue < int > que1;
	queue < int > que2;
	listnode[src]->visited=true;
	listnode[src]->color=1;
	cout << endl << "Node=" << src << '\t' << "Color=" << listnode[src]->color;
	que1.push(src);
	que2.push(listnode[src]->color);
	while(!que1.empty()){
		int temp=que1.front();
		int tempc=que2.front();
		for(int i=0; i<adj[temp].size(); i++){
			int v=adj[temp][i];
			if(listnode[v]->visited==false){
				listnode[v]->visited=true;
				listnode[v]->color=1-tempc;
				cout << endl << "Node=" << v << '\t' << "Color=" << listnode[v]->color;
				que1.push(v);
				que2.push(listnode[v]->color);
				}
			else if(listnode[v]->visited==true && listnode[v]->color==tempc){ 
				cout << endl << "The Visited node is " << v << " and the color here is " << listnode[v]->color << " and the color of its parent is " << tempc << endl; 
				return false;
				}
			}
		que1.pop();
		que2.pop();
		}
	return true;
	}

void insertnode(int v){
	struct node *p=new struct node;
	p->color=-1;
	p->visited=false;
	listnode[vc++]=p;
	}

int main(){
clock_t begin = clock();

int t;
cin >> t;
for(int z=0; z<t; z++){
	cout << endl << "#" << z ;
	int n;
	cin >> n;
	vector < vector < int > > adj;
	adj.resize(n);
	for(int i=0; i<n; i++) insertnode(i);
	int m;
	cin >> m;
	for(int i=0; i<m; i++){
		int from,to;
		cin >> from >> to;
		adj[from].push_back(to);
		adj[to].push_back(from);
		}
	cout << endl << "Our Adjacent list is as follows" << endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<adj[i].size(); j++){
			cout << adj[i][j] << " ";
			}
		cout << endl;
		}
	cout << endl;
	if(isbipartate(adj)) cout << endl << "The Graph is bipartate" << endl;
	else cout << endl << "the Graph is not bipartate" << endl;
	vc=0;
	cout << endl << endl;
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
