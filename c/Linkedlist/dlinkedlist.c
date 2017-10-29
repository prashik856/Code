#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
int key;
int data;
struct node *next;
struct node *prev;
};

struct node *head=NULL;
struct node *last=NULL;

void insertfirst(int key,int data){
struct node* p=(struct node*)malloc(sizeof(struct node));
p->key=key;
p->data=data;
p->next=NULL;
p->prev=NULL;
//if first
if(head==NULL){
	head=p;
	last=p;
	}
else{
	struct node *temp;
	temp=head;
	p->next=temp;
	temp->prev=p;
	head=p;
	}
}

void deletefirst(){
struct node* temp=head;
head=head->next;
head->prev=NULL;
temp=NULL;
}

void insertlast(int key,int data){
struct node *p=(struct node*)malloc(sizeof(struct node));
p->key=key;
p->data=data;
p->next=NULL;
p->prev=NULL;
if(head==NULL){
	last=p;
	head=p;
	}
else{
	struct node *temp;
	temp=last;
	p->prev=temp;
	temp->next=p;
	last=p;
	}
}

void deletelast(){
struct node *temp;
temp=last;
last=last->prev;
temp->prev=NULL;
last->next=NULL;
}

void displayforward(){
printf("\n");
struct node* temp=head;
while(temp!=NULL){
	printf("(%d,%d)->",temp->key,temp->data);
	temp=temp->next;
	}
printf("end\n");
}

void displaybackward(){
printf("\n");
struct node *temp=last;
while(temp!=NULL){
	printf("(%d,%d)->",temp->key,temp->data);
	temp=temp->prev;
	}
printf("end\n");
}

void insertafter(int sk,int key,int data){
struct node *p=(struct node*)malloc(sizeof(struct node));
p->key=key;
p->data=data;
struct node *temp2,*current;
current=head;
temp2=current->next;
//int flag=0;
while(temp2!=NULL){
	if(current->key==sk){
	//flag=1;
	p->prev=current;
	current->next=p;
	p->next=temp2;
	return;	
	}
	current=current->next;
	temp2=current->next;
	}
//if(flag==0){
	printf("\nNo such key is present in the linked list\n");
//	}
}

void deletekey(int key){

if(head->key==key){
	struct node *p;
	p=head;
	p=p->next;
	p->prev=NULL;
	head->next=NULL;
	head=p;
	return;
	}

if(last->key==key){
	struct node *p;
	p=last;
	p=last->prev;
	p->next=NULL;
	last->prev=NULL;
	last=p;
	return;
	}

struct node *current,*temp2,*temp1;
current=head->next;
temp2=current->next;
temp1=current->prev;
//int flag=0;
while(temp2!=NULL){
	if(current->key==key){
		temp1->next=current->next;
		temp2->prev=current->prev;
		current->next=NULL;
		current->prev=NULL;
		//flag=1;
		return;
		}
	current=current->next;
	temp2=current->next;
	temp1=current->prev;
	}

	printf("\nNo such key found in our linked list\n");
	
}

int main(){
int n;
scanf("%d",&n);
for(int i=0; i<n; i++){
	int key,data;
	scanf("%d %d",&key,&data);
	insertfirst(key,data);
	}
//displayforward();
//displaybackward();
deletefirst();
//displayforward();
int key,data;
scanf("%d %d",&key,&data);
insertlast(key,data);
scanf("%d %d",&key,&data);
insertlast(key,data);
//displayforward();
deletelast();
//displayforward();
int sk;
scanf("%d",&sk);
scanf("%d %d",&key,&data);
insertafter(sk,key,data);
displayforward();
scanf("%d",&key);
deletekey(key);
displayforward();
return 0;
}
