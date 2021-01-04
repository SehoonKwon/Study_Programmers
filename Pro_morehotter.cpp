#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <iostream>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    for(int i=0; i<scoville.size(); i++)
        pq.push(scoville[i]);
    
    while(!pq.empty())
    {
        int x = pq.top();
        if(x >= K) return answer;
        pq.pop();
        if(pq.empty()) return -1;
        int y = pq.top();
        pq.pop();
        answer++;
        
        int nx = x + y*2;
        pq.push(nx);
    }
    
    return answer;
}
