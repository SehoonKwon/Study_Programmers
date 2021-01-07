#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(const string& u, const string& v)
{
   return u+v > v+u;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> ans;
    
    for(int i=0; i<numbers.size(); i++)
        ans.push_back(to_string(numbers[i]));
    
    sort(ans.begin(), ans.end(), cmp);
    if(ans.at(0) == "0")    return "0";
    
    for(int i=0; i < ans.size(); i++)
        answer += ans[i];
    
    return answer;
}
