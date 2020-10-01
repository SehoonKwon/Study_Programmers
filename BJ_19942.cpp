#include <iostream>
#include <cstring>
using namespace std;

int N;
int visit[16];
int mp, mf, ms, mv;
int p[16], f[16], s[16], v[16], price[16];
int MIN = (int)1e9;
int ans[16];

void DFS(int idx, int cp, int cf, int cs, int cv, int sum)
{
	if (cp >= mp && cf >= mf && cs >= ms && cv >= mv)
	{
		if (sum < MIN)
		{
			MIN = sum;
			memcpy(ans, visit, sizeof(visit));
		}
		return;
	}

	for (int i = idx; i < N; i++)
	{
		if (visit[i] == true) continue;

		visit[i] = true;
		DFS(i + 1, cp + p[i], cf + f[i], cs + s[i], cv + v[i], sum + price[i]);
		visit[i] = false;
	}
}

int main()
{
	cin >> N;
	cin >> mp >> mf >> ms >> mv;
	for (int i = 0; i < N; i++)
		cin >> p[i] >> f[i] >> s[i] >> v[i] >> price[i];

	DFS(0, 0, 0, 0, 0, 0);

	if (MIN == (int)1e9)
		cout << -1;
	else
	{
		cout << MIN << "\n";
		for (int i = 0; i < 16; i++)
			if (ans[i] == true) cout << i + 1 << " ";
	}
	return 0;
}
