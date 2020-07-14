#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Hammingdistance(int x, int y)
{
    int n = x ^ y;
    int count = 0;
    while (n)
    {
        count++;
        n = n & (n - 1);
    }
    return count;
}

int max_Hamming(vector<int> arr)
{
    vector<int> dis;
    for (int i = 0; i < arr.size(); i++)
        for (int j = i + 1; j < arr.size(); j++)
            dis.push_back(Hammingdistance(arr[i], arr[j]));

    return *max_element(dis.begin(), dis.end());
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    int item;
    while (cin >> item)
        arr.push_back(item);
    int res = max_Hamming(arr);
    cout << res << endl;
    return 0;
}