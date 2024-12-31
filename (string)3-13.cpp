#include <iostream>
#include <string>
#include <cctype>
using namespace std;


string createOrdinalForm(int n);


int main() {
    int n;
    cin>>n;
    cout<<createOrdinalForm(n);
    return 0;
}

string createOrdinalForm(int n){
    string result = "";
    if (n % 100 >= 11 && n % 100 <= 13) {
        result = to_string(n) + "th";
    }
    else {
        
        switch(n % 10) {
            case 1:
                result = to_string(n) + "st";
                break;
            case 2:
                result = to_string(n) + "nd";
                break;
            case 3:
                result = to_string(n) + "rd";
                break;
            default:
                result = to_string(n) + "th";
                break;
        }
    }
    return result;
}

