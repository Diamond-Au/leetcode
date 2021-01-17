/*
给定一个长度为n的整数数列，请你计算数列中的逆序对的数量。

逆序对的定义如下：对于数列的第 i 个和第 j 个元素，如果满足 i < j 且 a[i] > a[j]，则其为一个逆序对；否则不是。

输入格式
第一行包含整数n，表示数列的长度。

第二行包含 n 个整数，表示整个数列。

输出格式
输出一个整数，表示逆序对的个数。
 */
#include <iostream>
using namespace std;

typedef long long LL;
const int N = 1e6 + 10;
int n;
int q[N], tem[N];

LL merge_sort(int l, int r)
{
  if (l >= r)
  {
    return 0;
  }

  int mid = (l + r) >> 1;
  LL res = merge_sort(l, mid) + merge_sort(mid + 1, r);

  int i = l, j = mid + 1, k = 0;
  while (i <= mid && j <= r)
  {
    if (q[i] <= q[j])
    {
      tem[k++] = q[i++];
    }
    else
    {
      tem[k++] = q[j++];
      res += mid - i + 1;
    }
  }
  while (i <= mid)
  {
    tem[k++] = q[i++];
  }
  while (j <= r)
  {
    tem[k++] = q[j++];
  }

  for (int i = l, j = 0; i <= r; i++, j++)
  {
    q[i] = tem[j];
  }
  return res;
}

int main(int argc, char const *argv[])
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> q[i];
  }

  cout << merge_sort(0, n - 1);
  return 0;
}
