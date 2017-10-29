#include<stdio.h>
#define getName(var) #var
int main(){
int myvar;
printf("%s",getName(myVar));
return 0;
}
