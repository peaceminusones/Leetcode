/*
    offer 11 -----------------------------------------------
*/
// #include <iostream>
// using namespace std;

// class Solution
// {
// public:
//     int NumberOf1(int n)
//     {
//         int count = 0;
//         while (n != 0)
//         {
//             count++;
//             n = n & (n - 1);
//             cout << n << endl;
//         }
//         return count;
//     }
// };

// int main()
// {
//     Solution s;
//     int n;
//     cin >> n;
//     int results = s.NumberOf1(n);
//     cout << results << endl;
// }

/*
    offer 12 -----------------------------------------------
*/
// #include <iostream>
// using namespace std;

// class Solution
// {
// public:
//     double Power(double base, int exponent)
//     {
//         double result = 1.0;
//         int n = exponent;
//         if (exponent < 0)
//         {
//             if (base == 0)
//             {
//                 cout << "error denominator" << endl;
//                 return 0;
//             }
//             n = -exponent;
//         }
//         else if (exponent == 0)
//         {
//             return 1;
//         }
//         while (n != 0)
//         {
//             if (n & 1 == 1)
//             {
//                 result *= base;
//             }
//             n >>= 1;
//             base *= base;
//         }
//         cout << result << endl;
//         return exponent > 0 ? result : (1 / result);
//     }
// };

// int main()
// {
//     Solution s;
//     double n;
//     int m;
//     // cin >> n >> m;
//     n = 4.0;
//     m = -2;
//     double results = s.Power(n, m);
//     cout << results << endl;
// }

/*
    offer 13 -----------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void reOrderArray(vector<int> &array)
    {
        vector<int> b;
        int i = 0;
        while (i < array.size())
        {
            if (array[i] % 2 == 0)
            {
                b.push_back(array[i]);
                array.erase(array.begin() + i);
            }
            else
            {
                i++;
            }
        }
        cout << endl;
        array.insert(array.end(), b.begin(), b.end());
    }
};

int main()
{
    Solution s;
    vector<int> a;
    int n;
    cin >> n;
    int b;
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        a.push_back(b);
    }
    if (a.size() > 0)
    {
        s.reOrderArray(a);
    }
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}