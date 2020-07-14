#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
    数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字
*/

class Solution
{
public:
    int partition(vector<int> &s, int l, int r)
    {
        int mid = s[l];
        int i = l;
        int j = r;
        while (i < j)
        {
            while (i < j && s[j] >= mid) // 注意别掉了等号！还有先从右往左遍历，在从左往右遍历！即先j--，后i++
                j--;
            while (i < j && s[i] <= mid)
                i++;
            int temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
        s[l] = s[i];
        s[j] = mid;

        return i;
    }

    vector<int> quick_sort(vector<int> &s, int l, int r)
    {
        if (l < r)
        {
            int m = partition(s, l, r);
            quick_sort(s, l, m - 1); // 注意和归并排序的区别，这里需要排除掉中间的值
            quick_sort(s, m + 1, r);
        }
        return s;
    }

    // 先对数组排序，然后中位数就是我们要找的元素
    int MoreThanHalfNum_Solution1(vector<int> numbers)
    {
        vector<int> res = quick_sort(numbers, 0, numbers.size() - 1);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;

        int major = res[res.size() / 2];
        int n = 0;
        for (int i = 0; i < res.size(); i++)
            if (res[i] == major)
                n++;

        if (n > res.size() / 2)
            return major;
        else
            return 0;
    }

    // map，存储元素和出现的个数
    int MoreThanHalfNum_Solution2(vector<int> numbers)
    {
        map<int, int> n;
        map<int, int>::iterator iter; // 迭代器！！
        for (int i = 0; i < numbers.size(); i++)
        {
            iter = n.find(numbers[i]);
            if (iter != n.end())
                n[numbers[i]]++;
            else
                n.insert(pair<int, int>(numbers[i], 1));
        }

        int major = 0;
        for (map<int, int>::iterator i = n.begin(); i != n.end(); i++)
        {
            if (i->second > numbers.size() / 2)
                major = i->first;
        }
        return major;
    }

    /* 阵地攻守思想：
        一个数字作为第一个士兵，守阵地；count = 1；
        遇到相同元素，count++; 
        遇到不相同元素，即为敌人，同归于尽,count--；
        当遇到count为0的情况，又以新的i值作为守阵地的士兵，继续下去，
        到最后还留在阵地上的士兵，就是要找主元素。
    */
    int MoreThanHalfNum_Solution3(vector<int> numbers)
    {
        int major = numbers[0];
        int count = 1;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (count == 0)
            {
                count++;
                major = numbers[i];
            }
            else if (major == numbers[i])
                count++;
            else
                count--;
        }

        int c = 0;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (numbers[i] == major)
                c++;
        }
        if (c > numbers.size() / 2)
            return major;
        else
            return 0;
    }
};

int main()
{
    vector<int> v;
    int item;
    while (cin >> item)
        v.push_back(item);

    Solution s;
    int res = s.MoreThanHalfNum_Solution2(v);
    cout << res << endl;

    return 0;
}