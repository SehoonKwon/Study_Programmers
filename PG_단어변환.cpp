#include <string>
#include <vector>
#include <iostream>
using namespace std;

int N;
int visit[51];
string t;
vector<string> w;
int MIN = 987654321;

int check(string a, string b)
{
    int cnt=0;
    for(int i=0; i<a.size(); i++)
        if(a[i] != b[i]) cnt++;
    
    return cnt;
}

void DFS(string s, int idx, int cnt)
{
    cout<<s<<" "<<cnt<<"\n";
    if(s == t)
    {
        if(cnt < MIN) MIN = cnt;
        return;
    }
    
    for(int i=0; i<N; i++)
    {
        if(visit[i] == true) continue;
        int c = check(s, w[i]);
        if(c == 1)
        {
            visit[i] = true;
            DFS(w[i], i, cnt+1);
            visit[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    N = words.size();
    w = words;
    t = target;
    
    int flag=0;
    for(int i=0; i<N; i++)
        if(target == words[i]) flag=1;
    
    if(!flag) return 0;
    
    DFS(begin, 0, 0);
    
    return MIN;
}
