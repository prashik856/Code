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
p->lc=NULL;
p->rc=NULL;
if(root==NULL){
	root=p;
	}
else{
	struct node *parent=root;
	int flag=0;
	while(flag==0){
		if(data > parent->data){
			if(parent->rc == NULL){
				parent->rc=p;
				flag=1;
				}
			else{
				parent=parent->rc;
				}
			}
		if(data <= parent->data){
			if(parent->lc == NULL){
				parent->lc=p;
				flag=1;
				}
			else{
				parent=parent->lc;
				}
			}
		}
	//parent=p;
	}
}

bool search(int data){
struct node *p=root;
while(p!=NULL){
	//cout << endl << p->data << endl;
	if(p->data == data){
		return true;
		}
	if(data < p->data){
		p=p->lc;
		}
	else if(data > p->data){
		p=p->rc;
		}
	}
return false;
}

void inorder(struct node *p){
	if(p==NULL){
		return;
		}
	else{
		inorder(p->lc);
		cout << p->data << " ";
		inorder(p->rc);
		}
}

void preorder(struct node *p){
	if(p==NULL){
		return;	
		}
	
	else{
		cout << p->data << " ";
		preorder(p->lc);
		preorder(p->rc);
		}
}

void postorder(struct node *p){
	if(p==NULL){
		return;	
		}
	
	else{
		postorder(p->lc);
		postorder(p->rc);
		cout << p->data << " ";
		}
}

void balance(struct node *c, struct node *p){
	if(c==NULL){
		return;	
		}
	
	else{	
		//Check for Left rotation
		if( (p->rc != NULL) && (p->lc == NULL) && (p->rc->rc != NULL) && (p->rc->lc == NULL) ){
			struct node *temp=p->rc;
			p->rc=NULL;
			temp->lc=p;
			}
		
		//Check for Right rotation
		else if( (p->lc != NULL) && (p->rc==NULL) && (p->lc->lc!=NULL) && (p->lc->rc==NULL) ){
			struct node *temp=p->lc;
			p->lc=NULL;
			temp->rc=p;
			}

		//Check for Left-Right Rotation
		else if( (p->lc != NULL) && (p->rc==NULL) && (p->lc->rc!=NULL) && (p->lc->lc==NULL) ){
			struct node *temp=p->lc->rc;
			p->lc->rc=NULL;
			temp->lc=p->lc;
			p->lc=temp;
			temp=p->lc;
			p->lc=NULL;
			temp->rc=p;
			}
		//Check for Right-Left Rotation
		else if( (p->rc != NULL) && (p->lc == NULL) && (p->rc->lc != NULL) && (p->rc->rc ==NULL) ){
			struct node *temp=p->rc->lc;
			p->rc->lc=NULL;
			temp->rc=p->rc;			
			p->rc=temp;
			temp=p->rc;
			p->rc=NULL;
			temp->lc=p;
			}
		}
		balance(p->lc);
		balance(p->rc);
}

int main(){
int n;
cin >> n;
for(int i=0; i<n; i++){
	int t;
	cin >> t;
	insert(t);
	};

cout << endl << "#Searching" << endl;

cin >> n;
cout << endl << "Searching " << n << " in our tree" << endl;
if(search(n)){
	cout << endl << "Element is present in the tree" << endl;
	}
else{
	cout << endl << "Element not found" << endl;
	}

cout << endl << "Searching another element" << endl;
cin >> n;
cout << endl << "Searching " << n << " in our tree" << endl;
if(search(n)){
	cout << endl << "Element is present in the tree" << endl;
	}
else{
	cout << endl << "Element not found" << endl;
	}

cout << endl << "\"Done with insertion and searching\"" << endl;

cout << endl << "#Traversing" << endl;

cout << endl << "1.Inorder" << endl;
struct node *p=root;
inorder(p);
cout << endl;

cout << endl << "2.Preorder" << endl;
p=root;
preorder(p);
cout << endl;

cout << endl << "3.Postorder" << endl;
p=root;
postorder(p);
cout << endl;

cout << endl << "\"Done with Traversing\"" << endl;

struct node *c=NULL;
p=root;
balance(p,c);
cout << endl << "\" Done with AVL Trees \"" << endl;

p=root;

inorder(p);
cout << endl;
return 0;
}
