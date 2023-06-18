#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;
map<string, string> m;

vector<string> split(string input, char delimiter){
    vector<string> result;
    stringstream ss(input); 
    string sen;
    
    while(getline(ss, sen, delimiter)) result.push_back(sen);
    return result;
}

typedef pair<string, bool> EL;
vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<EL> line;
    
    for(int t=0;t<record.size();t++){
        vector<string> info = split(record[t],' ');
        
        if(info[0][0] =='E'){//들어온것
            m[info[1]] = info[2];
            line.push_back({info[1],true});
        }
        else if(info[0][0] =='L'){//나간것
            line.push_back({info[1],false});
        }
        else if(info[0][0] =='C'){//바꾼것
            m[info[1]] = info[2];
        }
    }
    
    for(int i=0;i<line.size();i++){
        string id = line[i].first;
        if(line[i].second)answer.push_back(m[id]+"님이 들어왔습니다.");
        else answer.push_back(m[id]+"님이 나갔습니다.");
    }
    
    return answer;
}