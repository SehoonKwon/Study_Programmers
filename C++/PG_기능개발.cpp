#include <string>
#include <vector>
#include <queue>
using namespace std;

int Array[101];

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    for(int day=1; day<101; day++)
    {
        for(int i=0; i<speeds.size(); i++)
        {
            if(progresses[i] >= 100) continue;
            
            progresses[i] += speeds[i];
            if(progresses[i] >= 100) Array[i] = day;
        }
    }
    
    queue<int> q;
    for(int i=0; i<speeds.size(); i++)
        q.push(Array[i]);
    
    while(!q.empty())
    {
        int D = q.front();
        int cnt = 0;
        while(!q.empty())
        {
            int X = q.front();
            if(X > D) break;
            cnt++;
            q.pop();
        }
        answer.push_back(cnt);
    }
    
    return answer;
}
