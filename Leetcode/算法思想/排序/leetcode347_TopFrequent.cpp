#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// struct cmp
// {
//     bool operator()(const pair<int, int> p1, const pair<int, int> p2)
//     {
//         return p1.second < p2.second;
//     }
// };

class Solution
{
public:
    /*
     * 桶排序
     * 设置若干个桶，每个桶存储出现频率相同的数
     * 桶的小标表示数出现的频率，即第i个桶中存储的数出现的频率为i
     * 把数都放到桶之后，从后往前遍历桶，最先得到的k个数，就是出现频率最多的k个数
    */
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> res;                // 用于记录结果（即出现频率前k高的元素）
        unordered_map<int, int> record; // 字典：{数：出现频率}
        unordered_map<int, int>::iterator it;
        for (int i = 0; i < nums.size(); i++) // 遍历所有数，记录每个数出现的频率
            record[nums[i]]++;

        // 创建一个桶，一维下标表示当前这个桶内数据出现的频率
        // 例如在bucket[i] 中存储的所有数，都是出现过i次的
        vector<vector<int>> bucket(nums.size() + 1);
        for (it = record.begin(); it != record.end(); it++)
        {
            bucket[it->second].push_back(it->first); // 遍历字典，把数放入相应出现过的频率的桶中
        }

        // for (int i = 0; i < bucket.size(); i++)
        // {
        //     for (int j = 0; j < bucket[i].size(); j++)
        //         cout << bucket[i][j] << " ";
        //     cout << endl;
        // }

        // 从后到前遍历桶
        // 如果当前桶中没有数据，则跳过
        // 如果有数据，则先判断前k个位置还剩几个，然后把相应的结果放入res中
        for (int i = bucket.size() - 1; i > 0 && res.size() < k; i--)
        {
            if (bucket[i].size() == 0)
                continue;

            if (bucket[i].size() <= k - res.size()) // 当前桶中的数据可以全部放入到res中
            {
                int len = 0;
                while (len < bucket[i].size())
                    res.push_back(bucket[i][len++]);
            }
            else // 当前桶中的数据只有部分可以放入到res中
            {
                int len = 0;
                while (len <= k - res.size())
                    res.push_back(bucket[i][len++]);
            }
        }

        return res;
    }

    /*
     * 最小堆
    */
    vector<int> topKFrequent_queue(vector<int> &nums, int k)
    {
        unordered_map<int, int> record; // 字典：{数：出现频率}
        unordered_map<int, int>::iterator it;
        for (int i = 0; i < nums.size(); i++) // 遍历所有数，记录每个数出现的频率
            record[nums[i]]++;

        // 存储pair的最小堆，按照第一个数排序
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        for (it = record.begin(); it != record.end(); it++)
        {
            if (que.size() < k) // 如果堆还没满k个，则直接放入
            {
                // cout << "(" << it->first << ":" << it->second << ")" << endl;
                que.push(pair<int, int>(it->second, it->first)); // 第一个位置放出现频率，第二个位置放数的值（和map中相反）
            }
            else if (it->second > que.top().first)
            {
                // 如果堆满了k个，因为堆是按照出现频率从小到大达排序的
                // 所以与堆顶的出现频率比较，如果大与出现频率，则把堆顶pop出来，把新的pair push进去
                // cout << "(" << it->first << ":" << it->second << ") (" << que.top().second << ":" << que.top().first << ")" << endl;
                que.pop();
                que.push(pair<int, int>(it->second, it->first));
            }
        }

        vector<int> res; // 存储最终结果
        int len = que.size();
        for (int i = 0; i < len; i++)
        {
            res.push_back(que.top().second); // 把堆中每个pair的第二个（即数的值）拿出来，存储到res中
            que.pop();
        }

        return res;
    }
};

int main()
{
    vector<int> nums;
    int item;
    while (cin >> item)
    {
        nums.push_back(item);
    }
    cin.clear();
    cin.ignore();

    int k;
    cin >> k;

    Solution s;
    vector<int> res = s.topKFrequent_queue(nums, k);
    // for (int i = 0; i < res.size(); i++)
    //     cout << res[i] << " ";

    return 0;
}