#include <iostream>
#include <string>
using namespace std;


string encodeCaesarCipher(string str, int shift) {
    string result = "";
    for (char c : str) {
        if (isalpha(c)) {
            char base = (isupper(c)) ? 'A' : 'a';
            char shifted = (c - base + shift) % 26 + base;
           
            if (shifted < base) {
                shifted += 26;
            }
            result += shifted;
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    string input;
    int shift;
    
    cout << "Enter a word: ";
    getline(cin, input);
    
    cout << "Enter the shift value: ";
    cin >> shift;
    
    string encoded = encodeCaesarCipher(input, shift);
    
    cout << input << " -> " << encoded << endl;
    
    return 0;
}
