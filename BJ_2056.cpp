#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int indegree[10001];
int val[10001];
int wait[10001];
vector<int> v[10001];

struct point
{
	int Node;
	int T;
};

void input()
{
	cin >> N;
	for (int i = 1; i < N + 1; i++)
	{
		int M;
		cin >> val[i] >> M;
		indegree[i] += M;
		for (int j = 0; j < M; j++)
		{
			int b;
			cin >> b;
			v[b].push_back(i);
		}
	}
}

int topol()
{
	queue<point> q;
	for (int i = 1; i < N + 1; i++)
		if (indegree[i] == 0) q.push({ i, val[i] });

	int time = 0;
	while (!q.empty())
	{
		int X = q.front().Node;
		int t = q.front().T;
		q.pop();

		if (time < t) time = t;
		for (int i = 0; i < v[X].size(); i++)
		{
			int nx = v[X][i];
			indegree[nx]--;
			wait[nx] = max(wait[nx], t);

			if (indegree[nx] == 0)
			{
				int nt = max(wait[nx] + val[nx], t + val[nx]);
				if (time < nt) time = nt;
				q.push({ nx, nt });
			}
		}
	}
	return time;
}

void solve()
{
	cout << topol();
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	solve();
	return 0;
}
