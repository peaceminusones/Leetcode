#include <iostream>

using namespace std;

class MyInt
{
private:
    int x_;

public:
    MyInt(int x) : x_(x) { cout << "default ctor\n"; }
    MyInt(const MyInt &u) : x_(u.x_) { cout << "copy ctor\n"; }
    MyInt(MyInt &&u) : x_(u.x_) { cout << "move ctor\n"; }

    friend MyInt operator+(const MyInt &u, const MyInt &v);
};

MyInt operator+(const MyInt &u, const MyInt &v)
{
    // 1st move ctor
    MyInt w{u.x_ + v.x_};
    return w;
}

int main()
{
    MyInt u{3}, v{4};
    // 2nd move ctor
    MyInt w = u + v;
    return 0;
}