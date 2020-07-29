#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // 大根堆
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        vector<int> res;
        if (input.empty() || k == 0 || k > input.size())
            return res;

        // 大根堆，默认就是大根堆
        priority_queue<int, vector<int>, less<int>> pq;
        int i = 0;
        for (; i < k; i++)
        {
            pq.push(input[i]);
        }

        for (; i < input.size(); i++)
        {
            if (input[i] < pq.top())
            {
                pq.pop();
                pq.push(input[i]);
            }
        }

        while (!pq.empty())
        {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }

    // 快速排序
    vector<int> GetLeastNumbers_Solution1(vector<int> input, int k)
    {
        vector<int> res;
        if (input.empty() || k == 0 || k > input.size())
            return res;

        int l = 0, r = input.size() - 1;
        int mid = partition(input, l, r);
        while (mid != k - 1)
        {
            if (mid > k - 1)
            {
                r = mid - 1;
                mid = partition(input, l, r);
            }
            if (mid < k - 1)
            {
                l = mid + 1;
                mid = partition(input, l, r);
            }
        }

        res.assign(input.begin(), input.begin() + k);

        return res;
    }

    int partition(vector<int> &input, int l, int r)
    {
        int mid = input[l];
        int i = l, j = r;
        while (i < j)
        {
            while (i < j && input[j] >= mid)
                j--;
            while (i < j && input[i] <= mid)
                i++;

            swap(input[i], input[j]);
        }

        swap(input[i], input[l]);
        return i;
    }
};

int main()
{
    vector<int> input;
    int item;
    while (cin >> item)
    {
        input.push_back(item);
        if (cin.get() == '\n')
            break;
    }

    int k;
    cin >> k;

    Solution s;
    vector<int> res = s.GetLeastNumbers_Solution1(input, k);
    for (auto r : res)
        cout << r << " ";
    return 0;
}