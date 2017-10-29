//Does not take care if there are double elements
//If wanna take care, do the following
#include<iostream>
using namespace std;

int a=0;

void comb(char *arr,char *data, int start, int end, int index, int r){
	if(index==r){
		for(int i=0; i<r; i++) cout << data[i];
		cout << endl;
		a++;
		}
	else{
		for(int i=start; i<=end && end-i+1 >= r-index ; i++){
			data[index]=arr[i];
			comb(arr,data,i+1,end,index+1,r);
			while(arr[i]==arr[i+1]) i++; //For removing duplicates
			}
		}
	}

void sortarr(char *arr,int n){
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(arr[i]>arr[j]){
				char t;
				t=arr[j];
				arr[j]=arr[i];
				arr[i]=t;
				}
			}
		}
	}

void print_comb(char *arr,int n,int r){
	char data[r];
	sortarr(arr,n);
	cout << "Given String is sorted as ";
	for(int i=0; i<n; i++) cout << arr[i];
	cout << endl;
	comb(arr,data,0,n-1,0,r);
	}

int main(){
clock_t begin = clock();
int t;
cin >> t;
for(int z=0; z<t; z++){
	int n;
	cin >> n;
	char arr[n];
	cin >> arr;
	cout << arr << endl;
	int r;
	cin >> r;
	cout << endl;
	print_comb(arr,n,r);
	cout << endl << a << " Combinations are possible."<< endl << endl << endl;
	a=0;
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
