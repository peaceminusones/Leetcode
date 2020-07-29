#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        if (sequence.empty() || sequence.size() == 0)
            return false;
        return isBST(sequence, 0, sequence.size() - 1);
    }

    bool isBST(vector<int> seq, int start, int end)
    {
        if (start >= end)
            return true;

        int rootval = seq[end];
        int i = start;
        // 定位所有比rootval小的值
        for (; i < end && seq[i] < rootval; i++)
            ;
        // 如果后面还有比它小的，就出错
        for (int j = i; j < end; j++)
        {
            if (seq[j] < rootval)
                return false;
        }

        return isBST(seq, start, i - 1) && isBST(seq, i, end - 1);
    }
};

int main()
{
    return 0;
}