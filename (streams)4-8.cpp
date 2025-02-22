#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <random>
using namespace std;

string getInputText(string file);
string changeText(string file, string text, string characters);

int main()
{
  string inputFile;
  string outputFile;
  string characters;
  cout << "Input file : ";
  getline(cin, inputFile);
  string result = getInputText(inputFile);
  cout << "Output fule : ";
  getline(cin, outputFile);
  cout << "Characters to remove : ";
  getline(cin, characters);

  cout << changeText(outputFile, result, characters);

  return 0;
}

string getInputText(string file)
{
  ifstream stream;
  string result;
  stream.open(file);
  if (stream.fail())
  {
    return "Input file not found";
  }
  else
  {
    while (getline(stream, file))
    {
      result += file;
      result += "\n";
    }
  }
  return result;
  stream.close();
}

string changeText(string file, string text, string characters)
{
  ofstream stream(file);
  if (!stream)
  {
    return "error";
  }

  for (size_t i = 0; i < text.length();)
  {
    if (characters.find(text[i]) != string::npos) // Check if the character is in 'characters'
    {
      text.erase(i, 1); // Erase character
    }
    else
    {
      i++; // Only increment if no character was erased
    }
  }

  stream << text;
  stream.close();

  return "success";
}
