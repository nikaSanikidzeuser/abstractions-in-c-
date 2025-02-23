#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <random>
using namespace std;

string removeComments(ifstream &is, ofstream &os);

int main()
{
  ifstream is;
  ofstream os;
  cout << removeComments(is, os);

  return 0;
}

string removeComments(ifstream &is, ofstream &os)
{
  string text, result;

  is.open("test.txt"); // take something as an example

  os.open("removedComments.txt"); // example too
  char c;
  bool comment = false;
  bool fullComment = false;

  while (is.get(c))
  {
    // for text beginning with /* and ending with */, possibly many lines later
    if (fullComment)
    {
      if (c == '*' & c == '/')
      {
        fullComment = false;
      }
    }
    else
    {
     
      if ((c == '/') & (is.peek() == '*'))
      {

        fullComment = true;
      }
      else
      {
         // for text beginning with // and extending through the end of the line
        if (comment)
        {
          if (c == '\n')
          {
            comment = false;
          }
        }
        else
        {
          if ((c == '/') & (is.peek() == '/'))
          {

            comment = true;
          }
          else
          {
            // if it is not a comment
            os.put(c);
          }
        }
      }
    }
  }

  return result;
}
