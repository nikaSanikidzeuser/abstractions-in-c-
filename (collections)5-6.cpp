#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <set>
#include <vector>
#include <string>
#include <cmath>
#include <map>

using namespace std;

const int ERROR_NUM = -1;
const string ERROR_MESSAGE = "File not Found, try again.";
const string SUCCESS_MESSAGE = "File found.";
const string PROMT_FOR_FILE = "enter file name : ";
const int START_NUM = 2;
const int LAST_NUM = 1000;

void prime(ifstream &stream);

int main()
{

   vector<int> numbers(LAST_NUM + 1, 1);
   numbers[0] = numbers[1] = 0;

   for (int i = 0; i <= sqrt(LAST_NUM); i++)
   {
      if (numbers[i] == 1)
      {
         for (int j = i * i; j <= LAST_NUM; j += i)
         {
            numbers[j] = 0;
         }
      }
   }

   for (int i = 2; i <= LAST_NUM; i++)
   {
      if (numbers[i] == 1)
      {
         cout << i << endl;
      }
   }
   return 0;
}
