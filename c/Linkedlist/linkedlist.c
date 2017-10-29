#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
int key;
int data;
struct node *next;
};

struct node *head=NULL;

void addfirst(int key,int data){
struct node *p=(struct node*)malloc(sizeof(struct node));
p->key=key;
p->data=data;
p->next=head;
head=p;
}

void display(){
struct node *temp;
temp=head;
printf("\n");
while(temp!=NULL){
	printf("(%d,%d)->",temp->key,temp->data);
	temp=temp->next;
	}
printf("end\n");
}

void deletefirst(){
struct node *temp;
temp=head;
head=temp->next;
temp=NULL;
}

struct node *find(int key){
struct node *temp=head;
while(temp!=NULL){
	if(temp->key==key){
		return temp;		
		}
	temp=temp->next;
	}
return NULL;
}

void deletekey(int key){
struct node *temp=head;
struct node *temp2;
if(temp->key==key){
	temp=head;
	head=temp->next;
	temp=NULL;
	return;
	}
temp2=temp;
temp=temp->next;
int flag=0;
while(temp!=NULL){
	if(temp->key==key){
		temp2->next=temp->next;
		temp=NULL;
		flag=1;
		return;
		}
	temp2=temp;
	temp=temp->next;
	}
printf("\nGiven key not found\n");
}

int length(){
int count=0;
struct node* temp;
temp=head;
while(temp!=NULL){
	count++;
	temp=temp->next;
	}
return count;
}

void sort(){
struct node* current;
struct node* temp;
int tempkey,tempdata;
int l=length();
for(int i=0; i<l-1; i++){
	current=head;
	temp=current->next;
	for(int j=0; j<l-i-1; j++){
		if(current->data > temp->data){
			tempkey=current->key;
			current->key=temp->key;
			temp->key=tempkey;

			tempdata=current->data;
			current->data=temp->data;
			temp->data=tempdata;
			}
		current=temp;
		temp=temp->next;
		}
	}
}

void reverse(){
struct node *current=head;
struct node *prev=NULL;
struct node *next;
while(current!=NULL){
	next=current->next;
	current->next=prev;	
	prev=current;	
	current=next;
	}
head=prev;
}

int main(){
int n;
scanf("%d",&n);
for(int i=0; i<n; i++){
	int k,t;
	scanf("%d %d",&k,&t);
	//printf("%d %d ",t);
	addfirst(k,t);
	}
display();
deletefirst();
display();
int sk;
scanf("%d",&sk);
struct node *p=find(sk);
if(p==NULL){
	printf("\nElement Not found\n");
	}
else{
	printf("\nElement found, (key=%d,data=%d)\n",p->key,p->data);
	}
//addfirst(5,586);
display();
scanf("%d",&sk);
deletekey(sk);
display();
p=find(sk);
if(p==NULL){
	printf("\nElement Not found\n");
	}
else{
	printf("\nElement found, (key=%d,data=%d)\n",p->key,p->data);
	}
int l=length();
printf("\nLength of our linked list is %d\n",l);
sort();
display();
reverse();
display();
return 0;
}
