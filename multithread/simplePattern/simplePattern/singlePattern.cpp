#include <iostream>
#include <mutex>
using namespace std;

// 饿汉模式 ============================================================================
class Singleton2
{
public:
	/*using sptr = shared_ptr<Singleton2>;*/
	static Singleton2* getSingleton2()
	{
		return m_instance;
	}


private:
	Singleton2() {};
	Singleton2(const Singleton2&) {};
	Singleton2& operator =(const Singleton2&) {};
	
	static Singleton2* m_instance;
};

Singleton2* Singleton2::m_instance;

int main()
{
	return 0;
}

// 懒汉模式 =============================================================================
//template <class T>
//class Singleton
//{
//public:
//	/*using sptr = shared_ptr<Singleton2>;*/
//	static Singleton* getInstance()
//	{
//		if (m_instance_ptr == nullptr)
//		{
//			unique_lock<mutex> lock(m_mtx);
//			if (m_instance_ptr == nullptr)
//			{
//				m_instance_ptr = new Singleton();
//			}
//		}
//		return m_instance_ptr;
//	}
//
//private:
//	Singleton(){}
//	Singleton(const Singleton&){}
//	Singleton& operator =(const Singleton&) {};
//	
//	static mutex m_mtx;
//	static Singleton* m_instance_ptr;
//};
//
//template<class T>
//Singleton<T>* Singleton<T>::m_instance_ptr = nullptr;
//template<class T>
//mutex Singleton<T>::m_mtx;
//
//int main()
//{
//	Singleton<int>* sin = Singleton<int>::getInstance();
//	return 0;
//}


class Singleton
{
	static Singleton* getInstance()
	{
		if (m_instance == nullptr)
		{
			unique_lock<mutex> lock(m_mtx);
			if (m_instance == nullptr)
			{
				m_instance = new Singleton();
			}
		}
		return m_instance;
	}

private:
	Singleton(){}
	Singleton(const Singleton &){}
	Singleton &operator=(const Singleton &){}

	static mutex m_mtx;
	static Singleton* m_instance;
};