#include<iostream>
using namespace std;

void getpac(float **am,int n,int T){
	int time=T/10;
	float *prob,*temp;
	prob=new float[n]();
	temp=new float[n]();
	prob[0]=1;
	for(int i=0; i<time; i++){
		for(int j=0; j<n; j++){
			float sum=0;
			for(int k=0; k<n; k++){
				sum=sum+prob[k]*am[k][j];
				}
			temp[j]=sum;
			}
		for(int j=0; j<n; j++){
			prob[j]=temp[j];
			}
		}
	int city;
	float maxprob=0;
	for(int i=0; i<n; i++){
		if(prob[i]>maxprob){
			maxprob=prob[i];
			city=i;
			}
		}
	cout << city << " with prob " << maxprob << endl;
	}

int main(){
clock_t begin = clock();
int t;
cin >> t;
for(int z=0; z<t; z++){
	int n;
	cin >> n;	
	int m;
	cin >> m;

	//get prob matrix itself
	float **am;
	am=new float*[n];
	for(int i=0; i<n; i++){
		am[i]=new float[n]();
		}
	
	for(int i=0;i<m ;i++){
		int from,to;
		float p;
		cin >> from >> to >> p;
		am[from][to]=p;
		}	
	int T;
	cin >> T;
	
	getpac(am,n,T);
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
