#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

string defaultExtension(string filename, string ext);
string getFileName(string filename);

int main()
{
  string filename, ext;
  getline(cin, filename);
  getline(cin, ext);
  string result = defaultExtension(filename, ext);
  cout << "result : " << result << endl;

  return 0;
}

string defaultExtension(string filename, string ext)
{
  string file;

  for (int i = 0; i <= filename.length(); i++)
  {

    if (filename[i] == '.')
    {
      file = filename;
      break;
    }
  }
  if (ext[0] == '*')
  {
    string result;

    file = getFileName(filename) + ext.substr(1, ext.length() - 1);
  }
  else
  {
    bool noExt = true;
    for (int j = 0; j <= filename.length(); j++)
    {
      if (filename[j] == '.')
      {
        noExt = false;
      }
    }
    if (noExt)
    {
      file = filename + ext;
    }
  }

  return file;
}

string getFileName(string filename)
{
  string result;
  for (int i = 0; i <= filename.length(); i++)
  {
    if (filename[i] == '.')
    {
      result = filename.substr(0, i);
      break;
    }
  }
  return result;
}
