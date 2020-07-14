#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n == 0 || m == 0)
            return -1;

        if (n == 1)
            return 0;
        else
            return (LastRemaining_Solution(n - 1, m) + m) % n;
    }

    int LastRemaining_Solution1(int n, int m)
    {
        if (n == 0 || m == 0)
            return -1;
        vector<int> array;
        int i = 0;
        while (i++ < n)
            array.push_back(i);
        int step = 0;
        i = -1;
        while (n > 0)
        {
            i++;
            if (i >= n)
                i = 0;
            if (array[i] == -1)
                continue;
            step++;
            if (step == m)
            {
                array[i] = -1;
                step = 0;
                n--;
            }
        }
        return i;
    }
};

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    Solution s;
    int res = s.LastRemaining_Solution1(n, m);
    cout << res << endl;
    return 0;
}