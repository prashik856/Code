#include<iostream>
#include<string>
using namespace std;

int main(){
clock_t begin = clock();

string s;
cin >> s;
cout << endl << s;
cout << endl << "For normal Interger string";
cout << endl << stoi(s,nullptr,10);
cout << endl << stoul(s,nullptr,10);
cout << endl << stol(s,nullptr,10);
cout << endl << stoll(s,nullptr,10);
cout << endl << stof(s,nullptr);
cout << endl << stod(s,nullptr);
cout << endl << stold(s,nullptr); 

cout << endl << endl << "For Number inside a string";
cin >> s;
cout << endl << s;
cout << endl << stoi(s,nullptr,10);
cout << endl << stoul(s,nullptr,10);
cout << endl << stol(s,nullptr,10);
cout << endl << stoll(s,nullptr,10);
cout << endl << stof(s,nullptr);
cout << endl << stod(s,nullptr);
cout << endl << stold(s,nullptr);


cout << endl << endl << "For number after String";
cin >> s;
cout << endl << s;
cout << endl << stoi(s,nullptr,10);
cout << endl << stoul(s,nullptr,10);
cout << endl << stol(s,nullptr,10);
cout << endl << stoll(s,nullptr,10);
cout << endl << stof(s,nullptr);
cout << endl << stod(s,nullptr);
cout << endl << stold(s,nullptr);

cout << endl << endl << "Same for decimal Number" << endl << endl;
cin >> s;
cout << endl << s;
cout << endl << "For normal Interger string";
cout << endl << stoi(s,nullptr,10);
cout << endl << stoul(s,nullptr,10);
cout << endl << stol(s,nullptr,10);
cout << endl << stoll(s,nullptr,10);
cout << endl << stof(s,nullptr);
cout << endl << stod(s,nullptr);
cout << endl << stold(s,nullptr);

cout << endl << endl << "For Number inside a string";
cin >> s;
cout << endl << s;
cout << endl << stoi(s,nullptr,10);
cout << endl << stoul(s,nullptr,10);
cout << endl << stol(s,nullptr,10);
cout << endl << stoll(s,nullptr,10);
cout << endl << stof(s,nullptr);
cout << endl << stod(s,nullptr);
cout << endl << stold(s,nullptr);


cout << endl << endl << "For number after String";
cin >> s;
cout << endl << s;
cout << endl << stoi(s,nullptr,10);
cout << endl << stoul(s,nullptr,10);
cout << endl << stol(s,nullptr,10);
cout << endl << stoll(s,nullptr,10);
cout << endl << stof(s,nullptr);
cout << endl << stod(s,nullptr);
cout << endl << stold(s,nullptr);

cout << endl << endl << "For number to string" ;
float l;
cin >> l;
cout << endl << l;
string c=to_string(l);
cout << endl << c ;
clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout << endl << "The time taken by the program is " << elapsed_secs << " seconds." << endl;
return 0;
}
