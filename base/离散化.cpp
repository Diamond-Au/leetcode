
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e5 * 3 + 10;
typedef pair<int, int> PII;

int n, m;
int a[N], s[N];

vector<int> alls;
vector<PII> adds, query;

int find(int x)
{
	int l = 0, r = alls.size() - 1;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (alls[mid] > x)
			r = mid;
		else
			l = mid + 1;
	}

	return r + 1;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int x, c;
		cin >> x >> c;
		adds.push_back({x, c});
		alls.push_back(x);
	}

	for (int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r;
		query.push_back({l, r});
		alls.push_back(l);
		alls.push_back(r);
	}

	// 去重
	sort(alls.begin(), alls.end());
	alls.erase(unique(alls.begin(), alls.end()), alls.end());

	for (auto item : adds)
	{
		int x = find(item.first);
		a[x] += item.second;
	}

	// 处理前缀和

	for (int i = 1; i <= alls.size(); i++)
		s[i] = s[i - 1] + a[i];

	// 询问

	for (auto item : query)
	{
		int l = item.first, r = item.second;
		cout << s[r] - s[l - 1] << endl;
	}

	return 0;
}
