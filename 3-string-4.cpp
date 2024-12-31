#include <cmath>
#include <string>
#include <cctype>
#include <iostream>
using namespace std;

string capitilize(string input);


int main() {
    string input = "";
    getline(cin,input);
    cout<<capitilize(input);
    
    return 0;
}

string capitilize(string input){
    
    if(isalpha(input[0])){
        input[0] = toupper(input[0]);
    }
    for(int i = 0 ; i<input.length();i++){
        if(isalpha(input[i+1])){
            input[i+1] = tolower(input[i+1]);
        }
    }
    return input;
}
