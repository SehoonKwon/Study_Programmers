#include <vector>
#include <cstring>
using namespace std;

long long int sp_cnt, MAX, cnt;
int visit[101][101];
int Array[101][101];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int N, M;

void DFS(int x, int y)
{
    if(visit[y][x] == true) return;
    visit[y][x] = true;
    cnt++;
    if(MAX < cnt) MAX = cnt;
   
    for(int i=0; i<4; i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        
        if(nx > -1 && nx < N && ny > -1 && ny < M)
            if(visit[ny][nx] == false && Array[ny][nx] == Array[y][x])
                DFS(nx, ny);
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer;
    N = n;
    M = m;
    sp_cnt = 0, MAX = 0;
    memset(Array,0,sizeof(Array));
    memset(visit,0,sizeof(visit));
    
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
            Array[i][j] = picture[i][j];
    }
    
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(Array[i][j] != 0 && visit[i][j] == false)
            {
                sp_cnt++;
                cnt = 0;
                DFS(j, i);
            }
        }
    }
    answer.push_back(sp_cnt);
    answer.push_back(MAX);
    return answer;
}
