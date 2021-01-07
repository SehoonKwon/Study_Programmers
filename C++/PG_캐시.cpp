#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

#define endl "\n"

// 60점..

int N;
string City[100000];
int City_cnt = 0;

vector<string> Cache;

int isCache(string s)
{
	int flag = 0;
	int idx = 0;
	if (Cache.size() != 0)
	{
		for (int i = 0; i < Cache.size(); i++)
			if (Cache[i] == s)
			{
				Cache.erase(Cache.begin() + i);
				Cache.push_back(s);
				return true;
			}
	}

	return false;
}

void renew_cache(string s)
{
	if (Cache.size() == N)
	{
		for (int i = 0; i < Cache.size() - 1; i++)
			Cache[i] = Cache[i + 1];
		Cache[Cache.size() - 1] = s;
	}

	else Cache.push_back(s);
}

int solve(vector<string> City)
{
	if (N == 0) return 5 * City.size();

	int ans = 0;

	for (int i = 0; i < City.size(); i++)
	{
		int c = isCache(City[i]);
		if (c == 1) ans++;
		else
		{
			renew_cache(City[i]);
			ans += 5;
		}
	}

	return ans;
}

int solution(int cacheSize, vector<string> cities) {

	N = cacheSize;

	vector<string> City;

	for (int i = 0; i < cities.size(); i++)
	{
		string s = cities[i];

		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] >= 'A' && s[j] <= 'Z') s[j] = s[j] + 32;
		}

		City.push_back(s);
	}

	int answer = solve(City);
	return answer;
}
