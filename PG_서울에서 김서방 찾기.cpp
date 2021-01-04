#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string calcul(int n)
{
    string s;
    while(n > 0)
    {
        int r = n%10;
        s += (r+'0');
        n /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    int idx;
    for(; idx<seoul.size(); idx++)
        if(seoul[idx] == "Kim") break;
    
    if(idx < 10) answer += (idx+'0');
    else 
    {
        string a = calcul(idx);
        answer += a;
    }
    answer += "에 있다";
    return answer;
}
