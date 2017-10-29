#include<iostream>
using namespace std;

long long int score=0;

void display(int *arr,int l){
	cout << endl;
	for(int i=0; i<l; i++) cout << arr[i] << " ";
	cout << endl;
	}

long long int calscore(int *arr, int cl, int index){
	if(index==0){
		return arr[index+1];
		}
	else if(index==cl-1){
		return arr[cl-2];
		}
	else{
		return arr[index-1]*arr[index+1];
		}
	}

void removeelement(int *arr,int cl, int index){
	//int temp=arr[index+1];
	for(int i=index; i<cl-1; i++){
		arr[i]=arr[i+1];
		}
	}

void addelement(int *arr, int cl, int element, int index){
	int temp=arr[index];
	int temp2;	
	for(int i=index+1; i<cl ; i++){
		temp2=arr[i];
		arr[i]=temp;
		temp=temp2;
		}
	arr[index]=element;
	}

void getscore(int *arr,int n, int cl,long long int cs){
	if(cl==1){
		cs=cs+arr[0];
		if(score<cs){
			score=cs;
			}
		}
	else{
		for(int i=0; i<cl ; i++){
			long long int temp=calscore(arr,cl,i);
			cs=cs+temp;
			//remove the element from our array
			int element=arr[i];
			int index=i;
			removeelement(arr,cl,i);
			//display(arr,cl-1);
			getscore(arr,n,cl-1,cs);
			cs=cs-temp;
			addelement(arr,cl,element,index); //backtrack to our initial array
			//display(arr,cl);
			}
		}
	}

void shooting(int *arr,int n){
	int cl=n;
	long long int cs=0;
	getscore(arr,n,cl,cs);
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
	//int cl=n;
	//long long int cs=0;
	shooting(arr,n);
	
	//check our array restoring functions
	/*cout << endl << "Initial array" << endl;
	for(int i=0; i<n; i++) cout << arr[i] << " ";
	cout << endl;
	int index=3;
	int element=arr[index];
	removeelement(arr,n,index);
	for(int i=0; i<n-1; i++) cout << arr[i] << " ";
	cout << endl;
	addelement(arr,n,element,index);
	for(int i=0; i<n; i++) cout << arr[i] << " ";
	cout << endl;
	*/
	//They are working well
	cout << score << endl;
	score=0;
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
