#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string replaceAll(string str, char c1, char c2);


int main() {
    string str;
     char c1, c2;
     cin >> str >> c1 >> c2;
     cout << replaceAll(str, c1, c2) << endl;
     return 0;
}


string replaceAll(string str, char c1, char c2){

    for(int i = 0 ; i < str.length() ; i++){
        if(str[i] == c1){
            str[i] = c2;
        }
    }
    return str;
}
