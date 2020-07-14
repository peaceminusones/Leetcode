#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    /*
    offer 43 ---------------------------------------------
    */

    // method 1
    string LeftRotateString(string str, int n)
    {
        // eg:"12345"，n=3，结果为：45123
        int len = str.length();
        if (len == 0)
            return "";
        int k = n % len;           // 可能移动的位数大与字符串的长度 k=3
        str += str;                // 字符串拼接:"1234512345"
        return str.substr(k, len); // 截取从第3位开始长度为5的字符串："45123"
    }

    // method 2
    string LeftRotateString1(string str, int n)
    {
        // eg:"12345"，n=3，结果为：45123
        int len = str.length();
        if (len == 0)
            return "";
        n = n % len;
        reverse(str.begin(), str.end());             // 翻转整个字符串: "54321"
        reverse(str.begin(), str.begin() + len - n); // 翻转前面："45321"
        reverse(str.begin() + len - n, str.end());   // 翻转后面："45132"
        return str;
    }

    /*
    offer 44 ---------------------------------------------
    */
    string ReverseSentence(string str)
    {
        stack<string> st;
        int i = 0, j = 0;
        while (j <= str.size())
        {
            if (str[j] == ' ' || j == str.size())
            {
                string s = str.substr(i, j - i);
                st.push(s);
                i = ++j;
            }
            else
            {
                j++;
            }
        }

        string str_new = "";
        while (!st.empty())
        {
            str_new += st.top();
            str_new += " ";
            st.pop();
        }
        return str_new.substr(0, str.size());
    }

    /*
    offer 45 ---------------------------------------------
    */
    bool IsContinuous(vector<int> numbers)
    {
        if (numbers.empty() || numbers.size() != 5)
            return false;

        sort(numbers.begin(), numbers.end()); // 排序

        int joker = 0;
        for (int i = 0; i < 5 && numbers[i] == 0; i++) // 计算王的数量
            joker++;
        if (joker > 4) // 王的数量最大为4
            return false;

        for (int i = joker + 1; i < 5; i++)
            if (numbers[i] == numbers[i - 1]) // 判断是否有对
                return false;

        int dis = numbers[4] - numbers[joker]; // 最大值和最小值之差最大不能超过4
        if (dis <= 4)
            return true;

        return false;
    }
};

int main()
{
    /*
    offer 43 ---------------------------------------------
    */
    // string str;
    // cin >> str;
    // int n;
    // cin >> n;
    // Solution s;
    // string res1 = s.LeftRotateString(str, n);
    // cout << res1 << endl;
    // string res2 = s.LeftRotateString1(str, n);
    // cout << res2 << endl;

    /*
    offer 44 ---------------------------------------------
    */
    // string str;
    // getline(cin, str);
    // Solution s;
    // string res = s.ReverseSentence(str);
    // cout << res << endl;

    /*
    offer 45 ---------------------------------------------
    */
    vector<int> array;
    int item;
    while (cin >> item)
    {
        array.push_back(item);
    }
    Solution s;
    bool res = s.IsContinuous(array);
    cout << res << endl;

    return 0;
}