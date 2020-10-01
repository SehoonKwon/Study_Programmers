#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int a,b,c;
int visit[201][201][201];

vector<int> v;

struct point
{
	int A;
	int B;
	int C;
};

void solve()
{
	queue<point> q;
	q.push({ 0, 0, c });
	visit[0][0][c] = true;

	while (!q.empty())
	{
		int A = q.front().A;
		int B = q.front().B;
		int C = q.front().C;
		q.pop();

		if(A == 0)
			v.push_back(C);

		int na = 0, nb = 0, nc = 0;

		//A->B
		nb = A + B;
		if (nb > b)
		{
			na = nb - b;
			nb -= na;
			if (visit[na][nb][C] == false)
			{
				visit[na][nb][C] = true;
				q.push({ na, nb, C });
			}
		}
		else
		{
			if (visit[0][nb][C] == false)
			{
				visit[0][nb][C] = true;
				q.push({ 0, nb, C });
			}
		}

		//A->C
		nc = A + C;
		if (nc > c)
		{
			na = nc - c;
			nc -= na;
			if (visit[na][B][nc] == false)
			{
				visit[na][B][nc] = true;
				q.push({ na, B, nc });
			}
		}
		else
		{
			if (visit[0][B][nc] == false)
			{
				visit[0][B][nc] = true;
				q.push({ 0, B, nc });
			}
		}

		//B->A
		na = A + B;
		if (na > a)
		{
			nb = na - a;
			na -= nb;
			if (visit[na][nb][C] == false)
			{
				visit[na][nb][C] = true;
				q.push({ na, nb, C });
			}
		}
		else
		{
			if (visit[na][0][C] == false)
			{
				visit[na][0][C] = true;
				q.push({ na, 0, C });
			}
		}

		//B->C
		nc = B + C;
		if (nc > c)
		{
			nb = nc - c;
			nc -= nb;
			if (visit[A][nb][nc] == false)
			{
				visit[A][nb][nc] = true;
				q.push({ A, nb, nc });
			}
		}
		else
		{
			if (visit[A][0][nc] == false)
			{
				visit[A][0][nc] = true;
				q.push({ A, 0, nc });
			}
		}

		//C->A
		na = A + C;
		if (na > a)
		{
			nc = na - a;
			na -= nc;
			if (visit[na][B][nc] == false)
			{
				visit[na][B][nc] = true;
				q.push({ na, B, nc });
			}
		}
		else
		{
			if (visit[na][B][0] == false)
			{
				visit[na][B][0] = true;
				q.push({ na, B, 0 });
			}
		}

		//C->B
		nb = B + C;
		if (nb > b)
		{
			nc = nb - b;
			nb -= nc;
			if (visit[A][nb][nc] == false)
			{
				visit[A][nb][nc] = true;
				q.push({ A, nb, nc });
			}
		}
		else
		{
			if (visit[A][nb][0] == false)
			{
				visit[A][nb][0] = true;
				q.push({ A, nb, 0 });
			}
		}
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
}

int main()
{
	cin >> a >> b >> c;
	solve();
	return 0;
}
