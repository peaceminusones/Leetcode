#include <iostream>
#include <vector>
#include <string>
using namespace std;

void push(vector<int> &q, string mes)
{
    int num = 0;
    for (int i = 0; i < mes.size(); i++)
        if (mes[i] >= '0' && mes[i] <= '9')
            num = num * 10 + (mes[i] - '0');
    q.push_back(num);
}

int top(vector<int> &q)
{
    if (q.size() == 0)
        return -1;
    return q[0];
}

int pop(vector<int> &q)
{
    if (q.size() == 0)
        return -1;

    int item = q[0];
    vector<int>::iterator it = q.begin();
    q.erase(it);
    return item;
}

int size(vector<int> &q)
{
    return q.size();
}

void clear(vector<int> &q)
{
    for (int i = 0; i < q.size(); i++)
        pop(q);
}

int main()
{
    // Solution s;

    vector<int> que;
    vector<string> message;
    string mes;

    int T;
    cin >> T;
    cin.clear();
    cin.ignore();
    for (int k = 0; k < T; k++)
    {
        int Q;
        cin >> Q;
        cin.clear();
        cin.ignore();
        for (int i = 0; i < Q; i++)
        {
            getline(cin, mes);
            message.push_back(mes);
        }
    }

    for (int i = 0; i < message.size(); i++)
    {
        if (message[i].substr(0, 4) == "PUSH")
        {
            push(que, message[i]);
        }
        if (message[i].substr(0, 3) == "TOP")
        {
            cout << top(que) << endl;
        }
        if (message[i].substr(0, 3) == "POP")
        {
            if (pop(que) == -1)
                cout << pop(que) << endl;
        }
        if (message[i].substr(0, 4) == "SIZE")
        {
            cout << size(que) << endl;
        }
        if (message[i].substr(0, 5) == "CLEAR")
        {
            clear(que);
        }
    }

    return 0;
}