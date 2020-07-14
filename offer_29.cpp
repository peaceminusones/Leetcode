#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // void merge(vector<int> &res, int l, int m, int r)
    // {
    //     vector<int> nres;
    //     int i = l;
    //     int j = m + 1;
    //     while (i <= m && j <= r)
    //     {
    //         if (res[i] <= res[j])
    //             nres.push_back(res[i++]);
    //         else
    //             nres.push_back(res[j++]);
    //     }
    //     while (i <= m)
    //         nres.push_back(res[i++]);
    //     while (j <= r)
    //         nres.push_back(res[j++]);

    //     for (int i = 0; i < nres.size(); i++)
    //         res[l + i] = nres[i];
    // }

    // void merge_sort(vector<int> &res, int l, int r)
    // {
    //     if (l < r)
    //     {
    //         int m = (l + r) / 2;
    //         merge_sort(res, l, m);
    //         merge_sort(res, m + 1, r);
    //         merge(res, l, m, r);
    //     }
    // }

    // vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    // {
    //     vector<int> res;
    //     if (input.empty() || k > input.size())
    //         return res;

    //     merge_sort(input, 0, input.size() - 1);

    //     for (int i = 0; i < k; i++)
    //         res.push_back(input[i]);

    //     return res;
    // }

    // 交换函数
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    // 对于第i个结点，下沉
    void maxHeap(vector<int> &heap, int i, int n)
    {
        // int l = 2 * i + 1;
        // int r = 2 * i + 2;
        // int largest = i;

        // if (l <= n && heap[l] > heap[largest])
        //     largest = l;
        // if (r <= n && heap[r] > heap[largest])
        //     largest = r;
        // if (largest != i)
        // {
        //     swap(heap[i], heap[largest]);
        //     i = largest;
        //     maxHeap(heap, i, n);
        // }
        while (2 * i + 1 <= n) // 左孩子结点在范围内
        {
            int next = 2 * i + 1;

            if (next + 1 <= n && heap[next + 1] > heap[next]) // 如果右孩子结点在范围内，且值大于左孩子，则更新位置
                next++;

            if (heap[i] < heap[next])      // 如果父节点的值小于孩子结点
                swap(heap[i], heap[next]); // 交换

            i = next; // 位置i变成孩子结点的位置
        }
    }

    // 从最后一个非叶子结点开始，把大的值往上替换，小值往下替换
    void buildMaxHeap(vector<int> &heap, int n)
    {
        for (int i = (n - 1) / 2; i >= 0; i--)
            maxHeap(heap, i, n);
    }

    // 堆排序
    // 将堆顶元素（最大值）与最后一个值交替
    // 然后对除了这个最大值的其他元素，重新建立最大堆
    // 循环
    void heap_sort(vector<int> &heap)
    {
        for (int i = heap.size() - 1; i >= 0; i--)
        {
            swap(heap[0], heap[i]);
            maxHeap(heap, 0, i - 1);
        }
    }

    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        if (input.empty() || k < 0)
            return input;
        if (k > input.size() - 1)
        {
            heap_sort(input);
            return input;
        }

        // 先对前k个元素简历最大堆
        vector<int> res(input.begin(), input.begin() + k);
        buildMaxHeap(res, res.size() - 1);

        // 从k+1个元素开始
        // 如果比堆顶元素小，则把堆顶元素替换下来
        // 修正最大堆
        // 最后最大堆中剩下的就是最小的k个元素
        for (int i = k; i < input.size(); i++)
        {
            if (input[i] < res[0])
            {
                res.push_back(input[i]);
                int m = res.size() - 1;
                swap(res[0], res[m]);
                res.pop_back();
                buildMaxHeap(res, res.size() - 1);
            }
        }
        // 堆排序
        heap_sort(res);

        return res;
    }
};

int main()
{
    vector<int> input;
    int item;
    while (cin >> item)
        input.push_back(item);
    cin.clear();
    cin.ignore();

    int k;
    cin >> k;

    Solution s;
    vector<int> res = s.GetLeastNumbers_Solution(input, k);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}