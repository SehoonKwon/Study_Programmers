#include <iostream>
#include <vector>
using namespace std;

int N, M, V;
int Array[200001];

void input()
{
	cin >> N >> M >> V;
	for (int i = 0; i < N; i++)
		cin >> Array[i];
}

void solve()
{
	for (int i = 0; i < M; i++)
	{
		int X;
		cin >> X;

		if (X < N)
		{
			cout << Array[X] << "\n";
			continue;
		}

		//민달팽이
		if (V == N)
			cout << Array[N - 1] << "\n";
		else
		{
			int MOD = N - V + 1;
			X -= (V-1);
			int r = X % MOD;
			cout << Array[(V-1) + r] << "\n";
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
