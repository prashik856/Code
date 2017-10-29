#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
struct node{
int Q;
int T;
};

struct node **listnode;
int vc;
int money=99999999;


void insertn(int Q, int T){
struct node *p=(struct node*)malloc(sizeof(struct node));
p->Q=Q;
p->T=T;
listnode[vc]=p;
vc++;
}

int paytax(int m,int f,int i){
	if(i==vc){
		if(m<money){
		money=m;
		}
	return m,f,i+1;
	}

	if(i!=vc){
		m=m+listnode[i]->T;
		i++;
		//printf("%d ",m);
		return m,f,i;
	}

}

int main(){
int t;
scanf("%d",&t);
int a0;
for(a0=0; a0<t; a0++){
	int n;
	scanf("%d",&n);
	int i;
	//Initializing our listnode
	listnode=(struct node **)malloc(n*sizeof(struct node*));
	
	//Getting our Q and T for every city
	for(i=0; i<n; i++){
		int Q,T;
		scanf("%d %d",&Q,&T);
		insertn(Q,T);
	}
	
	int m=0,f=0;
	i=0;
	//printf("%d \n",vc);
	
	while(i<=vc){
		m,f,i=paytax(m,f,i);
		m=m+0;
		f=f+0;
		i=i+0;	
		printf("%d %d %d",m,f,i);
		}
	printf("%d",money);
vc=0;
}
return 0;
}
