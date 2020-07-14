#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /*
     * 大于给定元素（target）的最小元素，如果没有，返回letters的第一个元素
    */
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int l = 0, r = letters.size() - 1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (letters[m] <= target)
                l = m + 1;
            else
                r = m - 1;
        }
        return l < letters.size() ? letters[l] : letters[0];
    }

    char nextGreatestLetter_1(vector<char> &letters, char target)
    {
        for (int i = 0; i < letters.size(); i++)
        {
            if (letters[i] > target)
                return letters[i];
        }
        return letters[0];
    }
};

int main()
{
    vector<char> letters;
    char item;
    cin >> item;
    while (item != '#')
    {
        letters.push_back(item);
        cin >> item;
    }
    cin.clear();
    cin.ignore();

    char target;
    cin >> target;

    Solution s;
    char res = s.nextGreatestLetter(letters, target);
    cout << res << endl;

    return 0;
}