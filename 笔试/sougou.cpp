#include <bits/stdc++.h>
using namespace std;

int numberofPrice(int a, int b, int c)
{
    vector<int> num = {a, b, c};
    sort(num.begin(), num.end());
    while (num[2] - num[0] > 1)
    {
        if (num[2] - num[1] <= 1)
        {
            num[2]--;
            num[1]--;
            num[0]++;
        }
        else if (num[2] - num[1] > 1)
        {
            num[2] -= 2;
            num[0]++;
        }
        sort(num.begin(), num.end());
    }
    return num[0];
}

// void test(char str[5])
// {
//     cout << sizeof(str) << strlen(str) << endl;
// }

struct obj
{
    // char a;
    // uint32_t b;
    // uint8_t c;
    uint64_t d[0];
};

int main()
{
    // int a, b, c;
    // cin >> a >> b >> c;
    // cout << numberofPrice(a, b, c) << endl;
    // int i = 1;
    // printf("%d, %d\n", ++i, ++i);
    // printf("%d, %d\n", ++i, i++);
    // // cout << ++i <<" "<< ++i << endl;
    // // cout << ++i << " " << i++ << endl;
    // return 0;
    // printf("%s", 5 + "cmcc-iot");
    // char str[] = "hello";
    // test(str);
    // int (*n)[10];
    // cout<<sizeof(n)<<endl;
    // int a[4] = {0};
    // cout<<a[1]<<endl;
    cout<<sizeof(obj)<<endl;
    return 0;
}