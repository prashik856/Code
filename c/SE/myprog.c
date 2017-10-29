#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n,k;
    scanf("%d %d",&n,&k);
    int chap[n];
    for(int i=0; i<n; i++){
        scanf("%d",&chap[i]);
    }
    int page=0;
    int count2=1;
    int count3=0;
    
    //first getting our page number
    for(int i=0; i<n; i++){
        int a=chap[i]/k;
        //a=1
        int b=chap[i]%k;
        //b=1
        page=page+a;
        //page=2
        
        if(b!=0){
            page=page+1;
        }
    }
    //Now we have pages
    int **book;
    book=(int **)malloc(page*sizeof(int*));
    for(int i=0 ;i<page; i++){
        book[i]=(int*)calloc(k,sizeof(int));
    }
    
    count3=0;
    int count4=0;
    
    for(int i=0; i<n; i++){
        count2=1;
        printf("%d ",i);
        while(count2<=chap[i]){
            book[count3][count4]=count2;
            count2++;
            count4++;
            
            if(count4>=k){
                count4=count4%k;
                count3++;
            }
            
            if(count2==chap[i]+1){
                count3++;
                count4=0;
            }
        }
        
    }
     
    //Printing our Array
    for(int i=0; i<page; i++){
        for(int j=0; j<k; j++){
            printf("%d ",book[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

