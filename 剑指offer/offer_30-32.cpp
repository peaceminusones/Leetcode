/*
    offer30 & offer 31 & offer 32 ==============================
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    // offer 30 =======================================
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        if (array.empty())
            return 0;
        if (array.size() == 1)
            return array[0];

        vector<int> dp;
        dp.push_back(array[0]);

        for (int i = 1; i < array.size(); i++)
        {
            int temp = max(array[i], dp[i - 1] + array[i]);
            dp.push_back(temp);
        }

        int m = dp[0];
        for (int i = 1; i < dp.size(); i++)
            if (dp[i] > m)
                m = dp[i];

        return m;
    }

    // offer 31 =======================================
    int NumberOf1Between1AndN_Solution(int n)
    {
        if (n <= 0)
            return n;
        int count = 0;
        int i = 1; // 表示当前为为个位
        while (n / i != 0)
        {
            int pre = (n / (i * 10)) * i;
            int cur = min(max(n % (i * 10) - i + 1, 0), i);
            count += (pre + cur);
            i *= 10;
        }
        return count;
    }

    // offer 32 =======================================
    /*
        必须是静态的！！
        非静态成员函数是依赖于具体对象的，而std::sort这类函数
        是全局的，因此无法再sort中调用非静态成员函数。静态成员
        函数或者全局函数是不依赖于具体对象的, 可以独立访问，无
        须创建任何对象实例就可以访问。同时静态成员函数不可以调
        用类的非静态成员
    */
    static bool cmp(int a, int b)
    {
        string s1 = "", s2 = "";
        // a连接b
        s1 += to_string(a);
        s1 += to_string(b);
        // b连接a
        s2 += to_string(b);
        s2 += to_string(a);

        return s1 < s2;
    }

    string PrintMinNumber(vector<int> numbers)
    {
        string res = "";
        sort(numbers.begin(), numbers.end(), cmp);
        for (int i = 0; i < numbers.size(); i++)
            res += to_string(numbers[i]);

        return res;
    }
};

int main()
{
    // offer 30 ===================================
    // vector<int> v;
    // int item;
    // while (cin >> item)
    // {
    //     v.push_back(item);
    // }

    // Solution s;
    // int res = s.FindGreatestSumOfSubArray(v);
    // cout << res << endl;

    // offer 31 ====================================
    // int n;
    // cin >> n;
    // Solution s;
    // int res = s.NumberOf1Between1AndN_Solution(n);
    // cout << res << endl;

    // offer 32 ====================================
    vector<int> n;
    int item;
    while (cin >> item)
        n.push_back(item);
    Solution s;
    string res = s.PrintMinNumber(n);
    cout << res << endl;
}