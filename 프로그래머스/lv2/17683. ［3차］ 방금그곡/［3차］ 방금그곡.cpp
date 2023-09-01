#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

struct info{
    string name;
    int t, idx;
};

vector<string> split(string input, char delimeter){
    vector<string>result;
    stringstream s(input);
    string ss;
    
    while(getline(s, ss, delimeter)) result.push_back(ss);
    return result;
}

int time_cal(int a1, int a2, int b1, int b2){
    int time = 0;
    
    if(b2 < a2){
        time = b2+60-a2;
        b1--;
    }else time = b2-a2;
    
    time += (b1 - a1) * 60;
    return time;
}

bool cmp(info a, info b){
    if(a.t == b.t) return a.idx < b.idx;
    return a.t > b.t;
}

string code_to_num(string s){
    string res;
    for(int i=s.length()-1 ;i>=0;i--){
        if(s[i] == '#'){
            if(s[i-1] == 'C') res += 'a';
            else if(s[i-1] == 'D') res += 'b';
            else if(s[i-1] == 'F') res += 'c';
            else if(s[i-1] == 'G') res += 'd';
            else if(s[i-1] == 'A') res += 'e';
            i--;
            continue;
        }
        
        if(s[i] == 'C') res += 'f';
        else if(s[i] == 'D')res += 'g';
        else if(s[i] == 'E')res += 'h';
        else if(s[i] == 'F')res += 'i';
        else if(s[i] == 'G')res += 'j';
        else if(s[i] == 'A')res += 'k';
        else if(s[i] == 'B')res += 'l';
    }
    reverse(res.begin(), res.end());
    return res;
}


string solution(string m, vector<string> musicinfos) {
    vector<info>A;
    
    for(int i=0; i< musicinfos.size();i++){
        vector<string>B = split(musicinfos[i], ',');
        
        //시간 계산
        int a1 = stoi(B[0].substr(0,2));
        int a2 = stoi(B[0].substr(3,2));
        int b1 = stoi(B[1].substr(0,2));
        int b2 = stoi(B[1].substr(3,2));
        int time = time_cal(a1, a2, b1, b2);
        //int music_time = B[3].length();
        
        //#고려해서 시간 계산 진행
        string m_sheet = code_to_num(m);
        string u_sheet = code_to_num(B[3]);
        int music_time = u_sheet.length();
        
        //음악 재생 string
        string sen;
        int temp = time / music_time;
        while(temp != 0){
            sen += u_sheet;
            temp--;
        }
        temp = time % music_time;
        int idx=0;
        for(int j=0;j<u_sheet.length();j++){
            sen += u_sheet[j];     
            idx++;
            
            if(idx == temp) break;
        }
        
        //sen += B[3].substr(0, time % music_time);
        if(sen.length() < m_sheet.length()) continue;
        
        //m이 해당 string에 존재하는 지
        if(sen.find(m_sheet) == std::string::npos) continue;
        A.push_back({B[2], time, i});
    }
    
    if(A.size() == 0) return "(None)";
    sort(A.begin(), A.end(), cmp);
    string answer = A[0].name;
    return answer;
}