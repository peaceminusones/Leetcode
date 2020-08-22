#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Solution
{
public:
    int rand10()
    {
        while (true)
        {
            int a = rand7();           // rand7
            int b = rand7();           // rand7
            int num = (a - 1) * 7 + b; // rand49
            if (num <= 40)
                return num % 10 + 1;

            a = num - 40;          // rand9
            b = rand7();           // rand7
            num = (a - 1) * 7 + b; // rand63
            if (num <= 60)
                return num % 10 + 1;

            a = num - 60;          //rand3
            b = rand7();           // rand7
            num = (a - 1) * 7 + b; //rand21
            if (num <= 20)
                return num % 10 + 1;
        }
    }

    int rand7()
    {
        srand(int(time(0)));
        return rand() % 7 + 1;
    }
};

int main()
{
    Solution s;
    cout << s.rand10() << endl;
    return 0;
}