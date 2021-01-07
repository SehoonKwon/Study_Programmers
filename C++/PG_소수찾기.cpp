#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int visit[8];
vector<char> v;
vector<char> dv;
map<int, int> mymap;
int sosu;

void DFS(int idx)
{
    if(idx > v.size()) return;
    
    string res = "";
    if(dv.size() > 0)
    {
        for(int i=0; i<dv.size(); i++)
            res += dv[i];
        
        int X = stoi(res);
        if(X >= 2)
        {
            if(mymap[X] == 0)
            {
                mymap[X]++;
                cout<<X<<endl;
                int flag = 0;
                for(int j=2; j<X; j++)
                {
                    if(X%j == 0)
                    {
                        flag = 1;
                        break;
                    }
                }
                if(!flag) sosu++;
            }
        }
    }
    
    for(int i=0; i<v.size(); i++)
    {
        if(visit[i] == true) continue;
        visit[i] = true;
        dv.push_back(v[i]);
        DFS(idx+1);
        dv.pop_back();
        visit[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;
    for(int i = 0; i<numbers.size(); i++)
        v.push_back(numbers[i]);
    
    DFS(0);
    
    return sosu;
}
