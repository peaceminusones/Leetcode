#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxsquare(vector<int> arr)
    {
        int max = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            int h = arr[i];
            int l = i - 1, r = i + 1;
            int w = 1;
            while (l >= 0)
            {
                if (arr[l] >= arr[i])
                    l--;
                else
                    break;
            }
            while (r < arr.size())
            {
                if (arr[r] >= arr[i])
                    r++;
                else
                    break;
            }
            w = r - l - 1;
            if (w * h > max)
                max = w * h;
        }
        return max;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    int item;
    for (int i = 0; i < n; i++)
    {
        cin >> item;
        arr.push_back(item);
    }

    Solution s;
    int res = s.maxsquare(arr);
    cout << res << endl;
    return 0;
}