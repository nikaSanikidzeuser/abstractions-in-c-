#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const string c = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string cypher = "QWERTYUIOPASDFGHJKLZXCVBNM";

string decode(string str);
char intDecode(int n);
string toUpperCase(string str);

int main() {
    string input = "";
    cout << "Letter substitution cipher" << endl;
    cout << "Enter a 26-letter key: QWERTYUIOPASDFGHJKLZXCVBNM" << endl;
    getline(cin, input);
    cout << "Encoded message: " << decode(input);
    
    return 0;
}

string decode(string str) {
    str = toUpperCase(str);
    string result = "";
    int num;
    
    for (int j = 0; j < str.length(); j++) {
        if (isalpha(str[j])) {
            num = c.find(str[j]);
            result += intDecode(num);
        }else{
            result += str[j];
        }
        
    }
    
    return result;
}

char intDecode(int n) {
    return cypher[n];
}

string toUpperCase(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = toupper(str[i]);
    }
    return str;
}
