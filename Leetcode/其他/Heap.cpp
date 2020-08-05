#include <iostream>
#include <vector>
using namespace std;

// 最大堆
class Heap
{
private:
    int size;
    vector<int> q;

public:
    Heap() : size(0) {}
    Heap(int i, vector<int> r) : size(i), q(r) {}

    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    // 上浮
    void shift_up(int i, vector<int> &q)
    {
        if (q.empty())
            return;

        while (i > 0 && i < q.size()) // 要上浮的位置在范围内
        {
            if (q[i] > q[(i - 1) >> 1]) // 当前位置i的值大于它父节点的值
            {
                swap(q[i], q[(i - 1) >> 1]); // 交换！
            }
            i = (i - 1) / 2; // 位置i变成父节点的位置
        }
    }

    // 下沉
    void shift_down(int i, vector<int> &q)
    {
        if (q.empty())
            return;

        while (2 * i + 1 < q.size()) // 左孩子结点在范围内
        {
            int next = 2 * i + 1;

            if (next + 1 < q.size() && q[next + 1] > q[next]) // 如果右孩子结点在范围内，且值大于左孩子，则更新位置
                next++;

            if (q[i] < q[next])      // 如果父节点的值小于孩子结点
                swap(q[i], q[next]); // 交换

            i = next; // 位置i变成孩子结点的位置
        }
    }

    // 往堆中插入元素
    void insert(int value, vector<int> &q)
    {
        q.push_back(value);
        shift_up(q.size() - 1, q);
    }

    // pop出堆顶
    void pop(vector<int> &q)
    {
        if (q.empty())
            return;

        int len = q.size() - 1;
        swap(q[0], q[len]); // 交换堆顶和最后一个元素
        q.pop_back();       // 把最后一个元素pop出去
        shift_down(0, q);   // 下沉堆顶
    }

    // 最大根，当前结点i，上浮
    void maxHeap(vector<int> &q, int i, int n)
    {
        int l = 2 * i + 1; // 左结点位置
        int r = 2 * i + 2; // 右节点位置

        int largest = i; // 设当前最大值的位置为根节点i

        // 如果左结点在范围内，且值大于根结点的值，则更新largest
        if (l <= n && q[l] > q[largest])
            largest = l;

        // 如果右结点在范围内，且值大于根结点（或左结点）的值，则更新largest
        if (r <= n && q[r] > q[largest])
            largest = r;

        // 如果最大值不是最初的根结点的位置，则交换
        // 然后继续对交换后的位置进行相同的操作，直到叶子结点，不能再操作
        if (largest != i)
        {
            swap(q[i], q[largest]);
            i = largest;
            maxHeap(q, i, n);
        }
    }

    // 创建最大堆
    void buidMaxHeap1(vector<int> &q, int n)
    {
        for (int i = (n - 1) / 2; i >= 0; i--) // 从最后一个非叶子结点开始
            maxHeap(q, i, n);                  // 递归方法
    }

    // 创建最大堆
    void buidMaxHeap2(vector<int> &q, int n)
    {
        for (int i = (n - 1) / 2; i >= 0; i--) // 从最后一个非叶子结点开始
            shift_down(i, q);                  // 非递归方法
    }

    // 堆排序
    vector<int> heap_sort(vector<int> q)
    {
        int n = q.size() - 1;
        // buidMaxHeap(q, n); // 创建最大堆（递归方法）
        buidMaxHeap2(q, n); // 创建最大堆（非递归方法）

        for (int i = n; i >= 0; i--)
        {
            swap(q[0], q[i]);
            maxHeap(q, 0, i - 1);
        }
        return q;

        // vector<int> res;
        // for (int i = n; i >= 0; i--)
        // {
        //     res.push_back(q[0]);
        //     swap(q[0], q[i]);
        //     q.pop_back();
        //     shift_down(0, q);
        // }
        // return res;
    }

    void merge(vector<int> &res, int l, int m, int r)
    {
    }
};

int main()
{
    vector<int> res;
    int item;
    while (cin >> item)
        res.push_back(item);

    Heap *h = new Heap(res.size(), res);

    // vector<int> q1 = h->shift_up(3, res);
    // for (int i = 0; i < q1.size(); i++)
    //     cout << q1[i] << " ";
    // cout << endl;

    // vector<int> q2 = h->shift_down(1, res);
    // for (int i = 0; i < q2.size(); i++)
    //     cout << q2[i] << " ";
    // cout << endl;

    // vector<int> q3 = h->insert(10, res);
    // for (int i = 0; i < q3.size(); i++)
    //     cout << q3[i] << " ";

    // vector<int> q4 = h->del_top(res);
    // for (int i = 0; i < q4.size(); i++)
    //     cout << q4[i] << " ";

    vector<int> q5 = h->heap_sort(res);
    for (int i = 0; i < q5.size(); i++)
        cout << q5[i] << " ";

    return 0;
}
