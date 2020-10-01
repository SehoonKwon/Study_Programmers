#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define INF (int)1e9

int V, E, P;
int dist[5001];

struct point
{
	int dest;
	int val;
	vector<int> r;
};

vector<point> v[5001];
vector<int> root[5001];

void input()
{
	cin >> V >> E >> P;
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}
}

struct cmp
{
	bool operator()(const point& u, const point& v)
	{
		if (u.val > v.val) return true;
		else return false;
	}
};

void Dijk()
{
	priority_queue<point, vector<point>, cmp> pq;
	vector<int> t;
	pq.push({ 1, 0, t });

	while (!pq.empty())
	{
		int node = pq.top().dest;
		int val = pq.top().val;
		vector<int> temp = pq.top().r;
		pq.pop();

		if (dist[node] < val) continue;
		dist[node] = min(dist[node], val);

		for (int i = 0; i < temp.size(); i++)
			root[node].push_back(temp[i]);

		if (node == V)
		{
			for (int i = 0; i < temp.size(); i++)
			{
				if (P == temp[i])
				{
					cout << "SAVE HIM";
					return;
				}
			}
		}

		for (int i = 0; i < v[node].size(); i++)
		{
			int dest = v[node][i].dest;
			int w = v[node][i].val;
			temp.push_back(node);
			pq.push({ dest, val + w, temp });
			temp.pop_back();
		}
	}

	cout << "GOOD BYE";
}

void solve()
{
	for (int i = 2; i < V + 1; i++)
		dist[i] = INF;

	Dijk();
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	solve();
	return 0;
}
