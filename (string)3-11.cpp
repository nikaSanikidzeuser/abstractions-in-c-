#include <cctype>
#include <string>
#include <iostream>
using namespace std;

bool isSentencePalindrome(string str);

int main() {
    string str = "";
    getline(cin, str);
    
    cout << (isSentencePalindrome(str) ? "true" : "false");
}

bool isSentencePalindrome(string str) {
    string front = "";
    
    for (int i = 0; i < str.length(); i++) {
        if (isalpha(str[i])) {
            front += tolower(str[i]);
        }
    }
    
    for (int i = 0; i < front.length() / 2; i++) {
        if (front[i] != front[front.length() - 1 - i]) {
            return false;
        }
    }
    
    return true;
}
