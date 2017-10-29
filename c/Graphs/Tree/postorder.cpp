#include<iostream>
using namespace std;

struct node{
int data;
struct node *lc;
struct node *rc;
};

struct node *root=NULL;

void insert(int data){
	struct node *p=new struct node;
	p->data=data;
	if(root==NULL){
		root=p;	
		}

	else{
		struct node *temp=root;
		int flag=0;	
		while(flag==0){
			if(data <= temp->data){
				if(temp->lc==NULL){
					temp->lc=p; flag=1;
					}
				else {	temp=temp->lc;} 
				}
			else{
				if(temp->rc==NULL) {temp->rc=p; flag=1;}
				else temp=temp->rc;
				}
			}
		}
	}

void postorder(struct node *temp){
	if(temp!=NULL){
		postorder(temp->lc);
		postorder(temp->rc);
		cout << temp->data << " ";
		}
	else{
		return;
		}
	}

int main(){
clock_t begin = clock();

int n;
cin >> n;
for(int i=0; i<n; i++){
	int j;
	cin >> j;
	//cout << j << " ";
	insert(j);
	}
//cout << endl;
postorder(root);

clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
