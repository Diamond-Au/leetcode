

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  double x;
  cin >> x;
  /*
    如果 x = 0.01 的话 开根号的话是0.01 不在答案的范围内 应该去 r = max(1, x);
   */
  double l = 0, r = x >= 1 ? x : 1;
  while (r - l > 1e-8)
  {
    double mid = (l + r) / 2;
    if (mid * mid >= x)
      r = mid;
    else
      l = mid;
  }

  printf("%lf\n", l);
  return 0;
}
