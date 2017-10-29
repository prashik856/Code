#include<iostream> 
#include<string>
using namespace std;

class myclass{
public:
	myclass(string nm){
	//cout << "hey"<< endl;
	setname(nm);
	}
	void setname(string x){
	name=x;
	}
	string getname(){
	return name;
	}
private:
	string name;
};

int main()
{
myclass myobj("AMI");
myclass myobj2("hello");
cout << myobj2.getname() << endl;

cout << myobj.getname()<< endl;
return 0;
}
