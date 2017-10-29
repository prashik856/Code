#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
struct km{
int min;
int sec;
int h;
};

struct km **listnode;
int vc=0;
int tm=999999,ts=999999;
void insertn(int min, int sec, int h){
struct km *p=(struct km*)malloc(sizeof(struct km));
p->min=min;
p->sec=sec;
p->h=h;
listnode[vc]=p;
vc++;
}

void backtrack(int H, int D, int dist,int h,int timem, int times,int count){
if(dist<D){
	if(count==1){
		h=h+listnode[dist]->h;
		if(h<=H){
		timem=timem+listnode[dist]->min;
		times=times+listnode[dist]->sec;
		dist++;
		backtrack(H,D,dist,h,timem,times,count)
		}
		count++;
		h=h-listnode[dist]->h;
	}

	if(count==2){

	}

	if(count==3){

	}

	if(count==4){

	}

	if(count==5){

	}

}

}

int main(){
int t;
scanf("%d",&t);
int a0;
for(a0=0; a0<t; a0++){
	int H,D;
	scanf("%d %d",&H, &D);
	int i;
	listnode=(struct node **)malloc(D*sizeof(struct km *));
	for(i=0; i<D; i++){
	int min,sec,h;
	scanf("%d %d %d",&min,&sec,&h);
	insertn(min,sec,h);
	}
	int dist=0,count=1,h=0,timem=0,times=0 ;
	backtrack(H,D,dist,h,timem,times,count)
	vc=0;
	t=0;
	}	
return 0;
}
