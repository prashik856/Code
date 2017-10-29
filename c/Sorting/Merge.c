#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
void merge(int *a, int n, int low, int mid, int high,int *b){
int l1,l2,i;

for(l1=low,l2=mid+1,i=low; l1<=mid && l2<=high; i++){ //Iterate through b via i
	if(a[l1]<=a[l2]){ //if first list is small, then 1st, else 2nd
		b[i]=a[l1++];
		}
	else{
		b[i]=a[l2++];	
		}
	}

//The remaining elements of both list from low to high
while(l1<=mid){
	b[i++]=a[l1++];
	}

while(l2<=high){
	b[i++]=a[l2++];
	}


//Atlast, copy elements from b to a
for(i=low; i<=high ; i++){
	a[i]=b[i];
	}
}

void sort(int *a,int n, int low,int high,int *b){
int mid;
if(low<high){
	mid=(low+high)/2;
	sort(a,n,low,mid,b);
	sort(a,n,mid+1,high,b);
	merge(a,n,low,mid,high,b);
	}
else{
	return;
	}
}

void display(int *a, int n){
printf("\n");
for(int i=0; i<n; i++){
	printf("%d ",a[i]);
	}
printf("\n");
}

int main(){
clock_t start,end;
double cpu_time_used;
start = clock();

int n;
scanf("%d",&n);
int *a;
a=(int *)malloc(n*sizeof(int));
for(int i=0; i<n; i++){
	scanf("%d",&a[i]);
	}
//display(a,n);
int low=0;
int high=n-1; //high is included
int *b;
b=(int *)malloc(n*sizeof(int));

sort(a,n,low,high,b);
display(a,n);

end = clock();
cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
printf("\nTime taken by Sort is %lf\n",cpu_time_used);
return 0;
}
