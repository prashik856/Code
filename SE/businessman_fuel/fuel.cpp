#include<iostream>
#define INF 9999999
using namespace std;

int T=INF;

void solve(int H,int D, int *time,int *h,int ct,int ch,int cd){
	if(ch>H){
		return;
		}
	else if(ch<=H && cd==D){
		if(ct<T){
			T=ct;
			}
		return;
		}
	else{
		for(int i=0; i<5; i++){
			ch=ch+h[i];
			ct=ct+time[i];
			solve(H,D,time,h,ct,ch,cd+1);
			ch=ch-h[i];		//backtrack
			ct=ct-time[i];		//backtrack
			}
		
		}
	}

void getmintime(int H,int D,int *time,int *h){
	int ct=0;
	int ch=0;
	int cd=0;
	solve(H,D,time,h,ct,ch,cd);
	//T=INF;
	}

int main(){
clock_t begin = clock();

//no of test cases
//for each test case, heat bearing capacity and distance is given
//next 5 lines,speed in terms of time required in minutes and seconds for each kilometer and heating impact per kilometer
//is given for 5 diff fuels
//lpg
//cng
//petrol
//diesel
//hydrogen
int t;
cin >> t;
for(int z=0; z<t; z++){
	int H,D;
	cin >> H >> D;
	int *time;
	int *h;
	time=new int[5]();
	h=new int[5]();
	for(int i=0; i<5; i++){
		int a,b,c;
		cin >> a >> b;
		a=a*60;
		b=b+a;
		time[i]=b;
		cin >> c;
		h[i]=c;
		}
	
	cout << endl;
	cout << "Given max heat and distance to travel is " << H << " " << D << endl;
	//cout << "Given time and heating effect per km for fuels is " << endl;
	//for(int i=0; i<5; i++){
	//	cout << time[i] << " " << h[i] << endl;
	//	}
	getmintime(H,D,time,h);
	cout << endl;
	cout << "#" << z << endl;
	if(T==INF){
		cout << "-1" << endl;
		}	
	else{
		int a=T/60;
		int b=T%60;
		cout << a << " " << b << endl;
		}
	
	T=INF;
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
