#include <bits/stdc++.h>
using namespace std;

// static int a[2048] = {1};

// void func(int a)
// {
//     std::cout << "a" << std::endl;
// }

// void func(double b)
// {
//     std::cout << "b" << std::endl;
// }

struct st
{
    int a;
    char b;
};

int main()
{
    // func(1.0f);
    // return 0;
    vector<st> v;
    st st1[2];
    for (int i = 0; i < 2; i++)
    {
        st1[i].a = i;
        st1[i].b = '1';
        v.push_back(st1[i]);
        cout << v[i].a << " " << v[i].b << endl;
    }
    
    return 0;
}