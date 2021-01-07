#include <string>
#include <vector>
#include <iostream>
#include <functional>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> v;
    while(n > 0)
    {
        int r = n%10;
        v.push_back(r);
        n/=10;
    }
    
    sort(v.begin(), v.end(), greater<int>());
    
    int idx = 0;
    for(int i=v.size()-1; i>=0; i--)
    {
        answer += (v[i] * pow(10, idx));
        idx++;
    }
    return answer;
}
