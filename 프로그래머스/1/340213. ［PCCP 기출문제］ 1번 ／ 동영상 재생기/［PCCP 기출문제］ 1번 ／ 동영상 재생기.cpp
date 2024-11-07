#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";

    int videoM = stoi(video_len.substr(0, 2));
    int videoS =stoi(video_len.substr(3, 2));
    int pM = stoi(pos.substr(0, 2));
    int pS = stoi(pos.substr(3, 2));
    int sM = stoi(op_start.substr(0, 2));
    int sS = stoi(op_start.substr(3, 2));
    int eM = stoi(op_end.substr(0, 2));
    int eS = stoi(op_end.substr(3, 2));
    
    for(int i=0;i<commands.size() ;i++){
        if(((pM == sM && pS >= sS) || (pM > sM)) && ((pM == eM && pS <= eS)||(pM < eM))){
            pM = eM;
            pS = eS;
        }
        
        if(commands[i] == "next"){ // 10초 앞으로
            pS += 10;
            if(pS >= 60){
                pM++;
                pS -= 60;
            }
        }
        else { // 10초 뒤로
            pS -= 10;
            if(pS < 0){
                pM--;
                pS += 60;
            }
        }
        
        if(((pM == sM && pS >= sS) || (pM > sM)) && ((pM == eM && pS <= eS)||(pM < eM))){
            pM = eM;
            pS = eS;
        }
        if((pM > videoM)||(pM == videoM && pS > videoS)){ 
            pM = videoM;
            pS = videoS;
        }
        if(pM < 0 || pS < 0){
            pM = 0;
            pS = 0;
        }
        
        cout << pM << ", " << pS <<"\n";
    }
    if(to_string(pM).length() == 1) answer += "0";
    answer += to_string(pM);
    answer += ":";
    if(to_string(pS).length() == 1) answer += "0";
    answer += to_string(pS);
    
    return answer;
}