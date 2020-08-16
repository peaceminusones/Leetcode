#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxtimeval(vector<int> video, int ad)
    {
        sort(video.begin(), video.end());
        if (video.empty())
            return 0;
        if (video.size() == 1 && video[0] <= ad)
            return 0;

        int num = ad / video.size();   // 每个视频里最少放多少个广告
        int carry = ad % video.size(); // 多出来的
        if (carry == 0)
        {
            
        }
    }
};

int main()
{
    return 0;
}