#include <iostream>
#include <queue>
#include <string>
using namespace std;

int N;
int Non_prime[1003002]; // 1003001 이 백만 이후 가장 빠른 팰린드롬 소수(정답을 구한 뒤에 속도를 위해서 배열을 줄여준거. 처음엔 2백만잡고했음)

void eratos()
{
	for (int i = 2; i <= 1003001; i++)
	{
		for (int j = 2; j*i <= 1003001; j++)
			Non_prime[j*i] = 1;
	}
}

int is_pal(int X)
{
	int temp = X;
	queue<int> q;
	while (X > 0)
	{
		int r = X % 10;
		q.push(r);
		X /= 10;
	}

	string s = "";
	while (!q.empty())
	{
		s += (q.front() + '0');
		q.pop();
	}

	int nX = stoi(s);
	if (temp == nX) return 1;
	else return 0;
}

int main()
{
	cin >> N;
	eratos();
	Non_prime[1] = 1;
	for (int i = N; i <= 1003001; i++)
	{
		if (Non_prime[i] == false)
		{
			if (is_pal(i))
			{
				cout << i;
				return 0;
			}
		}
	}
	return 0;
}
