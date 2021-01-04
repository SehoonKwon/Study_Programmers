#include <string>
#include <vector>

using namespace std;

int DP[100001];

int solution(int n) {
    int answer = 0;
    DP[0] = 0;
    DP[1] = 1;
    
    for(int i=2; i<=n; i++)
    {
        DP[i] = DP[i-1] + DP[i-2];
        DP[i] = DP[i]%1234567;
    }
    return DP[n]%1234567;
}
