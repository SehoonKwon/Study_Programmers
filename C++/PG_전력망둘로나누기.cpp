#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

//100개 밖에 안되니까 wire 하나씩 끊고 탐색돌려서 최소차이 구하기
int visit[101];
int MIN = (int)1e9;
int cnt[2];
int Array[101][101];
int N;

void DFS(int idx, int c)
{
    if (visit[idx] == true) return;
    visit[idx] = true;
    cnt[c]++;

    for (int i = 1; i < N + 1; i++)
        if (Array[idx][i] == 1 && visit[i] == false)
            DFS(i, c);
}

int solution(int n, vector<vector<int>> wires) {
    int answer = (int)1e9;
    N = n;

    for (int i = 0; i < wires.size(); i++)
    {
        int x = wires[i][0];
        int y = wires[i][1];

        Array[x][y] = Array[y][x] = 1;
    }

    for (int i = 0; i < wires.size(); i++)
    {
        int x = wires[i][0];
        int y = wires[i][1];
        memset(cnt, 0, sizeof(cnt));
        memset(visit, 0, sizeof(visit));

        Array[x][y] = Array[y][x] = 0;


        //탐색
        int c = 0;
        for (int j = 1; j < n + 1; j++)
        {
            if (c == 2) break;
            if (visit[j] == false)
            {
                DFS(j, c);
                c++;
            }
        }

        if (cnt[0] + cnt[1] == n)
            answer = min(answer, abs(cnt[0] - cnt[1]));

        //백업
        Array[x][y] = Array[y][x] = 1;
    }

    return answer;
}
