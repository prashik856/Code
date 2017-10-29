#include<iostream>
using namespace std;

long maxs=0;

long calscore(int *arr,int cl,int index){
	long score=0;
	if(cl==1){
		score=arr[0];
		return score;
		}
	else{
	if(index==0){
		score=arr[1];
		return score;
		}
	else if(index==cl-1){
		score=arr[cl-2];
		return score;
		}
	
	else{
		score=arr[index-1]*arr[index+1];
		return score;
		}
	}
	return score;
	}

void remove(int *arr,int cl,int index){
	for(int i=index; i<cl-1; i++){
		arr[i]=arr[i+1];
		}
	}

void attach(int *arr,int n,int cl,int index,int ival){	
	for(int i=cl-1; i>=index; i--){
		if(i==index){
			arr[i]=ival;
			}
		else{
			arr[i]=arr[i-1];
			}
		}
	}

void solve(int *arr,int n, int cl,long cs){
	if(cl==0){
		if(cs>maxs){
			maxs=cs;
			}
		}
	
	else{
		for(int i=0; i<cl; i++){
			int index=i;
			int ival=arr[index];
			long cals=calscore(arr,cl,index);;
			cs=cs+cals;
			//cout << "orig" << endl;
			//for(int i=0; i<cl; i++){
			//	cout << arr[i] << " ";
			//	}
			//cout << endl;
			remove(arr,cl,index);
			//cout << "removed" << endl;
			//for(int i=0; i<cl-1; i++){
			//	cout << arr[i] << " ";
			//	}
			//cout << endl;
			solve(arr,n,cl-1,cs);
			attach(arr,n,cl,index,ival); //backtrack
			//cout << "attached" << endl;
			//for(int i=0; i<cl; i++){
			//	cout << arr[i] << " ";
			//	}
			//cout << endl;			
			cs=cs-cals; //backtrack;
			}
		}
	}

void shoot(int *arr,int n){
	int cl=n;
	long cs=0;
	solve(arr,n,cl,cs);
	}

int main(){
clock_t begin = clock();
int t;
cin >> t;
for(int z=0; z<t; z++){
	int n;
	cin >> n;
	int *arr;
	arr=new int[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
		}
	shoot(arr,n);
	//int a[4]={1,2,3,4};
	//int index=0;
	//int ival=arr[index];
	//remove(a,4,index);
	//for(int i=0; i<3; i++){
	//	cout << a[i] << " ";
	//	}
	//cout << endl;
	//attach(a,4,4,index,ival);
	//for(int i=0; i<4; i++){
	//	cout << a[i] << " ";
	//	}
	cout << maxs << endl;
	maxs=0;
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
