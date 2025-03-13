#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <fstream>

using namespace std;

int main()
{
    string lines;
    map<char, string> str;
    ifstream stream;
    stream.open("test.txt");
    while (getline(stream, lines))
    {

        for (int i = 0; i < lines.length(); i++)
        {
            if (isspace(lines[i]))
            {
                string last = lines.substr(i + 1, lines.length() - i);
                char linechar = lines[i - 1];

                str.insert({linechar, last});
            }
        }
    }
    string input;
    cout<<"Morse code translator "<<endl;
    cout<<"> ";
    getline(cin, input);
    string result;
    for (int i = 0; i < input.length(); i++)
    {
        char ch = input[i];
        for (auto it = str.begin(); it != str.end(); it++)
        {
            if (ch == it->first)
            {
                result += it->second;
            }
        }
    }
    cout << result;
}
