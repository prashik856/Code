#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
char *s;
s=(char*)malloc(200000*sizeof(char));
scanf("%[^\n]s",s);
int a=atoi(s);
printf("\n%d\n",a);
char *ptr;
long int b=strtol(s,&ptr,10);
printf("\n%li\n",b);
}
