
#include <iostream>
using namespace std;

// 一维数组 前缀和模板
const int N = 1e6 + 10;
const int N2 = 1010;
int n, m;
int a[N], s[N];
int aa[N2][N2], s[N2][N2];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i]; // 前缀和

	while (m--)
	{
		int l, r;
		cin >> l >> r;

		printf("%d\n", s[r] - s[r - 1]); // 区间和的计算
	}

	return 0;
}

// 二维数组前缀和
const int N2 = 1010;
int aa[N2][N2], ss[N2][N2];
int sum()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> aa[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			ss[i][j] = ss[i - 1][j] + ss[i][j - 1] - ss[i - 1][j - 1] + aa[i][j]; // 求前缀和
		}
	}

	return 0;
}

