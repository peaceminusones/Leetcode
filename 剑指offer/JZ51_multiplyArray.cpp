#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> multiply(const vector<int> &A)
    {
        vector<int> B(A.size(), 1);
        // 先求左半边
        for (int i = 1; i < A.size(); i++)
        {
            B[i] = B[i - 1] * A[i - 1];
        }

        // 再求右半边
        int tmp = 1;
        for (int i = A.size() - 2; i >= 0; i--)
        {
            tmp *= A[i + 1];
            B[i] *= tmp;
        }

        return B;
    }
};

int main()
{
    return 0;
}