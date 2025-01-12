#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string  openFile(string str);


int main() {
    string str;
    getline(cin,str);
    cout<<openFile(str);
    
    
    return 0;
}

string openFile(string str){
    string longest;
    string current;
    ifstream infile;
    infile.open(str);
    if(!infile.is_open()){
        return "file not found";
    }
    while(getline(infile,current)){
        if(current.length()>longest.length()){
            longest=current;
            
        }
        
        
    }
    infile.close();
    if(!(longest.length()>0)){
        return "failed";
        
    }
    return longest;
    
    
}
