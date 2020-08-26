#include <bits/stdc++.h>
#include <mutex>
using namespace std;

class Singleton
{
public:
    static Singleton *getInstance();

private:
    Singleton() {}
    Singleton(Singleton &) {}
    Singleton &operator=(Singleton &) {}

    static Singleton *m_instance;
};

Singleton *Singleton::getInstance()
{
    return m_instance;
}

// 饿汉模式关键：初始化即实例化
Singleton *Singleton::m_instance = new Singleton();

int main()
{
    return 0;
}