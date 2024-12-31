
#include <cmath>
#include <string>
#include <cctype>
#include <iostream>
using namespace std;

int totalPoints=0;
int sumUp(string input);


int main() {
    
    string name = "";
    getline(cin,name);
    cout<<sumUp(name);
    return 0;
}

int sumUp(string input){
    for(int i = 0; i<input.length();i++){
        char c = input[i];
        switch (c) {
                
            case 'A':
            case 'E':
            case 'I':
            case 'L':
            case 'N':
            case 'O':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
                totalPoints += 1;
                break;
                
                
            case 'D':
            case 'G':
                totalPoints += 2;
                break;
                
                
            case 'B':
            case 'C':
            case 'M':
            case 'P':
                totalPoints += 3;
                break;
                
                
            case 'F':
            case 'H':
            case 'V':
            case 'W':
            case 'Y':
                totalPoints += 4;
                break;
                
            case 'K':
                totalPoints += 5;
                break;
                
                
            case 'J':
            case 'X':
                totalPoints += 8;
                break;
                
                
            case 'Q':
            case 'Z':
                totalPoints += 10;
                break;
            default:
                break;
        };
    };
    return totalPoints;
}
