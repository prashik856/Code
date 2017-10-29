#include <iostream>
#define MAX 1000
using namespace std;

struct node{
int data;
bool visited;
};

struct node *listnode[MAX];
int vc=0;

int *stac;
int sptr=0;
int sic=0;

void initialize(){
    stac=new int[MAX];
}

void insertnode(int data){
struct node *p=new struct node;
p->data=data;
p->visited=false;
listnode[vc++]=p;
}

void addedge(int **am, int n,int from, int to){
am[from][to]=1;
am[to][from]=1;
}

void push(int data){
stac[sptr++]=data;
sic++;
}

void pop(){
sptr--;
sic--;
}

bool ise(){
return sic==0;
}

int gaun(int **am, int n, int v){
for(int i=0; i<n; i++){
    if(listnode[i]->visited==false && am[v][i]!=0){
        return i;
    }
}
return -1;
}

bool dfs(int **am,int n,int src){
listnode[src]->visited=true;
push(src);
while(!ise()){
    int temp=stac[sptr-1];
    int data=listnode[temp]->data;
    if(data==3){
        return true;
    }
    int a=gaun(am,n,temp);
    if(a!=-1){
	listnode[a]->visited=true;
        push(a);
    }
    else{
        pop();
    }

}
//if node not found, make all the inputs as unvisited
for(int i=0; i<vc; i++){
    listnode[i]->visited=false;
}
return false;
}

int main()
{
    //cout << "Hello world!" << endl;
    int t;
    cin >> t;
    for(int z=0; z<t; z++){
        initialize();
        int h,w;
        cin >> h >> w;
        
	int **arr;
        arr=new int*[h];
        for(int i=0; i<h; i++){
            arr[i]=new int[w];
        }

        //defining our adjacent matrix
        int **am;
        am=new int*[h*w];
        for(int i=0; i<h*w; i++){
            am[i]=new int[h*w]();
        }

        //Now taking the input and forming the graph
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin >> arr[i][j];
                insertnode(arr[i][j]);
                if(j>0 && arr[i][j-1]!=0){
                        addedge(am,h*w,w*i+j-1,w*i+j);
                }
            }
        }
	
	
	//Check our input and adjacent matrix
	cout << endl;	
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			cout << arr[i][j] << " ";
			}
		cout << endl;
		}
	cout << endl;
	
	//Checking our adjacent matrix
	for(int i=0; i<h*w; i++){
		for(int j=0 ;j<h*w; j++){
			cout << am[i][j] << " ";
			}
		cout << endl;
		}
	cout << endl;
	
	//Our adjacent matrix is fine	
		
        int count=1;
        bool a=false;
        while(!a){
            for(int j=0; j<w; j++){
                for(int i=0; i<h; i++){
                    if((i+count)<h){
			if(arr[i][j]!=0 && arr[i+count][j]!=0) addedge(am,h*w,w*(i+count)+j,w*i+j); 
                    }
                }
            }
            a=dfs(am,h*w,w*(h-1));
            count++;
        }
        cout << "The level of Rock is " << count-1 << endl;

        //dfs(am,h*w,w*(h-1));

        vc=0;
	sptr=0;
	sic=0;

    }
    return 0;
}
