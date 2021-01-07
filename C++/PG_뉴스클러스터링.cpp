#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define endl "\n";

// 1개의 태케에서 시간초과 걸림

struct Mystring
{
	char c1;
	char c2;
};

vector<Mystring> S1, S2;
vector<Mystring> AinB, AoutB;

void input(string str1, string str2)
{
	for (int i = 0; i < str1.size() - 1; i++)
	{
		if ((str1[i] >= 'a' && str1[i] <= 'z') || (str1[i] >= 'A' && str1[i] <= 'Z'))
			if ((str1[i + 1] >= 'a' && str1[i + 1] <= 'z') || (str1[i + 1] >= 'A' && str1[i + 1] <= 'Z'))
			{
				char c1, c2;
				
				if (str1[i] >= 'A' && str1[i] <= 'Z') c1 = str1[i] + 32;
				else c1 = str1[i];

				if (str1[i + 1] >= 'A' && str1[i + 1] <= 'Z') c2 = str1[i + 1] + 32;
				else c2 = str1[i + 1];

				S1.push_back({ c1, c2 });
			}
	}

	for (int i = 0; i < str2.size() - 1; i++)
	{
		if ((str2[i] >= 'a' && str2[i] <= 'z') || (str2[i] >= 'A' && str2[i] <= 'Z'))
			if ((str2[i + 1] >= 'a' && str2[i + 1] <= 'z') || (str2[i + 1] >= 'A' && str2[i + 1] <= 'Z'))
			{
				char c1, c2;

				if (str2[i] >= 'A' && str2[i] <= 'Z') c1 = str2[i] + 32;
				else c1 = str2[i];

				if (str2[i + 1] >= 'A' && str2[i + 1] <= 'Z') c2 = str2[i + 1] + 32;
				else c2 = str2[i + 1];

				S2.push_back({ c1, c2 });
			}

	}
}

void check_in()
{
	int cnt = 0;
	for (int i = 0; i < S1.size(); i++)
	{
		for (int j = 0; j < S2.size(); j++)
		{
			if (S1[i].c1 == S2[j].c1 && S1[i].c2 == S2[j].c2)
			{
				if (AinB.size() == 0) AinB.push_back({ S1[i].c1, S1[i].c2 });
				else
				{
					int flag = 0;
					for (int k = 0; k < AinB.size(); k++)
					{
						if (AinB[k].c1 == S1[i].c1 && AinB[k].c2 == S1[i].c2)
						{
							flag = 1;
							break;
						}
					}

					if(flag == 0) AinB.push_back({ S1[i].c1, S1[i].c2 });
				}
			}
		}
	}
}

void check_out()
{
	for (int i = 0; i < S1.size(); i++)
		AoutB.push_back({ S1[i].c1, S1[i].c2 });

	//중복된거 미리 체크
	if (AoutB.size() > 0)
	{
		for (int i = 0; i < AoutB.size() - 1; i++)
		{	for (int j = i + 1; j < AoutB.size(); j++)
			if (AoutB[i].c1 == AoutB[j].c1 && AoutB[i].c2 == AoutB[j].c2)
			{
				AoutB.erase(AoutB.begin() + j);
				j--;
			}
		}
	}

	for (int i = 0; i < S2.size(); i++)
	{
		char c1 = S2[i].c1;
		char c2 = S2[i].c2;

		int flag = 0;

		for (int j = 0; j < AoutB.size(); j++)
		{
			if (c1 == AoutB[j].c1 && c2 == AoutB[j].c2)
			{
				flag = 1;
				break;
			}
		}

		if (flag == 0) AoutB.push_back({ c1, c2 });
	}

}

int cnt_inner()
{
	int cnt = 0;
	
	for (int i = 0; i < AinB.size(); i++)
	{
		char c1 = AinB[i].c1;
		char c2 = AinB[i].c2;

		int cnt1 = 0, cnt2 = 0;

		for (int j = 0; j < S1.size(); j++)
			if (S1[j].c1 == c1 && S1[j].c2 == c2) cnt1++;

		for (int j = 0; j < S2.size(); j++)
			if (S2[j].c1 == c1 && S2[j].c2 == c2) cnt2++;

		if (cnt1 == 0) cnt += cnt2;
		else if (cnt2 == 0) cnt += cnt1;
		else cnt += min(cnt1, cnt2);
	}

	return cnt;
}

int cnt_outter()
{
	int cnt = 0;

	for (int i = 0; i < AoutB.size(); i++)
	{
		char c1 = AoutB[i].c1;
		char c2 = AoutB[i].c2;

		int cnt1 = 0, cnt2 = 0;

		for (int j = 0; j < S1.size(); j++)
			if (S1[j].c1 == c1 && S1[j].c2 == c2) cnt1++;

		for (int j = 0; j < S2.size(); j++)
			if (S2[j].c1 == c1 && S2[j].c2 == c2) cnt2++;

		cnt += max(cnt1, cnt2);
	}

	return cnt;
}

int solution(string str1, string str2) {
	int answer = 0;
	S1.clear();
	S2.clear();
	AinB.clear();
	AoutB.clear();

	input(str1, str2);

	if (S1.size() == 0 && S2.size() == 0) return 65536;

	double inner, outter;

	check_in();
	check_out();

	if (AinB.size() == 0) return 0;
	if (AoutB.size() == 0) return 65536;

	inner = cnt_inner();
	outter = cnt_outter();

	if (inner == outter) answer = 65536;
	else
	{
		double d = inner / outter;

		answer = d * 65536;
	}

	return answer;
}
