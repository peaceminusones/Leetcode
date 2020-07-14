#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    /*
     * 最大堆
    */
    string frequencySort(string s)
    {
        unordered_map<char, int> record;
        unordered_map<char, int>::iterator it;
        for (int i = 0; i < s.size(); i++)
            record[s[i]]++;

        priority_queue<pair<int, char>, vector<pair<int, char>>, less<pair<int, char>>> que;
        for (it = record.begin(); it != record.end(); it++)
        {
            que.push(pair<int, char>(it->second, it->first));
        }

        string res = "";
        int len = que.size();
        for (int i = 0; i < len; i++)
        {
            int fre = que.top().first;
            while (fre--)
                res += que.top().second;
            que.pop();
        }

        return res;
    }

    /*
     * 桶排序
    */
    string frequencySort_bucket(string s)
    {
        unordered_map<char, int> record;
        unordered_map<char, int>::iterator it;
        for (int i = 0; i < s.size(); i++)
            record[s[i]]++;

        vector<vector<char>> bucket(s.size() + 1);
        for (it = record.begin(); it != record.end(); it++)
        {
            bucket[it->second].push_back(it->first);
        }

        string res;
        for (int i = bucket.size() - 1; i > 0; i--)
        {
            if (bucket[i].size() == 0)
                continue;

            for (int j = 0; j < bucket[i].size(); j++)
            {
                int len = i;
                while (len--)
                    res += bucket[i][j];
            }
        }

        return res;
    }
};

int main()
{
    string str;
    cin >> str;

    Solution s;
    string res = s.frequencySort(str);
    cout << res << endl;

    return 0;
}