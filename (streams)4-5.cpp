#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
int dotNum = 0;

string getExtension(string file);
string getFileName(string file);

int main()
{
  string file;
  getline(cin, file);
  string res1 = getExtension(file);
  string res2 = getFileName(file);

  cout << "extension : " << res1 << " and filename : " << res2 << endl;

  return 0;
}
string getFileName(string file)
{
  string fileName = file.substr(0, dotNum);
  return fileName;
}
string getExtension(string file)
{
  string extension;
  for (int i = 0; i <= file.length(); i++)
  {

    if (file[i] == '.')
    {
      dotNum = i;
    }
  }
  extension = file.substr(dotNum, file.length() - dotNum);
  return extension;
}
