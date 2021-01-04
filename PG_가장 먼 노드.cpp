#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

int N;
int visit[20001];
vector<int> v[20001];
vector<int> av;

struct point
{
    int node;
    int step;
};

void BFS()
{
    queue<point> q;
    q.push({1, 0});
    visit[1] = true;
    
    while(!q.empty())
    {
        int x = q.front().node;
        int step = q.front().step;
        q.pop();
        
        for(int i=0; i<v[x].size(); i++)
        {
            int nx = v[x][i];
            if(visit[nx] == false)
            {   
                av.push_back(step+1);
                visit[nx] = true;
                q.push ({nx, step+1});
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    N = n;
    
    for(int i=0; i < edge.size(); i++)
    {
        int a, b;
        a = edge[i][0];
        b = edge[i][1];
        
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    BFS();
    
    sort(av.begin(), av.end(), greater<int>());
    
    int cnt = 0;
    int MAX = av[0];
    for(int i=0; i<av.size(); i++)
    {
        if(av[i] < MAX)
            break;
        else
            cnt++;
    }
    
    return cnt;
}
