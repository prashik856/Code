#include<stdio.h>
void swap(int *a, int from, int to){
int temp;
temp=a[from];
a[from]=a[to];
a[to]=temp;
}
void permute(int *a, int i, int n){
	if(i==n-1){
		for(int j=0; j<n; j++){
			printf("%d ",a[j]);
		}
		printf("\n");
	}
	int j=i;
	for(j=i; j<n; j++){
		swap(a,i,j);
		permute(a,i+1,n);
		swap(a,i,j);
	}
}
int main(){
int n;
scanf("%d",&n);
int a[n];
for(int i=0; i<n; i++){
	scanf("%d",&a[i]);
	}
int i=0;
permute(a,i,n);
return 0;

}
