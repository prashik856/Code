#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void sorta(int *a,int m){
    for(int i=0; i<m ; i++){
        for(int j=0; j<m-i-1; j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

int main(){
    int n; 
    int m; 
    scanf("%d %d",&n,&m);
    int *c = malloc(sizeof(int) * m);
    for(int c_i = 0; c_i < m; c_i++){
       scanf("%d",&c[c_i]);
    }
    sorta(c,m);
    int max=0;
    int min=999999;
    int count=0;
    int diff;
    int flag=0;
    printf("Array is sorted\n");
    for(int i=0; i<n; i++){
        printf("%d ",i);
        flag=0;
        while(flag==0){
        
            if(count==0){
                if(i<=c[count]){
                    flag=1;
                    diff=c[count]-i;
                    if(diff>=max){
                        max=diff;
                    }
                }
            }
            
            if(count==m-1){
                if(i>=c[count]){
                    flag=1;
                    diff=i-c[count];
                    if(diff>=max){
                        max=diff;
                    }
                }
            }
            
            if(count>0 && count!=m-1){
                if(i<=c[count] && i>=c[count-1]){
                    flag=1;
                    int d1=c[count]-i;
                    int d2=i-c[count-1];
                    if(d1<=d2){
                        diff=d1;
                    }
                    else{
                        diff=d2;
                    }
                    if(diff>=max){
                        max=diff;
                    }
                }
                else{
                    count++;
                }
            }
        }
    }
    
    printf("%d",max);
    
    return 0;
}

