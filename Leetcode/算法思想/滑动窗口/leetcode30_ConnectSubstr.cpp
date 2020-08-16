#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
    }

    int contain(unordered_map<string, int> &word_count, unordered_map<string, int> &s_word)
    {
        int flag = 0;
        for (auto it = s_word.begin(); it != s_word.end(); it++)
        {
            if (it->second > word_count[it->first])
                return 0;
            if (it->second < word_count[it->first])
                flag = 1;
        }

        if (flag == 1 || s_word.size() < word_count.size())
            return 1; // 还没有遍历所有的word
        else
            return 2; // 二者相等
    }
};

int main()
{
    string str;
    cin >> str;
    vector<string> words;
    string item;
    while (cin >> item)
    {
        words.push_back(item);
        if (cin.get() == '\n')
            break;
    }

    Solution s;
    vector<int> res = s.findSubstring(str, words);
    for (auto r : res)
        cout << r << " ";

    return 0;
}

// int start = 0; // 表示开始匹配的位置
// int i = 0;
// while (i < s.size() - length) // i：窗口的左边界
// {
//     int left = i, right = i;            // 窗口内的左指针，右指针
//     for (; right < i + length; right++) // 移动右指针，在窗口内逐个匹配
//     {
//         string tmp = s.substr(left, right - left + 1);
//         cout << tmp << endl;
//         if (word_count.find(tmp) != word_count.end())
//         {
//             s_word[tmp]++;
//             int signal = contain(word_count, s_word);
//             if (signal == 0) // 数量已经超过word里的数量了
//             {
//                 s_word.clear();
//                 start = i + tmp.size();
//                 i = i + tmp.size();
//                 break;
//             }
//             else if (signal == 1) // 数量还没到达word里的数量
//             {
//                 left = right + 1;
//             }
//             else if (signal == 2) // 数量刚好等于word里的数量
//             {
//                 res.push_back(start);
//                 s_word.clear();
//                 start = i + tmp.size();
//                 i = i + tmp.size();
//                 break;
//             }
//         }
//         else if (tmp.size() == length) // 如果窗口内的字符已经到达了最大，且不匹配，则整体往后移
//         {
//             i++;
//             start++;
//             break;
//         }
//     }
// }