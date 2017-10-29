#include<iostream>
#include<vector>
using namespace std;

bool checkoutput(int **arr, int **out , int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(arr[i][j]!=out[i][j]) return false;
			}
		}	
	return true;
	}

void rotatearray(vector < int >& arr, int r){
	//here r is smaller than arr.size()
	int count=r;
	while(count>0){
		int temp=arr[0];
		for(int i=0; i<arr.size()-1; i++){
			arr[i]=arr[i+1];
			}
		arr[arr.size()-1]=temp;
		count--;
		}
	}

void rotate(int **arr,int n,int r){
	int minr=0,minc=0,maxr=n,maxc=n;
	int count=0;
	vector < int > temp;
	while(count<n*n){
		//towards right
		for(int i=minc; i<maxc; i++){
			temp.push_back(arr[minr][i]);
			count++;
			}
		minr++;
		
		//downwards
		for(int i=minr; i<maxr; i++){
			temp.push_back(arr[i][maxc-1]);
			count++;
			}
		maxc--;

		//left
		for(int i=maxc-1; i>=minc; i--){
			temp.push_back(arr[maxr-1][i]);
			count++;
			}
		maxr--;

		//up
		for(int i=maxr-1; i>=minr; i--){
			temp.push_back(arr[i][minc]);
			count++;
			}
		minc++;
		
		//one rotation finished
		int r1=r;
		r1=r%temp.size();
		
		//cout << endl ;
		//cout << "Before rotating" << endl;
		//for(int i=0; i<temp.size(); i++) cout << temp[i] << " ";
		//cout << endl ;		
		
		//r1 is the actual number of rotations we have to do an our array temp
		
		rotatearray(temp,r1);
		
		//cout << endl ;
		//cout << "After rotating" << endl;
		//for(int i=0; i<temp.size(); i++) cout << temp[i] << " ";
		//cout << endl ;
		
		//Got our r times rotated array;
		//put them in our original matrix;
		int tminr=minr-1,tminc=minc-1,tmaxr=maxr+1,tmaxc=maxc+1;
		int index=0;
		
		for(int i=tminc; i<tmaxc; i++){
			//temp.push_back(arr[minr][i]);
			arr[tminr][i]=temp[index];
			//count++;
			index++;
			}
		tminr++;		
		
		//downwards
		for(int i=tminr; i<tmaxr; i++){
			//temp.push_back(arr[i][maxc-1]);
			//count++;
			arr[i][tmaxc-1]=temp[index];
			index++;
			}
		tmaxc--;
		
		//left
		for(int i=tmaxc-1; i>=tminc; i--){
			//temp.push_back(arr[maxr-1][i]);
			//count++;
			arr[tmaxr-1][i]=temp[index];
			index++;
			}
		tmaxr--;

		//up
		for(int i=tmaxr-1; i>=tminr; i--){
			//temp.push_back(arr[i][minc]);
			arr[i][tminc]=temp[index];
			index++;
			}
		tminc++;
		
		temp.clear();
		}
	}

void printmatrix(int **arr,int n){
	cout << endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << arr[i][j] << " ";
			}
		cout << endl;
		}
	cout << endl;
	}

int main(){
clock_t begin = clock();

int t;
cin >> t;
for(int z=0; z<t; z++){
	cout << endl << "#" << z << " Iteration" ;
	int n;	
	cin >> n;
	int **arr;
	int **out;
	arr=new int*[n];
	out= new int*[n];
	for(int i=0; i<n; i++) {
		arr[i]=new int[n];
		out[i]=new int[n];
		} 
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i][j];
			}
		}
	int r;
	cin >> r;
	//cout << endl << "Our input matrix is " << endl;
	//printmatrix(arr,n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> out[i][j];
			}	
		}
	/*vector < int > hell;
	for(int i=1; i<10; i++) hell.push_back(i);
	rotatearray(hell,2);
	cout << endl ;
	for(int i=0; i<hell.size(); i++) cout << hell[i] << " ";
	cout << endl;
	*/
	//cout << "Our required output matrix is " << endl;
	//printmatrix(out,n);
	rotate(arr,n,r);
	//cout << "My output is " << endl;
	//printmatrix(arr,n);
	if(checkoutput(arr,out,n)) cout << endl << "Your answer is correct" << endl;
	else cout << endl << "Incorrect answer asshole, try again" << endl;
	cout << endl << endl ;
	}

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
