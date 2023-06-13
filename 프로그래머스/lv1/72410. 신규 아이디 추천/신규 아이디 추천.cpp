#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    int n = new_id.length();
    
    for(int i=0;i<n;i++){
        //대문자일 경우
        if(new_id[i] >= 'A' && new_id[i] <= 'Z')answer.push_back(new_id[i]-'A'+'a');
        else if(new_id[i] >= 'a' && new_id[i] <= 'z') answer.push_back(new_id[i]);
        else if(new_id[i] >= '0' && new_id[i] <= '9') answer.push_back(new_id[i]);
        else if( new_id[i] == '-' || new_id[i] == '_') answer.push_back(new_id[i]);
        else if(new_id[i] == '.'){//'.'연속
            int t = answer.length();
            if(t > 0){
                if(answer[t-1] == '.') continue;
                answer.push_back('.');   
            }
            else if(t == 0) continue;
            else if(i == n-1) continue;
        }
    }
    
    int t = answer.length();
    if(t == 0) return "aaa";
    else{
        if(answer[t-1] == '.') {
            answer.erase(answer.begin() + t-1);
            t--;
        }
        
        if(t< 3){
            char c = answer[t-1];
            while(answer.length()< 3){
                answer.push_back(c);
            }
        }
        else if(t > 15) answer = answer.substr(0, 15);
        if(answer[14] == '.') answer.erase(answer.begin() + 14);
    }
    
    return answer;
}