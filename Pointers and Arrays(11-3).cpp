#include <iostream>
#include <vector>
#include <chrono>
#include <map>
#include <string>

using namespace std;

map<int,string> values = {
    {10,"A"},
    {11,"B"},
    {12,"C"},
    {13,"D"},
    {14,"E"},
    {15,"F"}
};

string integerToString(int n , int k);
int stringToInteger(string n , int k);
int helper(int n , int k);
int main(){
    string result = integerToString(42,16);
    
    int result2 = stringToInteger("111111", 2);
    cout<<result2;
    
    
    
    return 0;
    
}


string integerToString(int n , int k){
    
    int div = n/k;
    int left = n%k;
    auto key = values.find(left);
    string result = to_string(div)+key->second;
    return result;
    
}

int stringToInteger(string n , int k){
    
    int result = 0;
    int count = n.length()-1;
    if (k==2) {
        
        
        for(int i =count+1;i>=0;i--){
            if(n[i]=='1'){
                result +=  helper(i, 2);
            }
            
        }
    }
    
    return result;
    
}
int helper(int n , int k){
    if(n==0){
        return 1;
        
    }
    return k*helper(n-1,k);
    
}
