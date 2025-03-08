#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
      stack<int> st;
    int n ; 
    cout << "Enter a list of integers, ending with 0: " << endl;

    while (true) 
    {
        cout << "?";
        cin >> n;
        if (n == 0) break;  
        st.push(n);
    }

    cout << "Those integers in reverse order are: " << endl;
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;

}
