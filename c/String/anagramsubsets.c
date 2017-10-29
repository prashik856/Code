#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>

int *hash;
int sizemax;

void initialize(){
sizemax=pow(2,100);
hash=(int *)calloc(sizemax,sizeof(int));
}

void display(char *s){
printf("\n");
printf("%s",s);
printf("\n");
}

void merge(char *s,int low,int mid,int high){
//printf("\nin merge\n");
int l1,l2;
int i;
char *b;
b=(char*)malloc(150*sizeof(char));
for(l1=low,l2=mid+1,i=low;l1<=mid && l2<=high;i++){
	if(s[l1]<=s[l2]){
		b[i]=s[l1++];
		}
	else{
		b[i]=s[l2++];
		}
	}
while(l1<=mid){
		b[i++]=s[l1++];
		}

while(l2<=high){
		b[i++]=s[l2++];
		}

for(int i=low; i<=high; i++){
	s[i]=b[i];
	}
}

void mergesort(char *s,int low,int high){
//printf("\nin mergesort\n");
int mid;
if(low<high){
	mid=(low+high)/2;
	mergesort(s,low,mid);
	mergesort(s,mid+1,high);
	merge(s,low,mid,high);
	}
else{
	return;
	}
}

int hashkey(char *b){
int l=strlen(b);
//printf("\n%d\n",l);
int key=0;
for(int i=0; i<l; i++){
	key=key+b[i]*(i+1);
	}
return key;
}

void subsets(char *s){
printf("\n");
int l=strlen(s);
int size=pow(2,l);
char *b;
b=(char*)malloc(150*sizeof(char));
int count=0;
int key;
int index;
for(int counter=1; counter<size; counter++){
	for(int j=0; j<l; j++){
		if(counter & 1<<j){
			b[count++]=s[j];
			}
		}
		b[count]='\0';
		printf("\n%s\n",b);
		key=hashkey(b);
		index=key%sizemax;
		hash[index]=hash[index]+1;
		count=0;
	}

int count2=0;
for(int i=0; i<sizemax; i++){
	if(hash[index]>1){
		count2=count2+(hash[index]*(hash[index]-1))/2;
		}
	}
printf("\n Max subsets are %d\n",count2);
}

int main(){
clock_t start,end;
double cpu_time_used;
start = clock();

char *s;
s=(char*)malloc(150*sizeof(char));
scanf("%s",s);
display(s);
int low=0;
int high=strlen(s)-1;
//printf("\ninmain\n");
mergesort(s,low,high);
display(s);
subsets(s);

end = clock();
cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
printf("\nTime taken by Code is %lf\n",cpu_time_used);
return 0;
}
