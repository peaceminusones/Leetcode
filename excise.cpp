#include <iostream>
#include <vector>
#include <set>
#include <list>
using namespace std;

class mystruct
{
private:
    int a;    // 4
    char b;   // 1
    double c; // 8
    char d;   // 1
};

int i = 5;

int check_sys()
{
    int i = 1;
    return *(char *)&i; // 取出当前指针指向的一个字节
}

int main()
{
    // int res = check_sys();
    // if (res == 1) // 如果取出来是1，说明1存储在低地址（小端）
    // {
    //     cout << "small" << endl;
    // }
    // else // 如果取出来是0，说明1存储在高地址（大端）
    // {
    //     cout << "big" << endl;
    // }

    set<int> s = new Set();

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define INF 0x7fffffff
// #define MAXN 100010
// struct node
// {
//     int x;
//     int y;
// } s1[MAXN], s2[MAXN];

// bool cmp(node a, node b)
// {
//     return a.y < b.y;
// }

// int main()
// {
//     int n, m, t;
//     scanf("%d %d %d", &n, &m, &t);

//     for (int i = 0; i < n; ++i)
//     {
//         scanf("%d %d", &s1[i].x, &s1[i].y);
//     }
//     for (int i = 0; i < m; ++i)
//     {
//         scanf("%d %d", &s2[i].x, &s2[i].y);
//     }

//     sort(s2, s2 + m, cmp);
//     int ans = INF;
//     for (int i = 0; i < n; ++i)
//     {
//         int L = 0, R = m - 1, mid;
//         while (R - L >= 0)
//         {
//             mid = (L + R) / 2;
//             if (s2[mid].y + s1[i].y >= t)
//                 R = mid - 1;
//             else
//                 L = mid + 1;
//         }

//         for (int j = R; j < m; ++j)
//         {
//             if (s2[j].y + s1[i].y >= t)
//                 ans = min(ans, s2[j].x + s1[i].x);
//         }
//     }

//     for (int i = 0; i < n; ++i)
//     {
//         if (s1[i].y >= t)
//             ans = min(ans, s1[i].x);
//     }
//     for (int i = 0; i < m; ++i)
//     {
//         if (s2[i].y >= t)
//             ans = min(ans, s2[i].x);
//     }
//     if (t == 0)
//         printf("0\n");
//     else if (ans != INF)
//         printf("%d\n", ans);
//     else
//         printf("-1\n");
//     return 0;
// }

