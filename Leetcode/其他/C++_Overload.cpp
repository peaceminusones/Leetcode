
#include <iostream>
using namespace std;

// 基类
class Shape
{
public:
    void setWidth(int w)
    {
        width = w;
    }
    void setHeight(int h)
    {
        height = h;
    }

protected:
    int width;
    int height;
};

void pirnt()
{
    return;
}

class Rectange : public Shape
{
public:
    int getArea()
    {
        return width * height;
    }
};

int main()
{
    Rectange rect;
    rect.setWidth(5);
    rect.setHeight(7);

    cout << rect.getArea() << endl;
    return 0;
}

class A
{
public:
    int a;
};

class B : A // 默认继承方式是私有继承
{
public:
    using A::a;
    void fun()
    {
        cout << a << endl;
    }
};


