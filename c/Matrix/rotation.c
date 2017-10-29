#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void display(int **mat, int row, int col){
printf("\n");
for(int i=0; i<row; i++){
	for(int j=0; j<col; j++){
		printf("%d ",mat[i][j]);
		}
	printf("\n");
	}

printf("\n");
}

void rotate(int **mat,int row,int col){
int minr=0,minc=0,maxr=row,maxc=col;

int count=0;
while(count<row*col){
	
	//Towards right
	for(int i=minr,j=minc; j<maxc ; j++){
		printf("%d ",mat[i][j]);
		count++;
		}
	
	minr++; //done with a row

	//count value
	printf("\n%d\n",count);

	//down
	for(int j=maxc-1,i=minr; i<maxr; i++){
		printf("%d ",mat[i][j]);
		count++;
			}
	maxc--;

	//count value
	printf("\n %d \n",count);

	//going left
	for(int i=maxr-1,j=maxc-1; j>=minc ; j--){
		printf("%d ",mat[i][j]);
		count++;	
			}
	maxr--;
	
	printf("\n %d \n",count);
	
	//going up
	for(int j=minc,i=maxr-1; i>=minr; i--){
		printf("%d ",mat[i][j]);
		count++;
			}
	minc++;
	printf("\n %d \n",count);
	
	}

}

int main(){
int row,col;
scanf("%d %d",&row,&col);
int **mat;
mat=(int **)malloc(row*sizeof(int *));
for(int i=0; i<row;i++){
mat[i]=(int *)malloc(col*sizeof(int));
	}

for(int i=0; i<row; i++){
	for(int j=0; j<col; j++){
		scanf("%d",&mat[i][j]);
		}
	}

display(mat,row,col);

rotate(mat,row,col);

return 0;
}
