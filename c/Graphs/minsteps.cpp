#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int mstep=999999;

bool isinside(int x,int y){
	if(x>=0 && y>=0 && x<8 && y<8){
		return true;
		}
	return false;
	}

void getpositions(int **pos,int n,int m,int rk,int ck){
	pos[0][0]=rk+2; pos[0][1]=ck+1;
	pos[1][0]=rk+2; pos[1][1]=ck-1;
	pos[2][0]=rk-2; pos[2][1]=ck+1;
	pos[3][0]=rk-2; pos[3][1]=ck-1;
	pos[4][0]=rk+1; pos[4][1]=ck+2;
	pos[5][0]=rk+1; pos[5][1]=ck-2;
	pos[6][0]=rk-1; pos[6][1]=ck+2;
	pos[7][0]=rk-1; pos[7][1]=ck-2;
	}

void minsteps(int rk,int ck,int rd, int cd,bool **visited,int **count){
	queue < int > que1;
	queue < int > que2;
	queue < int > que3;
	int count1=0;
	que1.push(rk);
	que2.push(ck);
	que3.push(count1);
	count[rk][ck]=0;
	visited[rk][ck]=true;
	while(!que1.empty()){
		int tempr=que1.front();
		int tempc=que2.front();
		int tcount=que3.front();
		if(tempr==rd && tempc==cd){
			if(tcount<mstep) mstep=tcount;
			}

		//definining and getting our positions
		int **pos;
		pos=new int*[8];
		for(int i=0; i<8; i++){
			pos[i]=new int[2];
			}
		getpositions(pos,8,2,tempr,tempc); //got our positions
		
		for(int i=0; i<8; i++){
			if(isinside(pos[i][0],pos[i][1])){
				if(visited[pos[i][0]][pos[i][1]]==false){
					que1.push(pos[i][0]);
					que2.push(pos[i][1]);
					que3.push(tcount+1);
					visited[pos[i][0]][pos[i][1]]=true;
					count[pos[i][0]][pos[i][1]]=tcount+1;
					}
				else if(visited[pos[i][0]][pos[i][1]]==true){
					if(tcount+1<count[pos[i][0]][pos[i][1]]){
						que1.push(pos[i][0]);
						que2.push(pos[i][1]);
						que3.push(tcount+1);
						count[pos[i][0]][pos[i][1]]=tcount+1;
						}
					}
				
				}
			}
		que1.pop();
		que2.pop();
		que3.pop();
		}
	}	

int main(){
clock_t begin = clock();

int t;
cin >> t;
for(int z=0; z<t; z++){
	bool **visited;
	int **count;
	visited=new bool*[8];
	count=new int*[8];
	for(int i=0; i<8; i++) {
		visited[i]=new bool[8];
		count[i]=new int[8];
		}
	//Initializing Count to 0 and visited to false
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			count[i][j]=0;
			visited[i][j]=false;
			}
		}
	int rk,ck;
	cin >> rk >> ck;
	int rd,cd;
	cin >> rd >> cd;
	minsteps(rk,ck,rd,cd,visited,count);
	cout << endl << "The minimum steps required to reach dest by knight is : " << mstep;
	cout << endl;
	mstep=999999;
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
