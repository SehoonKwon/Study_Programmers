#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl "\n"

//문제 이해를 잘못했나??

int N, M;
int Array[10001];
int visit[10001];
int ans = 99999;

vector<int> v;

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> Array[i];
}

void calcul()
{
	int cnt = 0, sum = 0, idx = 0;
	
	for (int i = 0; i < v.size(); i++)
	{
		int dest = Array[v[i]];

		if (idx >= dest) sum += (idx - dest);
		else sum += (dest - idx);
		idx = dest;
		cnt++;

		if (i == v.size() - 1) break;

		if (cnt == M)
		{
			sum += abs(idx);
			idx = 0;
			cnt = 0;
		}
	}

	ans = min(ans, sum);
}

void DFS(int cnt)
{
	if (cnt == N)
	{
		calcul();
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (visit[i] == true) continue;

		visit[i] = true;
		v.push_back(i);
		DFS(cnt + 1);
		v.pop_back();
		visit[i] = false;
	}
}

void solve()
{
	//조합 짜서 계산
	DFS(0);

	cout << ans << endl;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	
	solve();

	return 0;
}