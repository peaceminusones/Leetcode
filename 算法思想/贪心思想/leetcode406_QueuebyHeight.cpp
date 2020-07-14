#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /*
     * 贪婪策略（优先选择最高的人）
     * 先排序，再插入
     * 一个学生用(h,k)描述：
     *     h: 身高
     *     k: 排在他前面的有k个学生的身高比他高或者和他一样高
     * 
     * 方法：
     *     1、先把people按照身高降序排序，如果身高相同，按照k升序排序
     *     2、将最高的人按照k值升值排序，然后将他们放置到输出队列中与k值相等的索引位置上
     *     3、按照降序取下一个身高，同样按照k值对该身高的人升序排序，然后逐个插入到输入队列中与k值相等的索引位置上
    */
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        if (people.size() == 0)
            return people;

        sort(people.begin(), people.end(), cmp); // 按照身高降序排序，如果身高相同，按照k升序排序
        // for (int i = 0; i < people.size(); i++)
        //     cout << people[i][0] << " " << people[i][1] << endl;

        vector<vector<int>> res;
        for (int i = 0; i < people.size(); i++)
        {
            res.insert(res.begin() + people[i][1], people[i]);
        }

        for (int i = 0; i < res.size(); i++)
            cout << res[i][0] << " " << res[i][1] << endl;

        return people;
    }

    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0]; // 如果身高相等，就按照k升序排序，如果身高不等，就按照身高降序排序
    }
};

int main()
{
    vector<vector<int>> peoples;
    int item1, item2;
    while (cin >> item1 >> item2)
    {
        vector<int> people;
        people.push_back(item1);
        people.push_back(item2);
        peoples.push_back(people);
    }

    Solution s;
    vector<vector<int>> res = s.reconstructQueue(peoples);
    // for (int i = 0; i < res.size(); i++)
    //     cout << res[i][0] << " " << res[i][1] << endl;

    return 0;
}