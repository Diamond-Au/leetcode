#include <iostream>
using namespace std;

int lowbit(int x)
{
    return x & -x;
}

int main()
{
    int n;
    scanf("%d", &n);
    int res = 0;
    while (n)
    {
        n = n - lowbit(n);
        res++;
    }

    return res;
}
