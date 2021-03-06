/*双指针算法

> O(N^2) ------> O(N)

```c++
// 最简单的例子
*/
#include <iostream>
using namespace std;

int main()
{
	char str[1000];
	gets(str);
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		int j = i;
		while (j < len && str[i] != ' ')
			j++;

		for (int k = i; k < j; k++)
			cout << str[i];

		cout << endl;
		i = j;
	}
}

const int N = 1e6 + 10;
int n;
int a[N], s[N];

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int res = 0;
	for (int i = 0, j = 0; j < n; i++)
	{
		s[a[i]]++;
		while (s[a[i]] > 1)
		{
			s[s[j]]--;
			j++;
		}

		res = res > i - j + 1 ? res : i - j + 1;
	}

	return res;
}
