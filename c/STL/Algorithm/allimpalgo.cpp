#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

void display(vector <int> arr){
cout << endl;
for(int i=0; i<arr.size(); i++){
	cout << arr[i] << " ";
	}
cout << endl;
}

int main(){
int n;
cin >> n;
//int *a;
//a=new int[n];
vector <int> arr;
arr.resize(n);
for(int i=0; i<n; i++){
	cin >> arr[i];
	}

display(arr);
sort(arr.begin(),arr.end());
cout << endl << "sort:" << endl;
display(arr);
cout << endl << "reverse:" << endl;
reverse(arr.begin(),arr.end());
display(arr);
int max,min;
max=*max_element(arr.begin(),arr.end());
min=*min_element(arr.begin(),arr.end());
cout << endl << "max is:" << max << endl << "min is" << min << endl;
int sum=0;
sum=accumulate(arr.begin(),arr.end(),sum);
cout << endl << "sum is:" << sum << endl ;
int count2;
int element;
cin >> element;
count2=count(arr.begin(),arr.end(),element);
cout << endl << element << " has occured " << count2 << " times in our array" << endl;
int fe;
cin >> fe;
if(find(arr.begin(),arr.end(),fe)!=arr.end()){
	cout << endl << fe << " Element found " << endl;
	}
else{
	cout << endl << fe << " Element not found" << endl;
	}
cin >> fe;
if(find(arr.begin(),arr.end(),fe)!=arr.end()){
	cout << endl << fe << " Element found " << endl;
	}
else{
	cout << endl << fe << " Element not found" << endl;
	}
cin >> element;
arr.erase(arr.begin()+element);
display(arr);
arr.erase(unique(arr.begin(),arr.end()),arr.end());
display(arr);
next_permutation(arr.begin(),arr.end());
display(arr);
next_permutation(arr.begin(),arr.end());
display(arr);
prev_permutation(arr.begin(),arr.end());
display(arr);
return 0;
}
