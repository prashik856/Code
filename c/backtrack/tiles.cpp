#include<iostream>
using namespace std;
long int score=0;

void display(int *a, int n){
cout << endl;
for(int i=0; i<n; i++){
	cout << a[i] << " ";
	}
cout << endl;
}

int calscore(int *a,int b, int s,int index){
	if(b==1){
		return a[0];
		}	
	if(index==0){
		s=a[index+1];
		}
	if(index==b-1){
		s=a[b-2];
		}
	
	if(index!=0 && index!=b-1){
		s=a[index-1]*a[index+1];
		}
return s;
}

void del(int *a,int b,int index){
int count=0;
for(int i=0; i<b; i++){
	if(i!=index){
		a[count++]=a[i];
		}
	}
}

void rearrange(int *a,int b,int index,int val){
//int count=0;

for(int i=b-1; i>0; i--){
	if(i==index){
		a[index]=val;
		break;	
		}	
	a[i]=a[i-1];
	}
if(index==0){
	a[index]=val;
	}
}

void tiles(int *a,int b,int n, int s, int index){
	if(b==1){
		if(score<s){
		score=s;		
		}
		return;	
		}
	else{	
		for(int i=0; i<b; i++){
			int val,initial_sum;
			index=i;
			val=a[index];
			initial_sum=calscore(a,b,s,index);
			s=s+initial_sum;
			//cout << endl << "sum=" << s << endl;
			del(a,b,index);
			//cout << endl << "After delete" << endl;
			//display(a,b-1);
			tiles(a,b-1,n,s,index);
			//cout << endl << "befor rearrange val= " << val << " and index=" << index << " and b=" << b << endl;
			rearrange(a,b,index,val);//backtrack
			//cout << endl << "After rearrange" << endl;
			//display(a,b);
			s=s-initial_sum; //return to our original value of sum;
			}
		}
}

int main(){
int t;
cin >> t;
for(int zo=0 ; zo<t; zo++){
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
		}
	display(a,n);
	int b=n,s=0,index=0;
	tiles(a,b,n,s,index);
	cout << score << endl;
	//int val=a[index];
	//del(a,b,index);
	//display(a,b-1);
	//cout << b << endl;
	//rearrange(a,b,index,val);
	//display(a,b);
	}
return 0;
}
