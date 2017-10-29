#include<iostream>
#define INF 99999999
using namespace std;

int mint=INF;

void solve(int d,int h,int **fuel,int cd,int ch, int ct){
	
	if(ch>h){
		return;
		}	
	
	if(cd==d){
		if(ct<mint){
			mint=ct;
			}
		}
		
	for(int i=0; i<5; i++){
		cd=cd+1;
		ch=ch+fuel[i][1];
		ct=ct+fuel[i][0];
		solve(d,h,fuel,cd,ch,ct);
		cd=cd-1;
		ch=ch-fuel[i][1];
		ct=ct-fuel[i][0];
		}
	}

void gogogo(int d,int h, int **fuel){
	int cd=0;
	int ch=0;
	int ct=0;
	solve(d,h,fuel,cd,ch,ct);
	}

int main(){
clock_t begin = clock();
int t;
cin >> t;
for(int z=0; z<t; z++){
	int d,h;
	cin >> h >> d;
	int **fuel;
	fuel=new int*[5];
	for(int i=0; i<5; i++){
		fuel[i]=new int[2];
		}
	for(int i=0; i<5; i++){
		int a,b,c;
		cin >> a >> b >> c;
		int time=a*60+b;
		fuel[i][0]=time;
		fuel[i][1]=c;
		}
	//got our inputs
	gogogo(d,h,fuel);
	cout << "#" << z << endl;
	if(mint==INF){
		cout << "-1" << endl;
		}
	else{
		cout << mint/60 << " " << mint%60 << endl;
		}
	
	mint=INF;
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
