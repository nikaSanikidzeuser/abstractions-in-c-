#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <vector>
using namespace std;

const int ERROR_NUM = -1;
const string ERROR_MESSAGE = "file not found";
vector<double> data;

double getData(string fileName, ifstream &stream);
double mean(vector<double> &data);

int main()
{
   string fileName;
   cout << "enter file name ";

   getline(cin, fileName);
   ifstream stream;
   double mean = getData(fileName, stream);
   if (mean == ERROR_NUM)
   {
      cerr << ERROR_MESSAGE;
   }
   else
   {
      cout << mean;
   };

   return 0;
}

double mean(vector<double> &data)
{
   double mean = 0;
   for (int i = 0; i < data.size(); i++)
   {
      mean += data[i];
   }
   mean = mean / data.size();
   return mean;
}
double getData(string fileName, ifstream &stream)
{
   vector<double> data;
   string line;

   stream.open(fileName);
   if (stream.fail())
   {
      return ERROR_NUM;
   }
   else
   {
      while (getline(stream, line))
      {

         int num = stod(line);
         data.push_back(num);
      }
      return mean(data);

      stream.close();
   }
}
