#include <iostream>
#include <mutex>
using namespace std;

// 饿汉模式 ============================================================================
class Singleton2
{
public:
	using ptr = shared_ptr<Singleton2>;

	static ptr getSingleton2()
	{
		return m_instance;
	}


private:
	Singleton2() {};
	Singleton2(const Singleton2&) {};
	Singleton2& operator =(const Singleton2&) {};
	static ptr m_instance;
};

Singleton2::ptr Singleton2::m_instance = Singleton2::ptr(new Singleton2());

int main()
{

}

// 懒汉模式 =============================================================================
class Singleton
{
public:
	static Singleton* getInstance()
	{
		if (m_instance_ptr == NULL)
		{
			unique_lock<mutex> lock(m_mtx);
			if (m_instance_ptr == NULL)
			{
				m_instance_ptr = new Singleton();
			}
		}
		return m_instance_ptr;
	}

private:
	static mutex m_mtx;
	static Singleton* m_instance_ptr;
	Singleton(){}
	Singleton(const Singleton&){}
	Singleton& operator =(const Singleton&) {};
};

