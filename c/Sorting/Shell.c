#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

void display(int *a, int n){
printf("\n");
for(int i=0; i<n; i++){
	printf("%d ",a[i]);
	}
printf("\n");
}

void shellsort(int *a,int n){
int inner,outer;
int vti;
int interval=1;
int elements=n;
int i=0;
while(interval<elements/3){
	interval=interval*3+1;
	}

while(interval>0){
	for(outer=interval; outer<elements; outer++){
		vti=a[outer];
		inner=outer;
		while(inner > interval-1 && a[inner-interval] >= vti){
			a[inner]=a[inner-interval];
			inner=inner-interval;
			}
		a[inner]=vti;
		}
	interval=(interval-1)/3;
	i++;
	}
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
display(a,n);
shellsort(a,n);
display(a,n);
end = clock();
cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
printf("\n Time taken by Sort is %lf\n",cpu_time_used);
return 0;
}
