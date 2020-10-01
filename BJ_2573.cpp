#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

//20.09.27

int N, M;
int Array[301][301];
int visit[301][301];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int No_ice;

struct point
{
	int x;
	int y;
};

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Array[i][j];
			if (No_ice == 0 && Array[i][j] > 0) No_ice = 1;
		}
	}
}

void BFS(int x, int y)
{
	queue<point> q;
	visit[y][x] = true;
	q.push({ x, y });

	while (!q.empty())
	{
		int X = q.front().x;
		int Y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = X + dx[i];
			int ny = Y + dy[i];

			if (nx > -1 && nx < M && ny > -1 && ny < N)
			{
				if (Array[ny][nx] > 0)
				{
					Array[ny][nx]--;
					if (Array[ny][nx] == 0) visit[ny][nx] = true;
				}
				else if (Array[ny][nx] == 0 && visit[ny][nx] == false)
				{
					visit[ny][nx] = true;
					q.push({ nx, ny });
				}
			}
		}
	}
}

void DFS(int x, int y)
{
	if (visit[y][x] == true) return;
	visit[y][x] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx > -1 && nx < M && ny > -1 && ny < N)
			if(visit[ny][nx] == false && Array[ny][nx] > 0)
				DFS(nx, ny);
	}
}

void solve()
{
	if (No_ice == 0)
	{
		cout << 0;
		return;
	}

	int time = 0;
	while (1)
	{
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (visit[i][j] == false && Array[i][j] == 0)
					BFS(j, i);
			}
		}

		time++;
		memset(visit, 0, sizeof(visit));
		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (visit[i][j] == false && Array[i][j] > 0)
				{
					cnt++;
					if (cnt == 2)
					{
						cout << time;
						return;
					};
					DFS(j, i);
				}
			}
		}
		if (cnt == 0)
		{
			cout << 0;
			return;
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
