#include <string>
#include <vector>

using namespace std;

char Array[] = { 'A','E' ,'I', 'O','U' };
int answer;
int ans_len, flag;
string target;

void DFS(vector<char> tv)
{
    if (tv.size() == ans_len)
    {
        int isEq = 1;
        for (int i = 0; i < ans_len; i++)
        {
            if (tv[i] != target[i])
            {
                isEq = 0;
                break;
            }
        }

        if (isEq) flag = 1;
    }
    
    if (flag) return;
    if (tv.size() == 5) return;

	for (int i = 0; i < 5; i++)
	{
		answer++;
		tv.push_back(Array[i]);
		DFS(tv);
		if (flag) return;
		tv.pop_back();
	}
 
}


int solution(string word) {

    vector<char> v;
    target = word;
    ans_len = word.size();
    DFS(v);
    return answer;
}
