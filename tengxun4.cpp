#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
    stack<int> s1, s2;

public:
    void add(int item)
    {
        if (s2.empty())
            s2.push(item);
        
    }

    void poll()
    {
    }

    int peek()
    {
    }
};

int main()
{
    Solution s;
    int n;
    cin >> n;
    string mes;
    vector<string> message;

    for (int i = 0; i < n; i++)
    {
        getline(cin, mes);
        message.push_back(mes);
    }

    for (int i = 0; i < message.size(); i++)
    {
        if (message[i].substr(0, 3) == "add")
        {
            int num = 0;
            for (int i = 0; i < mes.size(); i++)
                if (mes[i] >= '0' && mes[i] <= '9')
                    num = num * 10 + (mes[i] - '0');
            s.add(num);
        }
        if (message[i].substr(0, 4) == "peek")
            cout << s.peek() << endl;
        if (message[i].substr(0, 4) == "poll")
            s.poll();
    }

    return 0;
}