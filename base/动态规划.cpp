/**
 * 1 常用模型 背包问题
 * 2 线性dp
 * 3 区间dp
 */
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
int m, n;
int v[N], w[N];
int f[N][N];
/**
 * 0-1背包
 * n个物品 每个物品体积 vi 利润 wi  一个背包总容量V 挑选物品不超过背包的容量 使得利润最大
 * !每个物品最多只用一次
 */

/**
 * 分组  背包容量
 * N = 4 V= 5
 * 体积   价值
 *  1     2
 *  2     4
 *  3     4
 *  4     5
*/

// 状态表示 状态计算
/**
 * f(i,j) 集合和属性
 * 前 i个物品 总体积不超过 j
 * f(i,j)的值是最大利润
 **/

// 状态计算
/**
 * f(i,j)可分成两类
 * 本次选取第i个物品 本次不选取第i个物品
 * 如果不选的话 f(i,j) = f(i-1,j);
 * 如果选的话 f(i,j) = f(i-1, j-vi) + wi
 * 所以最大值的话就是二者的最大值
*/

// 二维数组写法
int fn1()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> v[i] >> w[i];
  }
  // f[0][0~m] = 0  没有选择物品的话 利润为0

  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j <= m; j++)
    {
      f[i][j] = f[i - 1][j];
      if (j > v[i])
      {
        f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
      }
    }
  }

  return f[n][m];
}

int fn[N];
// 一维数组写法
int fn2()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> v[i] >> w[i];
  }
  // f[0][0~m] = 0  没有选择物品的话 利润为0

  for (int i = 1; i <= n; i++)
  {
    for (int j = m; j >= v[i]; j++)
    {
      fn[j] = max(fn[j], fn[j - v[i]] + w[i]);
    }
  }

  return fn[m];
}

/**
 * 完全背包
 * n个物品 每个物品体积 vi 利润 wi  一个背包总容量V 挑选物品不超过背包的容量 使得利润最大
 * !每个物品可以使用无限次
 */

/**
 * 状态转移方程
 * f[i][j] = Math.max(f[i-1][j], f[i-1, j-k*v[i]] + k*w[i]);
*/

int fn3()
{

  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> v[i] >> w[i];
  }
  // f[0][0~m] = 0  没有选择物品的话 利润为0

  for (int i = 1; i <= n; i++)
  {
    for (int j = v[i]; j <= m; j++)
    {
      // ! 一维空间写法
      fn[j] = max(fn[j], fn[j - v[i]] + w[i]);
    }
    // for (int j = 0; j <= m; j++)
    // {
    // !朴素写法
    // for (int k = 0; k * v[i] <= j; k++)
    // {
    //   f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + w[i] * k);
    // }

    // ! 优化二维写法
    // f[i][j] = f[i - 1][j];
    // if (j > v[i])
    //   f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);

    // }
  }

  return f[n][m];
}

/**
 * 多重背包
 * n个物品 每个物品体积 vi 利润 wi  一个背包总容量V 挑选物品不超过背包的容量 使得利润最大
 * !每个物品可以使用s[i]次
 * 01:11:34
 */

/**
 * 多重背包
 * n个物品 每个物品体积 vi 利润 wi  一个背包总容量V 挑选物品不超过背包的容量 使得利润最大
 * !每个组里面的物品只能用一次
 */