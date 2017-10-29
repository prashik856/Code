#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include<math.h>

void display(char *s){
int l=strlen(s);
printf("\n");
printf("%s",s);
printf("\n");
}

void displaycount(int *count){
printf("\n");
for(int i=0; i<26; i++){
	printf("%d ",count[i]);
	}
printf("\n");
}

void maxalter(char *s){
int l=strlen(s);
int *count;
count=(int *)calloc(26,sizeof(int));
for(int i=0; i<l; i++){
	int a=s[i];
	count[a-97]++;
	}
//displaycount(count);

int **pairs;
pairs=(int **)malloc(516*sizeof(int*));
for(int i=0; i<516; i++){
	pairs[i]=(int *)malloc(2*sizeof(int));
	}
int count1=0;
for(int i=0; i<26; i++){
	for(int j=i+1; j<26; j++){
		if( count[i]>0 && count[j]>0 && (abs(count[i]-count[j])==0 || abs(count[i]-count[j])==1) ){
			pairs[count1][0]=97+i;
			pairs[count1][1]=97+j;
			count1++;
			}
		}
	}

//printf("\nPossible pairs are=%d\n",count1);

int max=0;
int count2=0;
for(int j=0; j<count1; j++){
	for(int i=0; i<l; i++){
		int a=0;
		int b=s[i];
		int index=i;
		if(b==pairs[j][a]){
			while(i<l){
				if((int)s[i]==pairs[j][a]){
					count2++;
					a=1-a;
					//i++;
					}
				
				else if((int)s[i]==pairs[j][1-a]){
					count2=0;
					break;
					}
				i++;
				}
			}
		
		else if(b==pairs[j][1-a]){
			while(i<l){
				if((int)s[i]==pairs[j][1-a]){
					count2++;
					a=1-a;
					}

				else if((int)s[i]==pairs[j][a]){
					count2=0;
					break;
					}
				i++;
				}
			}
		if(max<=count2){
			max=count2;
			}
		count2=0;
		}
	}
printf("\nMax_alter=%d\n",max);

}

int main(){
clock_t start,end;
double cpu_time_used;
start = clock();
int t;
scanf("%d",&t);
for(int i=0; i<t; i++){
	char *s;
	s=(char*)malloc(100000*sizeof(char));
	scanf("%s",s);
	//display(s);
	maxalter(s);
	}

end = clock();
cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
printf("\nTime taken by Code is %lf\n",cpu_time_used);
return 0;
}
