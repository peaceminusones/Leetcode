#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
====递归方法===========================================================================
    1.对于str中没有重复值的情况：
    固定第一个字符，递归取得后面的各种字符串组合
    再把第一个字符与后面的每个字符交换，并同样递归获得后面的字符串组合
    
    2.对于str中有重复值的情况：
    去重的全排列就是从第一个数字起，每个数分别与它后面非重复出现的数字交换。
    eg:
    对abb，第一个数a与第二个数b交换得到bab，然后考虑第一个数与第三个数交换，
    此时由于第三个数等于第二个数，所以第一个数就不再用与第三个数交换了。
    再考虑bab，它的第二个数与第三个数交换可以解决bba。此时全排列生成完毕！
*/

class Solution
{
public:
    vector<string> Permutation(string str)
    {
        vector<string> res;
        if (str.empty())
            return res;

        PermutationHelper(res, str, 0);

        sort(res.begin(), res.end()); // 按照首字母排序
        return res;
    }

    void PermutationHelper(vector<string> &res, string str, int begin)
    {
        if (begin == str.size() - 1) // 索引到最后一个字符
            res.push_back(str);
        else
        {
            for (int j = begin; j < str.size(); j++) // 从当前字符开始
            {

                if (is_swap(str, begin, j)) // 判断现在是否满足交换的条件
                {
                    swap(str[j], str[begin]);               // 满足的话交换位置
                    PermutationHelper(res, str, begin + 1); // 递归
                    swap(str[j], str[begin]);               // 交换回来
                }
            }
        }
    }

    bool is_swap(string str, int i, int j)
    {
        if (i == j) // 如果索引处于开始位置，则满足条件
            return true;
        // 如果当前位置的字符之前出现过，或者要交换的两个字符相同，则不交换
        else if (str.substr(i, j - i).find(str[j]) != string::npos || str[i] == str[j])
        {
            // 注意substr的用法！！！str.substr(pos,n)表示截取str中从pos开始（包括pos）的n个字符的子串，并返回
            // eg: aabc，str.substr(2,1)，得到的是'b'

            // cout << "(" << i << " " << j << ")" << endl;
            // cout << str.substr(i, j - i) << "," << str[j] << endl;
            // cout << str.substr(i, j - i).find(str[j]) << endl;
            return false;
        }
        else
            return true;
    }

    void swap(char &c1, char &c2) // 记得带引用符号！
    {
        char temp = c1;
        c1 = c2;
        c2 = temp;
    }
};

/*
====非递归方法==========================================================================
字典序排列算法
    一个全排列可看作一个字符串，字符串可有前缀、后缀
    生成给定全排列的下一个排列，就要求这一个与下一个有尽可能长的共同前缀，也即变化限制在尽可能短的后缀上
    346987521是（1-9）的一个排列
    （1-9）的排列，最前面的是123456789，最后面的是987654321

    那如何找到346987521的下一个排列：
    1. 从尾部向前找到第一个p[i-1]<p[i]的位置
        3 4 6 <- 9 <- 8 <- 7 <- 5 <- 2 <- 1
        即找到6<9，i-1位置为6，i位置为9
    2. 从i位置开始往后找，找到最后一个大于6的数，即为7，记录位置为j
    3. 交换i-1和j位置的值
        3 4 7 9 8 6 5 2 1
    4. 把i位置后(包括i)的所有数据倒序
        3 4 7 1 2 5 6 8 9
    结果：347125689即为346987521的下一个排列
*/

class Solution2
{
public:
    vector<string> Permutation2(string str)
    {
        vector<string> res;
        if (str.empty())
            return res;
        res.push_back(str);
        while (true)
        {
            int i = str.size() - 1; //从右往左的索引
            int j;                  // 从左往右的索引

            while (i > 0 && str[i - 1] >= str[i]) // 从右往左索引，找到str[i - 1] < str[i]的索引值
                i--;

            if (i == 0) // 如果i为0，则表示完成
                break;

            j = i;                                        // 从i开始往右索引
            while (j < str.size() && str[j] > str[i - 1]) // 找到比[i - 1]位置的值大的位置
                j++;

            swap(str[i - 1], str[j - 1]); // 交换两个位置的值
            reverse(str, i);              // 从i到结尾（包括i）的字符串倒序
            res.push_back(str);           // 结果放到res中
        }
        return res;
    }

    // 字符串倒序
    void reverse(string &str, int index)
    {
        int len = str.size();
        for (int i = 0; i < (len - index) / 2; i++)
            swap(str[index + i], str[len - 1 - i]); // 从位置[i+index]开始，分别与倒数的位置进行交换，次数为子串长度的一半
    }

    // 字符交换
    void swap(char &c1, char &c2)
    {
        char temp = c2;
        c2 = c1;
        c1 = temp;
    }
};

int main()
{
    string str;
    cin >> str;

    Solution s;
    vector<string> res;
    res = s.Permutation(str);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;

    Solution2 s2;
    vector<string> res2;
    res2 = s2.Permutation2(str);

    for (int i = 0; i < res2.size(); i++)
        cout << res2[i] << " ";
    return 0;
}