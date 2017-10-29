#include<iostream>
using namespace std;

template<class T>
void fun(T a){
cout << "The main template of fun() "<< a << endl;
}

template<>
void fun(int a){
cout << "The specialized template for int in fun() " << a << endl;
}


int main(){
fun<char>('b');
fun<int>(10);
fun<float>(1939.32);
return 0;
}
