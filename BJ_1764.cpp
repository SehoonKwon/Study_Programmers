#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	map<string, int> map;

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		map[s] = 1;
	}

	vector<string> v;
	for (int i = 0; i < M; i++)
	{
		string s;
		cin >> s;
		int a = map.size();
		map[s] = 1;
		int b = map.size();

		if (a == b)
			v.push_back(s);
	}

	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";

	return 0;
}
