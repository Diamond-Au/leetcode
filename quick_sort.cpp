#include <iostream>
using namespace std;
const int N = 1e6 + 10;

int n;
int q[N];

void quick_sort(int l, int r)
{
  if (l >= r)
  {
    return;
  }

  int x = q[(l + r) >> 1], i = l - 1, j = r + 1;
  while (l < r)
  {
    do
      i++;
    while (q[i] < x);
    do
      j--;
    while (q[j] > x);
    if (i < j)
    {
      int tem = q[i];
      q[i] = q[j];
      q[j] = tem;
    }
  }
  quick_sort(l, j);
  quick_sort(j + 1, r);
}

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &q[i]);
  }
  for (int i = 0; i < n; i++)
  {
    printf("%d", q[i]);
  }
  getchar();
  quick_sort(0, n - 1);
  for (int i = 0; i < n; i++)
  {
    printf("%d", q[i]);
  }
  return 0;
}