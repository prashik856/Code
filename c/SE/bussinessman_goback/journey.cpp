#include<iostream>
using namespace std;

int T=-1;

void solve(char **path,int h,int k,int cc,int ri, int ci, int flag){
	if(ri<0){
		if(cc>T){
			T=cc;
			}
		return;
		}
	if(ci<0 || ci>=5){
			return;
			}
	if(cc<0){
		return;
		}

	if(k!=0){
			if(path[ri][ci]=='S'){
				cc=cc+1;
				}
			solve(path,h,k-1,cc,ri-1,ci,flag);
			solve(path,h,k-1,cc,ri-1,ci-1,flag);
			solve(path,h,k-1,cc,ri-1,ci+1,flag);
		}
	else if(k==0){
			if(path[ri][ci]=='S'){
				cc++;
				}
			else if(path[ri][ci]=='R'){
				cc--;
				}
			solve(path,h,k,cc,ri-1,ci,flag);
			solve(path,h,k,cc,ri-1,ci+1,flag);
			solve(path,h,k,cc,ri-1,ci-1,flag);
			if(path[ri][ci]=='S'){
				cc--;
				}
			else if(path[ri][ci]=='R'){
				cc++;
				}
			if(path[ri][ci]=='R' && flag==0){
				flag=1;
				k=5;
				solve(path,h,k,cc,ri,ci,flag);
				}
		}
	}

void getmin(char **path,int h){
	int k=0;
	int cc=0;
	int ri=h-1;
	int ci=2;
	int flag=0;
	//cout << "HERE" << endl;
	solve(path,h,k,cc,ri,ci,flag);
	solve(path,h,k,cc,ri,ci-1,flag);
	solve(path,h,k,cc,ri,ci+1,flag);	
	}

int main(){
clock_t begin = clock();

int t;
cin >> t;
for(int z=0; z<t ;z++){
	int h;
	cin >> h;
	
	//defined our path matrix	
	char **path;
	path=new char*[h];
	for(int i=0; i<h; i++){
		path[i]=new char[6];
		}
	
	//taking input from our path matrix
	for(int i=0; i<h; i++){
		for(int j=0; j<5; j++){
			cin >> path[i][j];
			}
		}

	cout << endl;
	//Showing our path matrix
	for(int i=0; i<h; i++){
		for(int j=0; j<5; j++){
			//char a=path[i][j];
			cout << path[i][j];
			}
	cout << endl;
		}
	cout << endl;
	getmin(path,h);
	cout << endl << "MAX Score is " << T << endl;
	T=0;
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
