#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    bool duplicate(int numbers[], int length, int *duplication)
    {
        for (int i = 0; i < length; i++)
        {
            while (numbers[i] != i)
            {
                if (numbers[i] != numbers[numbers[i]])
                    swap(numbers[i], numbers[numbers[i]]);
                else
                {
                    *duplication = numbers[i];
                    return true;
                }
            }
        }
        return false;
    }

    bool duplicate_set(int numbers[], int length, int *duplication)
    {
        set<int> s;
        for (int i = 0; i < length; i++)
        {
            if (s.find(numbers[i]) == s.end())
                s.insert(numbers[i]);
            else
            {
                *duplication = numbers[i];
                return true;
            }
        }

        return false;
    }
};

int main()
{
    int n;
    cin >> n;

    int *numbers = new int(n);
    int item;
    for (int i = 0; i < n; i++)
    {
        cin >> item;
        *(numbers + i) = item;
    }

    int res;

    Solution s;
    cout << s.duplicate(numbers, n, &res) << endl;
    cout << res << endl;
    return 0;
}