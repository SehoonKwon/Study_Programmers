#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int N;
int Array[16][16], Array2[16][16], check[16];
char ANS[16][16];

void D2B(int x)
{
	for (int i = N - 1; i > -1; i--)
	{
		if ((x % 2) == 1) check[i] = 1;
		else check[i] = 0;
		x /= 2;
	}
}

void solve(vector<string> &v)
{
	memset(ANS, 0, sizeof(ANS));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
        {
            if (Array[i][j] == 1 || Array2[i][j] == 1) ANS[i][j] = '#';
            else ANS[i][j] = ' ';         
        }
        
        v.push_back(ANS[i]);
	}
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    N = n;
    
    for(int i=0; i<n; i++)
    {
        int x = arr1[i];
        D2B(x);
        for(int j=0; j<n; j++)
            Array[i][j] = check[j];
    }
    
    
    for(int i=0; i<n; i++)
    {
        int x = arr2[i];
        D2B(x);
        for(int j=0; j<n; j++)
            Array2[i][j] = check[j];
    }
    
    solve(answer);
    
    return answer;
}
