#include <string>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

#define endl "\n"

int M, N;
char Array[31][31];
int dx[] = { 0, 1, 1 };
int dy[] = { 1, 0, 1 };
int pang_cnt = 0;

struct point
{
	int x;
	int y;
};

vector<point> v, v2; //v1은 사라질 곳 시작점의 좌표, v2는 사라진 공간의 좌표

int isPang(int x, int y, char C)
{
	int cnt = 0;
	for (int i = 0; i < 3; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx > N || ny < 0 || ny > M) return false;

		if (Array[ny][nx] == C) cnt++;
	}

	if (cnt == 3) return true;
	else return false;
}

void Check()
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Array[i][j] == 'x') continue;

			int p = isPang(j, i, Array[i][j]);
			if (p == 1) v.push_back({ j, i });
		}
	}
}

void Pang()
{
	for (int i = 0; i < v.size(); i++)
	{
		int x = v[i].x;
		int y = v[i].y;

		Array[y][x] = 'x';
		v2.push_back({ x, y });

		for (int j = 0; j < 3; j++)
		{
			int nx = x + dx[j];
			int ny = y + dy[j];

			Array[ny][nx] = 'x';
			v2.push_back({ nx, ny });
		}
	}

	v.clear();
}

void renew()
{
	for (int i = M-1; i > -1; i--)
	{
		for (int j = 0; j < N; j++)
		{
			if (Array[i][j] == 'x')
			{
				for (int k = i - 1; k > -1; k--)
				{
					if (Array[k][j] != 'x')
					{
						Array[i][j] = Array[k][j];
						Array[k][j] = 'x';
						break;
					}
				}
			}
		}
	}
}

int solution(int m, int n, vector<string> board) {
	int answer = 0;

	M = m;
	N = n;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			Array[i][j] = board[i][j];
	}

	//한 셀을 기준으로 오른쪽,아래쪽, 대각아래 검사해서 삭제 시작점 좌표 벡터에 넣기 -> 다 넣으면 벡터돌면서 제거 범위제거 -> 배열 내리기
	while (1)
	{
		Check();
		if (v.size() == 0) break;
		else
		{
			Pang();
			renew();
		}
	}

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			if (Array[i][j] == 'x') answer++;

	return answer;
}
