#include<iostream>
using namespace std;

int main(){
clock_t begin = clock();
float prob=0.5656561;
prob=prob*1000000+0.5 ;
if(prob>=0){
	prob=int(prob);
	}
else{
	prob=int(prob)-1;
	}
prob=prob/1000000;
cout << prob << endl;

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
