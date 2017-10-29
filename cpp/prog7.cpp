//Constant objects
#include<iostream>
#include<string>
using namespace std;
class myclass{
public:
 void myprint() const{
	cout << "Hello const" << endl;
	}
};

int main(){
const myclass obj;
obj.myprint();
myclass obj2;
obj2.myprint();
return 0;
}
