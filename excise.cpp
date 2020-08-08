#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

// class mystruct
// {
// private:
//     int a;    // 4
//     char b;   // 1
//     double c; // 8
//     char d;   // 1
// };

// int i = 5;

// int check_sys()
// {
//     int i = 1;
//     return *(char *)&i; // 取出当前指针指向的一个字节
// }

class A
{
public:
    int b = 1;
    void funca()
    {
        cout << "class A" << endl;
    }

private:
    int a = 0;
};

class B : protected A
{
public:
    void func()
    {
        // cout << a << endl;
        cout << b << endl;
        funca();
    }
};

int main()
{
    B b;
    b.func();

    // cout << sizeof(unsigned int) << endl;
    // vector<int> data = {1, 3, 4, 5, 6};

    // sort(data.begin(), data.end(), cmp);
    // for (auto d : data)
    //     cout << d << " ";
    // cout << endl;
    // string str = "123.123.123";
    // cout << stoi(str) << endl;

    // string str = "1234";
    // cout << sizeof(str) << endl;

    // vector<int>::iterator it;
    // if (find(data.begin(), data.end(), 1) != data.end())
    // {
    //     cout << true << endl;
    // }

    // map<int, int> map = {{1, 2}, {2, 3}, {3, 4}};
    // if (map.find(1) != map.end())
    //     cout << true << endl;

    // string str = "1234";
    // string::iterator sit;
    // if (find(str.begin(), str.end(), '1') != str.end())
    //     cout << true << endl;

    return 0;
}
