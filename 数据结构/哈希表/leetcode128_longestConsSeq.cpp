#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> set;
        for (auto n : nums)
            set.insert(n);

        int res = 0; // 最终长度
        int cur = 0; // 当前长度
        int curnum;  // 当前num
        for (auto n : nums)
        {
            // 如果n不是当前序列的起点，则跳过，如果是起点，则进入下面的程序
            if (set.find(n - 1) == set.end())
            {
                curnum = n;
                cur = 1;

                // 从起点开始，依次加一，并判断在不在set中，如果在的话，当前长度加一
                while (set.find(++curnum) != set.end())
                {
                    cur++;
                }
                // 更新res
                res = max(res, cur);
            }
        }

        return res;
    }

    // 并查集 =================================================
    // cnt用于记录当前集合的元素个数
    unordered_map<int, int> fa, cnt;

    int find(int x)
    {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }

    int merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return cnt[x];
        // 合并，y的父节点改成x
        fa[y] = x;
        // 更新合并之后的序列长度
        cnt[x] += cnt[y];
        return cnt[x];
    }

    int longestConsecutive_djs(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        for (auto n : nums)
        {
            fa[n] = n;
            cnt[n] = 1;
        }

        int res = 1;
        for (auto n : nums)
        {
            // a.count(key)统计key值在unordered_map中出现的次数
            // 由于不允许有重复的key，所以如果key存在，则count返回1，如果不存在，则返回0
            if (n != INT_MAX && fa.count(n + 1))
                res = max(res, merge(n, n + 1));
        }

        return res;
    }
};

int main()
{
    vector<int> nums;
    int item;
    while (cin >> item)
        nums.push_back(item);

    Solution s;
    int res = s.longestConsecutive_djs(nums);
    cout << res << endl;

    return 0;
}