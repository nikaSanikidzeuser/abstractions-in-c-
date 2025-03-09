#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

void reverseQueue(queue<string> &queue);

int main()
{
    queue<string> data;
    data.push("And the first one now");
    data.push("Will later be last");
    data.push("For the times they are a-changin");
    reverseQueue(data);
    return 0;
}
void reverseQueue(queue<string> &queue)
{
    stack<string> data;
    
    while (true)
    {

        string str;
        str = queue.front();
        data.push(str);
         
        queue.pop();
        if (queue.empty())
            break;
    }
    while(!data.empty()){
         string str = data.top();
         queue.push(str);
         data.pop();

    }
    while (!queue.empty())
    {
        cout << queue.front()<<endl;
        queue.pop();
    }
}
