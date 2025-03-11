#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

bool checkCode(string str);

int main()
{
    string str = "{ s = 2 * (a[2] + 3); x = (1 + (2)); }";

    if (checkCode(str))
    {
        cout << "Yes, it is balanced.";
    }
    else
    {
        cout << "No, it is not balanced.";
    }
    return 0;
}

bool checkCode(string str)
{
    vector<char> chars;
    for (int i = 0; i < str.length(); i++)
    {
        chars.push_back(str[i]);
    }
    for (int j = 0; j < chars.size(); j++)
    {
        if (chars[j] == '{')
        {
            for (int k = j + 1; k < chars.size(); k++)
            {
                if (chars[k] == '}')
                {
                    chars[j] = ' ';
                    chars[k] = ' ';
                    break;
                }
            }
        }
    }
    for (int j = 0; j < chars.size(); j++)
    {
        if (chars[j] == '[')
        {
            for (int k = j + 1; k < chars.size(); k++)
            {
                if (chars[k] == ']')
                {
                    chars[j] = ' ';
                    chars[k] = ' ';
                    break;
                }
            }
        }
    }
    for (int j = 0; j < chars.size(); j++)
    {
        if (chars[j] == '(')
        {
            for (int k = j + 1; k < chars.size(); k++)
            {
                if (chars[k] == ')')
                {
                    chars[j] = ' ';
                    chars[k] = ' ';
                    break;
                }
            }
        }
    }
    string str1 = "({[]})";
    for (int p = 0; p < chars.size(); p++)
    {
        for (char c : str1)
        {
            if (chars[p] == c)
            {
                return false;
            }
        }
    }
    return true;
}
