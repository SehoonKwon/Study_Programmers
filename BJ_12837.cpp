#include <iostream>
using namespace std;

#define ll long long

int N, M;
ll Node[1000001];

void input()
{
	cin >> N >> M;
}

void update(int v, ll val)
{
	while (v <= N)
	{
		Node[v] += val;
		v += (v&-v);
	}
}

ll sum(int v)
{
	ll res = 0;
	while (v > 0)
	{
		res += Node[v];
		v -= (v&-v);
	}

	return res;
}

void solve()
{
	while (M--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			update(b, c);
		}
		else
		{
			cout << sum(c) - sum(b - 1) << "\n";
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	solve();
	return 0;
}
