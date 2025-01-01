#include <iostream>
#include <string>
#include <cctype>
using namespace std;


string addCommas(int n);


int main() {
    int n;
    cin>>n;
    cout<<addCommas(n);
    return 0;
}

string addCommas(int n){
    string result = to_string(n);
    int len = result.length();
    int commaCount = 0;
    
    for (int i = len - 1; i > 0; i--) {
        commaCount++;
        if (commaCount == 3) {
            result.insert(i, ",");
            commaCount = 0;
        }
    }
    
    return result;
}

