#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    int FirstNotRepeatingChar(string str)
    {
        unordered_map<char, int> map(str.size());
        for (auto s : str)
        {
            map[s]++;
        }

        for (int i = 0; i < str.size(); i++)
        {
            if (map[str[i]] == 1)
                return i;
        }

        return -1;
    }
};

int main()
{
    return 0;
}