#include <iostream>
#include <iomanip>
#include <string>

#include <fstream>
#include <sstream>
using namespace std;

string checkForFile(string file, ifstream & stream);

int main(){
    ifstream stream;

  cout<<"enter file name ";
  string file;
  getline(cin, file);
  checkForFile(file,stream);
  int lineCount=0;
  int charCount = 0;
  int wordCount = 0; 
  istringstream fileStream(file);
  while(getline(stream,file)){
    lineCount++;
   
     for(int i = 0; i<=file.length();i++){
          
            fileStream>>skipws;
            charCount++;  
  }
    string word;
  
     while(fileStream>>word) {
        wordCount++;

     }
  }
  stream.close();

  cout<<lineCount<< " and " <<charCount << " and " << wordCount;

  return 0;

}

string checkForFile(string file, ifstream & stream){
     stream.open(file);
   if(stream.fail()){
    return "connection error";
   }else{
    return "file found";
   }
   
     
}
