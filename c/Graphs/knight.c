#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 9999
struct coor{
int row;
int col;
int dist;
};

struct coor **que;
int rear=-1,front=0,qic=0;

void initialize(){
que=(struct coor**)malloc(MAX*sizeof(struct coor*));
}

void pushc(int row, int col, int dist){
struct coor *p=(struct coor*)malloc(sizeof(struct coor));
p->row=row;
p->col=col;
p->dist=dist;
rear++;
que[rear]=p;
qic++;
}

void popc(){
front++;
qic--;
}

bool iqe(){
return qic==0;
}

bool isinside(int row,int col, int n){
if(row>=0 && row<n && col>=0 && col<n){
	return true;
	}
return false;
}

int minstep(int rk, int ck,int rt, int ct, bool** board,int n){
int dr[8]={2,2,-2,-2,-1,1,-1,1};
int dc[8]={-1,1,-1,1,2,2,-2,-2};

//Starting position
board[rk][ck]=true;
pushc(rk,ck,0);

int row,col;//positions
struct coor *t=(struct coor*)malloc(sizeof(struct coor));
//t=que[front];

//printf("\n %d %d %d \n",t->row,t->col,t->dist);
//int flag=0;
//int count=0;
while(!iqe()){
	t=que[front];
	board[t->row][t->col]=true;
	
	if(t->row==rt && t->col==ct){
		return t->dist;
		}

	for(int i=0; i<8 ; i++){
		row=t->row+dr[i];
		col=t->col+dc[i];
		
		if(isinside(row,col,n)){
			if(board[row][col]==false){
				pushc(row,col,t->dist+1);
				//printf("\n%d %d\n",row,col);
				//printf("\n %d \n",count++);
				}
			}
		}
	popc();
	}
	
}

int main(){
int n;
scanf("%d",&n);
initialize();

//Our board for visited coordinates
bool **board;
board=(bool **)malloc(n*sizeof(bool*));

for(int i=0; i<n; i++){
	board[i]=(bool *)malloc(n*sizeof(bool));
	}
for(int i=0; i<n; i++){
	for(int j=0; j<n; j++){
		board[i][j]=false;
		}
	}

//printf("\nAll Initialized\n");

int rk,ck;
scanf("%d %d",&rk,&ck);

int rt,ct;
scanf("%d %d",&rt,&ct);


int min_d=minstep(rk,ck,rt,ct,board,n);
printf("\n%d\n",min_d);

}
