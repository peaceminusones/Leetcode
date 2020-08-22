#include <bits/stdc++.h>

static int a[2048] = {1};

void func(int a)
{
    std::cout << "a" << std::endl;
}

void func(double b)
{
    std::cout << "b" << std::endl;
}

int main()
{
    func(1.0f);
    return 0;
}