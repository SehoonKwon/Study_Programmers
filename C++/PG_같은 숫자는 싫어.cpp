#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    int pre = -1;
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] != pre)
        {
            pre = arr[i];
            answer.push_back(pre);
        }
    }

    return answer;
}
