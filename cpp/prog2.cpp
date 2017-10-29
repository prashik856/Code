#include"prog2.h"
#include<iostream> 
#include<string>
using namespace std;

myclass::myclass(string nm){
setname(nm);
}

myclass::setname(string x){
name=x;
}

myclass::getname(){
return name;
}

