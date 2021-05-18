
#include <iostream>
using namespace std;

const int N = 100010;

// idx表示当前用到的点
// head 头结点的下标
int head, e[N], ne[N], idx;

void init()
{
	head = -1;
	idx = 0;
}

void add_to_head(int x)
{
	e[idx] = x;
	ne[idx] = head;
	head = idx;
	idx++;
}

void add(int k, int x)
{
	e[idx] = x;
	ne[idx] = ne[k];
	ne[k] = idx;
	idx++;
}

void remove(int k)
{
	ne[k] = ne[ne[k]];
}

int main()
{
	int m;
	cin >> m;
	init();
	while (m--)
	{
		int k, x;
		char op;
		cin >> op;
		if (op == 'H')
		{
#include <iostream>
			using namespace std;

			const int N = 100010;

			// idx表示当前用到的点
			// head 头结点的下标
			int head, e[N], ne[N], idx;

			void init()
			{
				head = -1;
				idx = 0;
			}

			void add_to_head(int x)
			{
				e[idx] = x;
				ne[idx] = head;
				head = idx;
				idx++;
			}

			void add(int k, int x)
			{
				e[idx] = x;
				ne[idx] = ne[k];
				ne[k] = idx;
				idx++;
			}

			void remove(int k)
			{
				ne[k] = ne[ne[k]];
			}

			int main()
			{
				int m;
				cin >> m;
				init();
				while (m--)
				{
					int k, x;
					char op;
					cin >> op;
					if (op == 'H')
					{
						cin >> x;
						add_to_head(x);
					}
					else if (op == 'D')
					{
						cin >> k;
						if (!k)
							head = ne[head];
						remove(k - 1);
					}
					else if (op == 'A')
					{
						cin >> k >> x;
						add(k - 1, x);
					}
				}

				for (int i = head; i != -1; i = ne[i])
					cout << e[i] << ' ';
				cout << endl;
				return 0;
			}

			cin >> x;
			add_to_head(x);
		}
		else if (op == 'D')
		{
			cin >> k;
			if (!k)
				head = ne[head];
			remove(k - 1);
		}
		else if (op == 'A')
		{
			cin >> k >> x;
			add(k - 1, x);
		}
	}

	for (int i = head; i != -1; i = ne[i])
		cout << e[i] << ' ';
	cout << endl;
	return 0;
}

#include <iostream>
using namespace std;

const int N = 100010;

int m;
int e[N], l[N], r[N], idx;

void init()
{
	// 0 左端点 1右端点
	r[0] = 1;
	l[1] = 0;
}

void add(int k, int x)
{
	e[idx] = x;
	r[idx] = r[k];
	l[idx] = k;
	l[r[k]] = idx;
	r[k] = idx;
}

// 删除第k个点
void remove(int k)
{
	r[l[k]] = r[k];
	l[r[k]] = l[k];
}

int main()
{

	return 0;
}
/*

		##栈和队列

c++
*/
/* 单调栈 */
#include <iostream>
using namespace std;

const int N = 100010;
int n;
int stk[N], tt = 0;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		while (tt && stk[tt] >= x)
		{
			tt--;
		}
		if (tt)
			cout << stk[tt] << endl;
		else
			cout << -1 << endl;
		stk[++tt] = x;
	}

	return 0;
}
/*
```

		######队列

```c++
*/
#include <iostream>
using namespace std;

const int N = 100010;
int n, k;
int a[N], q[N];
/* 单调队列 */
/* 滑动窗口最大值和最小值 */
int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	// 最小值
	int hh = 0, tt = -1;
	for (int i = 0; i < n; i++)
	{
		if (hh <= tt && i - k + 1 > q[hh])
			hh++;
		while (hh <= tt && a[q[tt]] >= a[i])
			tt--;
		q[++tt] = i;
		if (i >= k - 1)
			printf("%d", a[q[hh]]);
	}
	// 最大值
	for (int i = 0; i < n; i++)
	{
		if (hh <= tt && i - k + 1 > q[hh])
			hh++;
		while (hh <= tt && a[q[tt]] <= a[i])
			tt--;
		q[++tt] = i;
		if (i >= k - 1)
			printf("%d", a[q[hh]]);
	}
	return 0;
}
/*
```

		##KMP

				next[i] = j == == == > p[1, j] = p[i - j + 1, i]

```c++
*/
#include <iostream>
using namespace std;

using namespace std;

const int N = 1e6 + 5;
int n, m;
char p[N], s[N];
int ne[N];
int main()
{
	cin >> n >> p + 1 >> m >> s + 1;
	//求next
	for (int i = 2, j = 0; i <= n; i++)
	{
		while (p[i] != p[j + 1] && j)
			j = ne[j];
		if (p[i] == p[j + 1])
			j++;
		ne[i] = j;
	}
	//匹配
	for (int i = 1, j = 0; i <= m; i++)
	{
		while (s[i] != p[j + 1] && j)
			j = ne[j]; //必须判断j是否不等于0
		if (s[i] == p[j + 1])
			j++;
		if (j == n)
		{
			cout << i - n << " ";
			j = ne[j];
		}
	}
	return 0;
}
