#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N;
int Array[51][51];
int visit[51][51];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

struct point
{
	int x;
	int y;
	int cnt;
};

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%1d", &Array[i][j]);
}

void BFS()
{
	queue<point> q;
	q.push({ 0, 0, 0 });
	visit[0][0] = 0;
	
	while (!q.empty())
	{
		int X = q.front().x;
		int Y = q.front().y;
		int cnt = q.front().cnt;
		q.pop();

		if (X == N - 1 && Y == N - 1)
			continue;

		for (int i = 0; i < 4; i++)
		{
			int nx = X + dx[i];
			int ny = Y + dy[i];
			int ncnt = cnt;

			if (nx > -1 && nx < N && ny > -1 && ny < N)
			{
				if (visit[ny][nx] == -1)
				{
					if (Array[ny][nx] == 0) ncnt++;
					visit[ny][nx] = ncnt;
					q.push({ nx, ny, ncnt });
				}
				else
				{
					if (Array[ny][nx] == 0) ncnt++;

					if (ncnt < visit[ny][nx])
					{
						visit[ny][nx] = ncnt;
						q.push({ nx, ny, ncnt });
					}
				}
			}
		}
	}
}

void solve()
{
	memset(visit, -1, sizeof(visit));
	BFS();
	cout << visit[N - 1][N - 1];
}

int main()
{
	input();
	solve();
	return 0;
}
