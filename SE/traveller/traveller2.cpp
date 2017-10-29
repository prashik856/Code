#include<iostream>
using namespace std;

void getcity(float **am, int n, int T){
	int time=T/10;
	
	//Initial prob arr	
	float *prob;
	prob=new float[n]();
	prob[0]=1;
	
	//Final prob array
	float *fprob;
	fprob=new float[n]();

	float max_prob=0;
	int max_index=0;

	for(int i=0; i<time; i++){
		max_prob=0;
		max_index=0;
		// fprob=prob*am
		for(int j=0; j<n; j++){
			float sum=0;
			for(int k=0; k<n; k++){
				sum=sum+prob[k]*am[k][j];
				}
			fprob[j]=sum;
			}
		
		//prob=fprob;
		for(int j=0; j<n; j++){
			prob[j]=fprob[j];
			if(prob[j]>max_prob){
				max_prob=prob[j];
				max_index=j;
				}
			}
		
		
		//displaying our prob array after every iteration
		//cout << endl << "After " << i+1 << " , the prob array is " << endl;
		//for(int j=0; j<n; j++) cout << prob[j] << " ";
		//cout << endl;
		
		//for loop for number of times the person will travel
		}
	
	//We got our final prob and city index here
	cout << max_prob << " " << max_index << endl;
		
	}

int main(){
clock_t begin = clock();
int t;
cin >> t;
for(int z=0; z<t; z++){
	int n;
	cin >> n;
	float **am;
	am=new float*[n];
	for(int i=0; i<n; i++) am[i]=new float[n];
	int m;
	cin >> m;
	for(int i=0; i<m; i++){
		int from,to;
		float prob;
		cin >> from >> to >> prob;
		am[from][to]=prob;
		}
	//our prob matrix is as follows
	cout << endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << am[i][j] << " ";
			}
		cout << endl;
		}
	int T;
	cin >> T;
	cout << endl << "given time is " << T << endl;
	getcity(am,n,T);
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
