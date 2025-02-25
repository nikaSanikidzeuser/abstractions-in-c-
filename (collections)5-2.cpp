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
double stddev(vector<double> &data);

int main()
{
   string fileName;
   cout << "enter file name ";

   getline(cin, fileName);
   ifstream stream;
   double stddev = getData(fileName, stream);
   if (stddev == ERROR_NUM)
   {
      cerr << ERROR_MESSAGE;
   }
   else
   {

      cout << stddev;
   };

   return 0;
}

// stddev calc
double stddev(vector<double> &data)
{
   double stddev = 0;
   double mean = 0;
   double minus = 0;
   double sum = 0;
   double division = 0;
   for (int i = 0; i < data.size(); i++)
   {
      mean += data[i];
   }
   mean = mean / data.size();

   for (int j = 0; j < data.size(); j++)
   {
      minus = mean - data[j];
      minus *= minus;
      sum += minus;
   }

   division = sum / data.size();
   stddev = sqrt(division);
   return stddev;
}
// gets data
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

         int num = std::stod(line);
         data.push_back(num);
      }
      return stddev(data);

      stream.close();
   }
}
