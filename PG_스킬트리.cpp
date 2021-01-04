#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

int org[27], chk[27];

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for(int i=0; i<skill.size(); i++)
        org[skill[i]-'A']++;
    
    int cnt = 0;
    int s_idx = 0;
    for(int i=0; i<skill_trees.size(); i++)
    {
        s_idx = 0;
        int flag = 0;
        memcpy(chk, org, sizeof(org));
        for(int j=0; j<skill_trees[i].size(); j++)
        {
            char X = skill_trees[i][j];
            if(chk[X-'A'] > 0)
            {
                if(X == skill[s_idx])
                {
                    chk[X-'A']--;
                    s_idx++;
                }
                else
                {   
                    flag = 1;
                    break;
                }
            }
        }
        if(!flag) cnt++;
    }
    
    return cnt;
}
