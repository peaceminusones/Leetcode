#include <iostream>
#include <queue>
using namespace std;

class Solution
{
    priority_queue<int, vector<int>, less<int>> p;    // 降序队列
    priority_queue<int, vector<int>, greater<int>> q; // 升序队列

public:
    void Insert(int num)
    {
        if (p.empty() || num <= p.top())
            p.push(num);
        else
            q.push(num);

        if (p.size() == q.size() + 2)
        {
            q.push(p.top());
            p.pop();
        }
        if (p.size() + 1 == q.size())
        {
            p.push(q.top());
            q.pop();
        }
    }

    double GetMedian()
    {
        return (p.size() == q.size()) ? (p.top() + q.top()) / 2.0 : p.top();
    }

    void print()
    {
        cout << "p queue:" << endl;
        while (!p.empty())
        {
            cout << p.top() << " ";
            p.pop();
        }
        cout << endl;

        cout << "q queue:" << endl;
        while (!q.empty())
        {
            cout << q.top() << " ";
            q.pop();
        }
        cout << endl;
    }
};

int main()
{
    vector<int> arr;
    int item;
    while (cin >> item)
        arr.push_back(item);
    cin.ignore();
    cin.clear();

    Solution s;
    for (int i = 0; i < arr.size(); i++)
    {
        s.Insert(arr[i]);
    }
    double res = s.GetMedian();
    cout << res << endl;
    s.print();

    return 0;
}