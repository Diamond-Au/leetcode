
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int a[N], b[N];
int n, m;

void insert(int l, int r, int c)
{
  b[l] += c;
  b[r + 1] -= c;
}

int main()
{

  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  for (int i = 1; i <= n; i++)
    insert(i, i, a[i]);

  while (m--)
  {
    int l, r, c;
    cin >> l >> r >> c;
    insert(l, r, c);
  }
  for (int i = 1; i <= n; i++)
    b[i] += b[i - 1];

  for (int i = 1; i <= n; i++)
    cout << b[i] << " ";
  cout << endl;
  return 0;
}
