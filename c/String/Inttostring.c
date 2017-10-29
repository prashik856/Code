#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
int main(){
int b=799398;
char *a;
a=(char*)malloc(100000*(sizeof(char)));
sprintf(a,"%d",b);
printf("\n%s\n",a);
}
