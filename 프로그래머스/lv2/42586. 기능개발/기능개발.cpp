#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> s;
    
    for(int i=0;i<speeds.size();i++){
        int day = 0;
        day = (100-progresses[i]) / speeds[i];
        if((100-progresses[i]) % speeds[i] != 0) day++;
        
        s.push(day);
    }
    
    int temp = s.front(), cnt = 0;
    while(!s.empty()){
        int v = s.front();
        s.pop();
        
        if(temp >= v)cnt++;
        else{
            answer.push_back(cnt);
            temp = v;
            cnt = 1;
        }
    }
    if(cnt>0) answer.push_back(cnt);
    
    
    return answer;
}