#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
int score=0;

int *rearrange(int *a, int n){
int b[n-1];
int i;
int count=0;
for(i=0; i<n; i++){
	if(a[i]!=0){
	b[count]=0;
	count++;
	}
}
return b;
}

void calscore(int *a , int n,int s){
	
	if(n==0){
		if(s>score){
	   	  score=s;
		}
	return;
	}
	
	int b[n];
	
	for(int i=0; i<n; i++){
		b[i]=a[i];
		}
	
	for(int i=0; i<n; i++){
		b[i]=0;
		if(i==0){
		   s=s+b[i+1];
		}
	
		if(i==n-1){
		   s=s+b[i-1];
		}
	
		if(i!=0 && i!=n-1){
		   s=s+b[i-1]*a[i+1];
		}
		int *c=rearrange(b,n);
		calscore(b,n-i+1, s);
	}

}

int main(){
int t;
scanf("%d",&t);
int a0;
for(a0=0; a0<t ; a0++){
	int n;
	scanf("%d",&n);
	int i;
	int a[n];
	printf("\n TC=%d\n",a0);
	for(i=0; i<n ; i++){
		scanf("%d",&a[i]);
		printf(" %d ",a[i]);
		}
	
	calscore(a,n,0);
	
	printf("\n");
	}

return 0;
}
