#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int GCD(int a, int b)
{
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}

	return a;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		vector<int> v(N);
		for (int i = 0; i < N; i++)
			cin >> v[i];

		ll sum = 0;
		for (int i = 0; i < N - 1; i++)
			for (int j = i + 1; j < N; j++)
				sum += GCD(v[i], v[j]);

		cout << sum << "\n";
	}
	return 0;
}
