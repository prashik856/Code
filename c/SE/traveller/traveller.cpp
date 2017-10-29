#include<iostream>
#define MAX 10000
using namespace std;

int *que1,*que2;
float *que3;
int rear,front,qic;

void initialize(){
	que1=new int[MAX];
	que2=new int[MAX];
	que3=new float[MAX];
	rear=-1;
	front=0;
	qic=0;
	}

void push(int node,int height,float prob){
	rear=(rear+1)%MAX;
	que1[rear]=node;
	que2[rear]=height;
	que3[rear]=prob;
	qic++;
	}

void pop(){
	front=(front+1)%MAX;
	qic--;
	}

void travelbaba(int **am,float **prob,int n,int time){
	int t=time/10;
	int src=0;
	push(0,1,1);
	int count1=1;
	int parent=1;
	int child=0;
	while(count1<t){
		int tempn=que1[front];
		int temph=que2[front];
		float tempp=que3[front];
		for(int i=0; i<n; i++){
			if(am[tempn][i]==1){
				push(i,temph+1,prob[tempn][i]*tempp);
				child++;
				}
			}
		parent--;
		if(parent!=0){
			pop();
			}
		else if(parent==0){
			parent=child;
			child=0;
			count1++;
			pop();
			}
		}
	float max_prob=0;
	int max_index=0;
	if(rear>front){
			for(int i=front ; i<=rear; i++){
			int node=que1[i];
			float p=que3[i];
			for(int j=i+1; j<=rear; j++){
				if(que1[j]==node){
					p=p+que3[j];
					}
				}
			if(p>max_prob){
				max_prob=p;
				max_index=node;
				}
			}
		}
	if(front>rear){
		for(int i=front; i<MAX; i++){
			int node=que1[i];
			float p=que3[i];
			for(int j=i+1; j<MAX; j++){
				if(que1[j]==node){
					p=p+que3[j];
					}
				}
			for(int j=0; j<=rear; j++){
				if(que1[j]==node){
					p=p+que3[j];
					}
				}
			if(p>max_prob){
				max_prob=p;
				max_index=node;
				}
			}
		
		for(int i=0; i<=rear; i++){
			int node=que1[i];
			float p=que3[i];
			for(int j=i+1; j<MAX; j++){
				if(que1[j]==node){
					p=p+que3[j];
					}
				}
			for(int j=0; j<=rear; j++){
				if(que1[j]==node){
					p=p+que3[j];
					}
				}
			if(p>max_prob){
				max_prob=p;
				max_index=node;
				}
			}
		}
	
	cout << endl << "The prob of reaching this node is " << max_prob << " and the traveller is at node " << max_index << endl;
	
	}

int main(){
clock_t begin = clock();

int t;
cin >> t;
for(int z=0; z<t; z++){
	initialize();
	int n;
	cin >> n;
	
	//defining our adjacent matrix and prob matrix
	int **am;
	float **prob;
	prob=new float*[n];
	am=new int*[n];
	for(int i=0; i<n; i++) {
		am[i]=new int[n](); 
		prob[i]=new float[n]();
		}
	
	//taking our input
	int m;
	cin >>m;
	for(int i=0; i<m; i++){
		int from,to;
		float p;
		cin >> from >> to >> p;
		am[from][to]=1;
		prob[from][to]=p;
		}
	
	//displaying our adjacent matrix and prob matrix
	/*cout << endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << am[i][j] << " ";
			}
		cout << endl;
		}
	cout << endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << prob[i][j] << " ";
			}
		cout << endl;
		}
	*/
	int T;
	cin >> T;
	cout << endl << "given time is " << T << endl;
	travelbaba(am,prob,n,T);
	cout << endl << endl;
	}


clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
