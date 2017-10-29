#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
 { 
  ofstream outputfile;
  string filename;

  cout << "Please inter file name without extension " << endl;
  cin >> filename;

  outputfile.open( filename.c_str());
 
 if(outputfile.fail())
 {
   cout << "Input File opening failed \n " << endl;
   break;
 }

 cout << " What do you want to do in this file ? " << endl;

 cout << " Select from the following options \n 1.Edit a line and save in same file  \n 2. Edit a line and store in another file (renamed)  \n " << endl;

 cout << "Please select any option \n " ;
 
 int a;
 cin >> a;

 if(a==1)
 {
 cout << "Enter any word from the file of the line which you want to edit \n " << endl;
 string b;
 cin >> b;

 int size=strlen(b);

 bool isfound=0;

 while(!outputfile.eof())
 {
      string temp = "";
      getline(outputfile,temp);
      for(int i=0; i<size; i++)
           {
              if(temp[i]==b[i])
                     {
                        isfound=1;
                       }
              else
                 {

                    isfound=0;
                    break;
                     }
             
              }

      if(isfound)
        {
            cout << temp;
           }

    }   
}

 
 outputfile.close();

 cout << "File reading is Done " << endl;
 return 0;

}

