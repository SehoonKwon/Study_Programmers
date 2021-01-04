#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int N = citations.size();
    sort(citations.begin(), citations.end());
    
    int MAX = 0;
    for(int i=0; i<=N; i++)
    {
        int ucnt=0, dcnt=0;
        for(int j=0; j<N; j++)
        {
            if(citations[j] <= i) dcnt++;
            if(citations[j] >= i) ucnt++;
        }
        
        if(ucnt >= i && dcnt <= i)
            MAX = max(MAX, i);
    }
    
    return MAX;
}
