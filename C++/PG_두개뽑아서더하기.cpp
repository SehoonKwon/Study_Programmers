#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int Array[10001];

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    int len = numbers.size();
    for(int i=0; i<len; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            int sum = numbers[i]+numbers[j];
            if(Array[sum] == 0)
            {
                Array[sum]++;
                answer.push_back(sum);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}
