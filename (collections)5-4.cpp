#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <set>
#include <vector>
#include <string>
#include <map>

using namespace std;

const int ERROR_NUM = -1;
const string ERROR_MESSAGE = "File not Found, try again.";
const string SUCCESS_MESSAGE = "File found.";
const string PROMT_FOR_FILE = "enter file name : ";

void histogram(ifstream &stream);

int main()
{
   ifstream stream;
   histogram(stream);

   return 0;
}

void histogram(ifstream &stream)
{
   string fileName;
   bool fileFound = true;
   while (fileFound)
   {
      cout << PROMT_FOR_FILE;

      getline(cin, fileName);
      stream.open(fileName);
      if (stream.fail())
      {
         cerr << ERROR_MESSAGE << endl;
      }
      else
      {
         cout << SUCCESS_MESSAGE << endl;
         fileFound = false;
         vector<int> histogramData;
         map<int, int> count = {
             {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}, {9, 0}, {10, 0}};
         string line;
         int c;

         while (getline(stream, line, ','))
         {
            int num = stoi(line);
            histogramData.push_back(num);
         }

         for (int i = 0; i < histogramData.size(); i++)
         {
            int key = histogramData[i] / 10;
            if (count.find(key) != count.end())
            {
               count[key]++;
            }
         }
         cout << "Histogram " << endl;
         for (const auto &entry : count)
         {
            cout << entry.first << "0 s : ";
            for (int j = 0; j < entry.second; j++)
            {
               cout << " *";
            }
            cout << endl;
         }
      }
   }
}
