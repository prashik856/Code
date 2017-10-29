#include <iostream>
#include <string>
using namespace std;

class Bankaccount{
public:

	void create(int num){
		ac=num;
		bal=0;
	}

	void deposit(int num,int money){
	if(num==ac){
		bal=bal+money;
	}
	else{
	cout << "No such account number for the given object" << endl;
	}

	}

	void withdraw(int num,int money){
	if(num==ac){
	bal=bal-money;
	}
	else{
	cout << "No such account number for the given object" << endl;
	}
	}

	void showbal(int num){
		if(num==ac){
		cout << bal << endl;
		}
		else{
		cout << "no such account number" << endl;
		}
	}

private:
	int ac;
	int bal;
};

int main(){
Bankaccount prash;
prash.create(1234);
prash.deposit(1234,5000);
prash.showbal(1234);
prash.deposit(1234,5000);
prash.showbal(1234);
prash.withdraw(1234,6000);
prash.showbal(1234);
prash.withdraw(122,1000);
//prash.ac=123;
//prash.bal=100000;

return 0;
}


