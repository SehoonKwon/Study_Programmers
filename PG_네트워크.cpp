#include <string>
#include <vector>

using namespace std;

vector<vector<int>> v;
int N;
int visit[201];
int ans;

void DFS(int x)
{
    if(visit[x] == true) return;
    visit[x] = true;
    
    for(int i=0; i<N; i++)
    {
        
        if(v[x][i] == true && visit[i] == false)
            DFS(i);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    N = n;
    v = computers;
    
    for(int i=0; i<n; i++)
    {
        if(visit[i] == false)
        {
            ans++;
            DFS(i);
        }
    }
    return ans;
}
