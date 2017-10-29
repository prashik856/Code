#include<iostream>
using namespace std;

int score=0;

void solve(char **map,int cs,int cr,int cc,int k,int flag){
	if(cc<0 || cc>=5){
		return;
		}
	if(cs<0){
		return;
		}
	if(cr<0){
		score=max(score,cs);
		return;
		}
	
	//Under kadha	
	if(k>0){
		if(map[cr][cc]=='S'){
			cs=cs+1;
			}
		solve(map,cs,cr-1,cc,k-1,flag);
		solve(map,cs,cr-1,cc-1,k-1,flag);
		solve(map,cs,cr-1,cc+1,k-1,flag);
		}
	//Not under kadha
	else{
		if(map[cr][cc]=='S'){
			cs=cs+1;
			}
		else if(map[cr][cc]=='R'){
			cs=cs-1;
			}
		solve(map,cs,cr-1,cc,k,flag);
		solve(map,cs,cr-1,cc-1,k,flag);
		solve(map,cs,cr-1,cc+1,k,flag);

		//backtrack
		if(map[cr][cc]=='S'){
			cs=cs-1;
			}
		else if(map[cr][cc]=='R'){
			cs=cs+1;
			}
		if(flag==0){
			flag=1;
			k=5;
			solve(map,cs,cr,cc,k,flag);
			}
		}
	}

void goback(char **map,int R){
	int cs=0;
	int cr=R;
	int cc=2;
	int k=0; //kadha
	int flag=0; //used kadha or not
	solve(map,cs,cr-1,cc,k,flag);
	solve(map,cs,cr-1,cc-1,k,flag);
	solve(map,cs,cr-1,cc+1,k,flag);
	}

int main(){
clock_t begin = clock();
int t;
cin >> t;
for(int z=0; z<t; z++){
	int R;
	cin >> R;
	char **map;
	map=new char*[R];
	for(int i=0; i<R; i++){
		map[i]=new char[6];
		}
	for(int i=0; i<R; i++){
		cin >> map[i];
		}
	goback(map,R);
	cout << score << endl;
	score=0;
	}


clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
