#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX 1000000

//defining our global variables
struct node{
int data;
bool visited;
};
struct node **listnode;
int vc=0,time=0;

void insertn(int data){
struct node *p=(struct node*)malloc(sizeof(struct node));
p->data=data;
p->visited=false;
listnode[vc]=p;
vc++;
}

int main(){
int t;
scanf("%d",&t);
int a0;
for(a0=0; a0<t; a0++){
	int n,m;
	scanf("%d %d",&n,&m);
	int a_r,a_c;
	scanf("%d %d",&a_r,&a_c);
	int p=n*(a_r-1)+(a_c-1);
	int i,j;
	int **a=(int **)malloc(n*sizeof(int*));
	for(i=0; i<n; i++){
		a[i]=(int*)malloc(m*sizeof(int));
		for(j=0; j<m; j++){
			scanf("%d",&a[i][j]);
					
		}
	}

	//Display the given grid
       /*	for(i=0; i<n ; i++){
		for(j=0; j<m; j++){
			printf("%d ",a[i][j]);
		}
	printf("\n");
	}
	*/
	
	//Initializing our Adjacent matrix
	int **am=(int **)malloc((n*m)*sizeof(int*));
	for(i=0; i<n*m; i++){
		am[i]=(int*)calloc(n*m,sizeof(int));
	}
	
	//Initializing our listnode matrix
	listnode=(struct node **)malloc((n*m)*sizeof(struct node*));

	//Going throung our matrix
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			
			if(a[i][j]==1 || a[i][j]==2){
				insertn(n*i+j);
				}
			//checking left right up and down for 1
			
		}
	}

time=0;
vc=0;	
}
return 0;
}
