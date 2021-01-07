#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

string d2t(int n)
{
    stack<int> stk;
    while(1)
    {   
        if(n < 3)
        {
            stk.push(n);
            break;
        }
        int r = n%3;
        stk.push(r);
        n /= 3;
    }
    
    string s = "";
    while(!stk.empty())
    {
        char c = stk.top()+'0';
        stk.pop();
        s += c;
    }
    reverse(s.begin(), s.end());
    return s;
}

int t2d(string s)
{
    int res = 0;
    reverse(s.begin(), s.end());
    for(int i=0; i<s.size(); i++)
        res += ((s[i]-'0') * pow(3, i));
    return res;
}

int solution(int n) 
{
    int answer = 0;
    string s = d2t(n);
    answer = t2d(s);
    return answer;
}
