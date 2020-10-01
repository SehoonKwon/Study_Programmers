#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int N;
vector<int> v;

int main()
{
	cin >> N;

	if (N == 1)
	{
		cout << 0;
		return 0;
	}

	int DS;
	cin >> DS;
	for (int i = 0; i < N - 1; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	int ans = 0;
	for (int i = 0; i < 1001; i++)
	{
		sort(v.begin(), v.end(), greater<int>());
		if (DS > v[0]) break;
		else
		{
			DS++;
			ans++;
			v[0]--;
		}
	}

	cout << ans;

	return 0;
}
