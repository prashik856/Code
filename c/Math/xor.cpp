#include<iostream>
using namespace std;

int findbitreverse(int x,int p1,int p2,int n){
	int s1=1,s2=1;
	s1=s1<<p1;
	s2=s2<<p2;
	//cout << endl << s1 << endl << s2 << endl;
	int s11=s1,s22=s2;
	int i=n;
	int count=1;
	while(i>1){
		s1=s1 | (s11<<count);
		s2=s2 | (s22<<count);
		i--;
		count++;
		}
	//cout << endl << s1 << endl << s2 << endl;
	s1=s1 & x; //Got our first three bits
	s2=s2 & x; // Got our second three bits
	count=x;
	count=count ^ s1;
	count=count ^ s2;
	cout << endl << count << endl;
	s1=s1<<(p2-p1);
	s2=s2>>(p2-p1);
	int result=s1 | s2;
	result=result | count;
	return result;
	}

int findsum(int a,int b){
	int sum;
	int carry;
	while(b!=0){
		carry=a&b;		
		a=a^b;
		b=carry<<1;
		}
	return a;
	}

void findmissingnumbers(int *arr,int n){
	int t=0;
	for(int i=0; i<n; i++){
		t=t^arr[i];
		}
	int setbit= t & ~(t-1);
	int x1=0,x2=0;
	for(int i=0; i<n; i++){
		if(arr[i] & setbit) x1=x1^arr[i];
		else x2=x2^arr[i];
		}
	cout << endl << "The two numbers missing are " << x1 << " and " << x2;
	}

int findmissingxor(int *arr,int n){
	int x1=0;
	int x2=0;
	for(int i=1; i<=n; i++){
		x1=x1^i;
		}
	for(int j=0; j<n-1 ; j++){
		x2=x2^arr[j];
		}
	return x1^x2;
	}

int findmissingsum(int *arr,int n){
	int t=0;
	int sum=(n*(n+1))/2;
	for(int i=0; i<n-1; i++){
		t=t+arr[i];
		}
	int num=sum-t;
	return num;
	}

int findodd(int *arr,int n){
	int t=0;
	for(int i=0; i<n; i++){
		t=t^arr[i];
		}
	return t;
	}

int main(){
clock_t begin = clock();

//Single element in a double array
int n;
cin >> n;
int arr[n];
for(int i=0; i<n; i++){
	cin >> arr[i];
	cout << arr[i] << " ";
	}
int a=findodd(arr,n);
cout << endl << "The missing number is " << a ;
cout << endl;

//missing element in the series of n natural numbers
int N;
cin >> N;
int arr2[N-1];
for(int i=0; i<N-1; i++){
	cin >> arr2[i]; cout << arr2[i] << " ";
	} 
cout << endl;

a=findmissingsum(arr2,N);
cout << endl << "The missing number using sum is " << a;
a=findmissingxor(arr2,N);
cout << endl << "The missing number using xor is " << a;
cout << endl;

//Two single numbers in an array of double elements
cin >> n;
int arr3[n];
for(int i=0; i<n; i++){
	cin >> arr3[i]; cout << arr3[i] << " ";
	}
//int b;
findmissingnumbers(arr3,n);

//Add two numbers without arithmatic operations
int x1,x2;
cin >> x1 >> x2;
a=findsum(x1,x2);
cout << endl << "The sum of the two numbers is " << a ;

//Change the bit positions
int x;
cin >> x;
int p1,p2;
cin >> p1 >> p2;
cin >> n;
a=findbitreverse(x,p1,p2,n);
cout << endl << "The reversed number is " << a ;

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
