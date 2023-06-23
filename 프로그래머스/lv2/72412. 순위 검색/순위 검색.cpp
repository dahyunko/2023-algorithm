#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

vector<string> split(string input, char delimeter){
    vector<string> result;
    stringstream s(input);
    string sen;
    
    while(getline(s,sen,delimeter)) result.push_back(sen);
    return result;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    //동점자 있을 수도 있음-> vector<int> 사용
    map<string, vector<int>> m;
    
    for(int t=0;t<info.size();t++){
        vector<string>str = split(info[t], ' ');
        m[str[0]+ str[1]+ str[2]+str[3]].push_back(stoi(str[4]));
        m[str[0]+ str[1]+ str[2]+"-"].push_back(stoi(str[4]));
        m[str[0]+ str[1]+ "-"+str[3]].push_back(stoi(str[4]));
        m[str[0]+ "-"+ str[2]+str[3]].push_back(stoi(str[4]));
        m["-" + str[1]+ str[2]+str[3]].push_back(stoi(str[4]));
        m[str[0]+ str[1]+ "--"].push_back(stoi(str[4]));
        m[str[0]+ "-"+ str[2]+"-"].push_back(stoi(str[4]));
        m["-"+ str[1]+ str[2]+"-"].push_back(stoi(str[4]));
        m[str[0]+ "-"+ "-"+str[3]].push_back(stoi(str[4]));
        m["-"+ str[1]+ "-"+str[3]].push_back(stoi(str[4]));
        m["--"+ str[2]+str[3]].push_back(stoi(str[4]));
        m[str[0]+ "-"+ "--"].push_back(stoi(str[4]));
        m["-"+ str[1]+ "--"].push_back(stoi(str[4]));
        m["--"+ str[2]+"-"].push_back(stoi(str[4]));
        m["---"+str[3]].push_back(stoi(str[4]));
        m["----"].push_back(stoi(str[4]));
    }
    
    for(auto it = m.begin();it != m.end();it++){
        sort(it->second.begin(), it->second.end());
        //for(int i=0;i<it->second.size();i++) cout<< it->second[i]<<' ';
        //cout<< it->first<<'\n';
    } 

    //query 진행
    
    for(int t=0;t<query.size();t++){
        vector<string>str = split(query[t],' ');
        int c = 0, score;
        string sen;
        for(int i=0;i<str.size();i++){
            if(str[i] == "and") continue;
            if(c == 4) score = stoi(str[i]); 
            else sen += str[i];
            c++;
        }
        //cout<< sen;
        
        auto it = lower_bound(m[sen].begin(), m[sen].end(), score);
        
        int n = m[sen].size()-(it-m[sen].begin());
        answer.push_back(n);
    }
    
    return answer;
}