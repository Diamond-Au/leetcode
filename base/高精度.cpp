#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 比较函数
bool cmp(vector<int> &A, vector<int> &B)
{
    if (A.size() != B.size())
        return A.size() > B.size();

    for (int i = A.size() - 1; i >= 0; i--)
    {
        if (A[i] != B[i])
            return A[i] > B[i];
    }
    return true;
}

// 高精度减法
vector<int> sub(vector<int> &a, vector<int> b)
{

    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); i++)
    {
        t = a[i] - t;
        if (i < b.size())
            t -= b[i];
        c.push_back((t + 10) % 10);
        if (t < 0)
            t = 1;
        else
            t = 0;
    }

    while (c.size() > 1 && c.back() == 0)
        c.pop_back();
    return c;
}

// 高精度加法
vector<int> add(vector<int> &a, vector<int> b)
{

    vector<int> c;
    int tt = 0;
    for (int i = 0; i < a.size() || i < b.size(); i++)
    {
        if (i < a.size())
            tt += a[i];
        if (i < b.size())
            tt += b[i];
        c.push_back(tt % 10);
        tt /= 10;
    }

    if (tt)
        c.push_back(1);
    return c;
}

// 高精度乘法
vector<int> mulity(vector<int> &A, int B)
{
    int tt = 0;

    vector<int> res;
    for (int i = 0; i < A.size() || tt; i++)
    {
        if (i < A.size())
            tt += A[i] * B;
        res.push_back(tt % 10);
        tt = tt / 10;
    }

    return res;
}

//
vector<int> div(vector<int> &A, int b, int &r)
{

    vector<int> res;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        r = r * 10 + A[i];
        if (r / b != 0)
        {
            res.push_back(r / b); // 消除前导0
        }
        r = r % b;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');

    if (cmp(A, B))
    {
        vector<int> c = sub(A, B);
        for (int i = c.size() - 1; i >= 0; i--)
            printf("%d", c[i]);
    }
    else
    {
        vector<int> c = sub(B, A);
        printf("-");
        for (int i = c.size() - 1; i >= 0; i--)
            printf("%d", c[i]);
    }

    printf("\n");

    vector<int> res = add(A, B);
    for (int i = res.size() - 1; i >= 0; i--)
        printf("%d", res[i]);

    return 0;
}
