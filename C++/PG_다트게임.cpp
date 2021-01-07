#include <string>
#include <iostream>
#include <cmath>

using namespace std;

int Array[30];
string s;

int solve(string s)
{
	int cnt = 0;
	int flag1 = 0, flag2 = 0;

	int x = 0, p = 0;

	for (int i = 0; i < s.size();)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			if (s[i] == '1' && s[i + 1] == '0')
			{
				x = 10;
				i++;
			}

			else
				x = s[i] - 48;

			flag1 = 1;
		}

		else
		{
			if (s[i] == 'S') p = 1;
			else if (s[i] == 'D') p = 2;
			else if (s[i] == 'T') p = 3;

			flag2 = 1;
		}

		i++;

		if (flag1 == 1 && flag2 == 1)
		{
			Array[cnt] = pow(x, p);
			cnt++;
			flag1 = 0;
			flag2 = 0;
		}

		if (s[i] == '*')
		{
			if (cnt == 1)
				Array[0] *= 2;

			else
			{
				Array[cnt - 2] *= 2;
				Array[cnt - 1] *= 2;
			}

			i++;
		}

		else if(s[i] == '#')
		{
			Array[cnt - 1] *= -1;
			i++;
		}

	}

	int ans = 0;
	for (int i = 0; i < 3; i++)
		ans += Array[i];
    return ans;
}
