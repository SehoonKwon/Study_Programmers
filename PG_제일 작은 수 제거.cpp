#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    if(arr.size() == 1)
    {
        answer.push_back(-1);
        return answer;
    }
    
    int MIN = (int)1e9, idx = -1;
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i]<MIN)
        {
            MIN = arr[i];
            idx = i;
        }
    }
    
    arr.erase(arr.begin() + idx);
    
    return arr;
}
