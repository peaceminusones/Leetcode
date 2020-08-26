#include <bits/stdc++.h>
#include <mutex>
using namespace std;

class Singleton
{
public:
    static Singleton *getInstance();

private:
    Singleton(){};
    Singleton(const Singleton &) {}
    Singleton &operator=(const Singleton &) {}

    static Singleton *m_instance;
    static mutex m_mtx;
};

mutex Singleton::m_mtx;
Singleton *Singleton::getInstance()
{
    if (m_instance == NULL)
    {
        unique_lock<mutex> lock(m_mtx);
        if (m_instance == NULL)
        {
            m_instance = new Singleton();
        }
    }
    return m_instance;
}

Singleton *Singleton::m_instance = NULL;

int main()
{
}