#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> multiply(const vector<int> &A)
    {
        // 利用上下三角连乘
        vector<int> B;
        if (A.empty())
            return B;
        // 先求下三角
        B.push_back(1); //B[0] = 1;
        for (int i = 1; i < A.size(); i++)
        {
            B.push_back(B[i - 1] * A[i - 1]);
        }

        // 再把上三角考虑进去
        int temp = 1;
        for (int i = A.size() - 1; i >= 0; i--)
        {
            B[i] *= temp;
            temp *= A[i];
        }
        return B;
    }
};

int main()
{
    vector<int> A;
    int item;
    while (cin >> item)
    {
        A.push_back(item);
    }
    cin.ignore();
    cin.clear();

    Solution s;
    vector<int> B = s.multiply(A);
    for (int i = 0; i < A.size(); i++)
        cout << B[i] << endl;

    return 0;
}