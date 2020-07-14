#include <iostream>
#include <vector>
using namespace std;

/*归并排序的改进*/

class Solution
{
    int count = 0;

public:
    void merge(vector<int> &data, int l, int m, int r)
    {
        vector<int> ndata;
        int i = l, j = m + 1;
        while (i <= m && j <= r)
        {
            if (data[i] > data[j])
            {
                ndata.push_back(data[i++]);
                count = (count + r - j + 1) % 1000000007;
            }
            else
                ndata.push_back(data[j++]);
        }

        while (i <= m)
            ndata.push_back(data[i++]);
        while (j <= r)
            ndata.push_back(data[j++]);

        for (int i = 0; i < ndata.size(); i++)
        {
            data[l + i] = ndata[i];
            cout << ndata[i] << " ";
        }
        cout << endl;
    }

    void merge_sort(vector<int> &data, int l, int r)
    {
        if (l < r)
        {
            int mid = (r + l) / 2;
            merge_sort(data, l, mid);
            merge_sort(data, mid + 1, r);
            merge(data, l, mid, r);
        }
    }

    int InversePairs(vector<int> &data)
    {
        if (data.size() == 0)
            return 0;
        merge_sort(data, 0, data.size() - 1);
        // for (int i = 0; i < data.size(); i++)
        //     cout << data[i] << " ";
        return count;
    }
};

int main()
{
    vector<int> data;
    int item;
    while (cin >> item)
        data.push_back(item);

    Solution s;
    int res = s.InversePairs(data);
    cout << endl;
    cout << res;
    return 0;
}