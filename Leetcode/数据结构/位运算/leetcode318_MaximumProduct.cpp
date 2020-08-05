#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        vector<int> appear(words.size());
        for (int i = 0; i < words.size(); i++)
        {
            for (auto word : words[i])
            {
                appear[i] |= 1 << (word - 'a');
            }
        }

        int res = 0;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if ((appear[i] & appear[j]) == 0)
                {
                    int length = words[i].size() * words[j].size();
                    res = max(res, length);
                }
            }
        }

        return res;
    }
};

int main()
{
    vector<string> words;
    string str;
    while (cin >> str)
    {
        words.push_back(str);
        if (cin.get() == '\n')
            break;
    }

    Solution s;
    int res = s.maxProduct(words);
    cout << res << endl;

    return 0;
}