#include <iostream>
#include <vector>
using namespace std;

class mystruct
{
private:
    int a;    // 4
    char b;   // 1
    double c; // 8
    char d;   // 1
};

int main()
{
    cout << sizeof(mystruct) << endl;
    return 0;
}