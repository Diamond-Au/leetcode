/*
  质数(素数)
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
const int N = 10010;
int primes[N], cnt;
bool st[N];

// 试除法 O(sqrt(n))
bool is_prime1(int n)
{
  if (n < 2)
    return true;

  for (int i = 2; i <= n / i; i++)
  {
    if (n % i == 0)
    {
      return false;
    }
  }
  return true;
}

// 分解质因数
// n中最多包含一个大于sqrt(n)的质因子
// n = n1 * n2 * n3

void divide(int n)
{
  for (int i = 2; i <= n / i; i++)
  {
    if (n % i == 0)
    {
      int s = 0;
      while (n % i == 0)
      {
        n /= i;
        s++;
      }
      printf("%d %d\n", i, s);
    }
  }
  if (n > 1)
    printf("%d %d\n", n, 1);

  puts(" ");
}

/*
  筛质数
  1 所有的数 从小到大 删掉所有的倍数 剩下的数就是质数
 */

void get_primes(int n)
{
  for (int i = 2; i <= n; i++)
  {
    if (!st[i])
    {
      primes[cnt++] = i;
      // 埃氏筛法
      for (int j = i + 1; j <= n; j += i)
        st[j] = true;
    }
  }
}

// 线性筛法 核心 n只会被最小的质因子筛掉
void get_primes3(int n)
{
  for (int i = 2; i <= n; i++)
  {
    if (!st[i])
      primes[cnt++] = i;
    for (int j = 0; primes[j] <= n / i; j++)
    {
      st[primes[j] * i] = true;
      if (i % primes[j] == 0)
        //  primes[j] 一定是i的最小质因子
        //  primes[j] 也一定是primes[j] * i 的最小质因子
        break;
    }
  }
}

// 试除法求约数 约数都是成对出现的 只需要枚举 "一半"就行了
vector<int> get_divisors(int n)
{
  vector<int> res;

  for (int i = 1; i <= n / i; i++)
  {
    if (n % i == 0)
    {
      res.push_back(i);
      if (i != n / i)
        res.push_back(n / i);
    }
  }
  sort(res.begin(), res.end());
}

// 约数个数

// 约数之和

// 欧几里得算法 最大公约数

int gcd(int a, int b)
{
  return b ? gcd(b, a % b) : a;
}
