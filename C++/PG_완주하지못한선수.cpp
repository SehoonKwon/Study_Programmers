#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> mymap;
    for(int i=0; i<participant.size(); i++)
        mymap[participant[i]]++;
    
    for(int i=0; i<completion.size(); i++)
        mymap[completion[i]]--;
    
    for(int i=0; i<participant.size(); i++)
        if(mymap[participant[i]] > 0)
            answer = participant[i];
    
    return answer;
}
