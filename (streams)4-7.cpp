#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <random>
using namespace std;

bool checkForFile(string fileName, ifstream &stream);
string randomText(string filename, ifstream &stream);
int randomUpperCase();
int randomLowerCase();
int main()
{
  ifstream stream;
  string fileName;

  getline(cin, fileName);
  if (checkForFile(fileName, stream))
  {

    string result = randomText(fileName, stream);
    cout << "changed text: "<<result<<endl;
  }
  else
  {
    cout << "file not found";
  }
  return 0;
}

bool checkForFile(string fileName, ifstream &stream)
{

  stream.open(fileName);
  if (stream.fail())
  {
    return false;
  }
  return true;
}
string randomText(string filename, ifstream &stream)
{
  string line;
  string result;

  while (getline(stream, line))
  {
    for (int j = 0; j <= line.length(); j++)
    {
      if (isupper(line[j]))
      {
      int changed = randomUpperCase();
        
        result += changed;
      }
      else if (islower(line[j]))
      {
       int changed = randomLowerCase();
        result += changed;
      }
      else
      {
        result += line[j];
      }
    }
  }

  return result;
}


int randomUpperCase(){
  std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(65,90);
        char changed = dist(gen);
        return changed;
}
int randomLowerCase(){
  std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(97, 122);
        char changed = dist(gen);
        return changed;
}
