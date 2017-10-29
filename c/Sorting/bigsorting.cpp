#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> unsorted(n);
    for(int unsorted_i = 0; unsorted_i < n; unsorted_i++){
       cin >> unsorted[unsorted_i];
    }
    //cout << endl << int('1') << " " << int ('2') << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1-i; j++){
            int a=unsorted[j].size();
            int b=unsorted[j+1].size();
            if(a > b){
                swap(unsorted[j],unsorted[j+1]);
            }
            else if( a==b ){
                for(int k=0; k<a; k++){
 	            cout << endl;
 	            cout << endl << "Value in vector is=" << unsorted[j][k] << " " << "value in int is =" << int(unsorted[j][k]) << endl;
		    cout << endl << "Value in vector is=" << unsorted[j+1][k] << " " << "value in int is =" << int(unsorted[j+1][k]) << endl;
                    cout << endl;    
		if(int(unsorted[j][k]) < int(unsorted[j+1][k])){
                        swap(unsorted[j],unsorted[j+1]);
			break;
                    }
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        cout << unsorted[i] << endl;
    }
    return 0;
}

