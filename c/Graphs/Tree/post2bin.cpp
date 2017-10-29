#include<iostream>
using namespace std;

struct node{
int data;
struct node* lc;
struct node* rc;
};

struct node *root=NULL;

void insert(int data){
	struct node *p=new struct node;
	p->data=data;
	p->lc=NULL;
	p->rc=NULL;
	if(root==NULL) root=p;
	else{
		struct node *temp=root;
		int flag=0;
		while(flag==0){
			if(data > temp->data){
				if(temp->rc==NULL){
					temp->rc=p;
					flag=1;
					}
				else{temp=temp->rc;}		
				}
			else{
				if(temp->lc==NULL){
					temp->lc=p;
					flag=1;
					}
				else {temp=temp->lc;}
				}
			}
		}
	}

void post(struct node *temp){
	if(temp!=NULL){
		post(temp->lc);
		post(temp->rc);
		cout << temp->data << " ";
		}
	else return;
	}

void post2bin(int *arr,int n){
	for(int i=n-1; i>=0; i--){
		insert(arr[i]);
		}
	post(root);
	}

int main(){
clock_t begin = clock();

int n;
cin >> n;
int arr[n];
for(int i=0; i<n; i++){
	cin >> arr[i];
	}
post2bin(arr,n);

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
