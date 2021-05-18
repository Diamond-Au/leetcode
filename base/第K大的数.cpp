/*
给定一个长度为 n 的整数数列，以及一个整数 k，请用快速选择算法求出数列从小到大排序后的第 k 个数。

输入格式
第一行包含两个整数 n 和 k。

第二行包含 n 个整数（所有整数均在 1~109 范围内），表示整数数列。

输出格式
输出一个整数，表示数列的第 k 小数。

*/

#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int q[N];

int quick_sort(int l, int r, int k)
{
  if (l == r)
    return q[r];
  int x = q[l], i = l - 1, j = r + 1;

  while (i < j)
  {
    do
      i++;
    while (q[i] < x);
    do
      j--;
    while (q[j] > x);
    if (i < j)
      swap(q[i], q[j]);
  }

  int sl = j - l + 1;
  if (sl >= k)
    return quick_sort(l, j, k);

  else
    return quick_sort(j + 1, r, k - sl);
}

int main()
{
  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; i++)
    scanf("%d", &q[i]);
  int res = quick_sort(0, n - 1, m);
  printf("%d", res);

  return 0;
}
