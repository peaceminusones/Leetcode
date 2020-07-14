#include <iostream>
#include <vector>
using namespace std;

/*
    method 1：递归+短路原理 ======================================
*/
class Solution
{
public:
    int Sum_Solution(int n)
    {
        int sum = n;
        sum && (sum += Sum_Solution(n - 1)); // 如果sum为0，则不再执行后面的函数
        return sum;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution s;
    int sum = s.Sum_Solution(n);
    cout << sum << endl;
    return 0;
}

/*
    method 2：构造函数=================================
*/
// class Sum
// {
// private:
//     static int n;
//     static int sum;

// public:
//     Sum()
//     {
//         ++n;
//         sum += n;
//     }

//     static void Reset()
//     {
//         n = 0;
//         sum = 0;
//     }

//     static int GetSum()
//     {
//         return sum;
//     }
// };

// int Sum::n = 0;
// int Sum::sum = 0;

// int Sum_solution(int n)
// {
//     Sum::Reset();
//     // 动态分配数组
//     // 构造一个以Sum类为类型、大小为n的数组，会调用其构造函数进行默认初始化
//     // 重复调用此构造函数n次来实现n次的累加运算
//     Sum *s = new Sum[n];
//     delete[] s;
//     s = nullptr;
//     return Sum::GetSum();
// }

// int main()
// {
//     int n;
//     cin >> n;
//     int res = Sum_solution(n);
//     cout << res << endl;
//     return 0;
// }

/*
    method 3：利用虚函数求解+递归 =============================
*/
// class A;
// A *array[2];

// class A
// {
// public:
//     virtual unsigned int Sum(unsigned int n)
//     {
//         cout << "a" << endl;
//         return 0;
//     }
// };

// class B : public A
// {
// public:
//     virtual unsigned int Sum(unsigned int n)
//     {
//         // !!n来构造true(1) false(0)来对指针数组进行访问
//         // 即只要n不为0，!!n就为1，调用的是B的sum
//         // 如果n为0，!!n就为0，调用的是A的sum
//         cout << "b" << endl;
//         return array[!!n]->Sum(n - 1) + n;
//     }
// };

// int main()
// {
//     int n;
//     cin >> n;
//     A a;
//     B b;
//     array[0] = &a;
//     array[1] = &b;
//     int value = array[1]->Sum(n);
//     cout << value << endl;
//     return 0;
// }

/*
    method 4：利用函数指针 ===============================
*/

// // typedef 创建类型别名，函数指针名为fun
// // 参数类型为int，参数个数为1，返回值类型为int
// typedef int (*fun)(int);

// int Solution(int n)
// {
//     return 0;
// }

// int Sum_solution(int n)
// {
//     static fun f[2] = {Solution, Sum_solution};
//     return f[!!n](n - 1) + n;
// }

// int main()
// {
//     int n;
//     cin >> n;
//     int value = Sum_solution(n);
//     cout << value << endl;
//     return 0;
// }

/*
    method 5：利用模板类型求解 ========================
    ???????????????????????
*/

// template <int n>
// struct Sum_Solution
// {
//     enum Value
//     {
//         N = Sum_Solution<n - 1>::N + n;
//     };
// };

// template <>
// struct Sum_Solution<1>
// {
//     enum Value
//     {
//         N = 1
//     };
// };
