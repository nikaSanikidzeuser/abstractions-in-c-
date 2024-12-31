#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string createRegularPlural(string word);

int main() {
    string str = "";
    getline(cin,str);
    cout<<createRegularPlural(str);
    
    return 0;
}


string createRegularPlural(string word){
    string result = word;
    int n = word.length()-1;
    if( word[n] == 's' || word[n] == 'x' || word[n] == 'z' ){
        result += "es";
    }else
        if(word.substr(n-1,n) == "ch" || word.substr(n-1,n) == "sh"){
            result += "es";
        }else
            if( word[n] == 'y'){
                result.erase(n);
                
                result += "ies";
            }else{
                return result+"s";
            }
    return result;
}
