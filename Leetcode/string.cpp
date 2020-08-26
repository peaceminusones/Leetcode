#include <iostream>
#include <cstring>
using namespace std;

//基本类方法
class String
{
public:
    String(const char *str = NULL); //普通的构造函数, 注意=NULL
    String(const String &other);    //拷贝构造函数
    ~String();
    String &operator=(const String &rhs); //=运算符构造，赋值构造函数
    void Show();

private:
    char *m_data; //保存字符串
};

//方法实现
String::String(const char *str)
{
    if (str == NULL)
    {
        m_data = new char[1];
        *m_data = '\0';
    }
    else
    {
        int num = strlen(str);
        m_data = new char[num + 1];
        strcpy(m_data, str);
    }
    cout << "默认构造" << endl;
}

// 析构函数
String::~String()
{
    delete[] m_data;
    m_data = NULL;
    cout << this << "析构" << endl;
}

// 拷贝构造函数
String::String(const String &other)
{
    int len = strlen(other.m_data);
    m_data = new char[len + 1];
    strcpy(m_data, other.m_data);
    cout << "拷贝构造" << endl;
}

//等号运算符重载
//赋值构造函数，将=右边的本类对象的值复制给等号左边的的对象，它不属于构造函数，等号左右两边的对象必须已经被创建
//若没有显示写=运算符重载，系统也会创建一个默认的=运算符重载，只做一个简单的拷贝工作
String &String::operator=(const String &rhs)
{
    //首先检测等号右边的是否就是左边的对象本身，如果是，则返回就行
    if (&rhs == this)
    {
        return *this;
    }

    delete[] m_data;
    int len = strlen(rhs.m_data);
    m_data = new char[len + 1];
    strcpy(m_data, rhs.m_data);
    cout << "=运算符重载，赋值构造函数" << endl;
    return *this;
}

void String::Show()
{
    cout << m_data << endl;
}

//测试
int main()
{
    //拷贝构造
    //String str = "str";
    //String str1 = str;
    // str1.Show();
    //等号运算符重载构造函数
    // String s1 = "str";
    // String s2;
    // s2 = s1;
    // s2.Show();
    String s1 = "abc";
    String s2 = String(s1);
    //String s3 = s1 + s2;
    return 0;
}