#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef pair<int, char> info;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    vector<info> result;
    int r =0, t = 0, f = 0,c=0,m=0,j=0,a=0,n=0;
    
    result.push_back(info(0,'R'));
    result.push_back(info(0,'C'));
    result.push_back(info(0,'J'));
    result.push_back(info(0,'A'));
    
    for(int i=0;i<survey.size();i++){
        if(survey[i] == "RT" || survey[i] == "TR" ){
            if(survey[i][0]== 'R'){
                switch(choices[i]){
                    case 1: r += 3; break;
                    case 2: r += 2; break;
                    case 3: r += 1; break;
                    case 5: t += 1; break;
                    case 6: t += 2; break;
                    case 7: t += 3; break;
                    default: break;      
                }    
            }else{
                switch(choices[i]){
                    case 1: t += 3; break;
                    case 2: t += 2; break;
                    case 3: t += 1; break;
                    case 5: r += 1; break;
                    case 6: r += 2; break;
                    case 7: r += 3; break;
                    default: break;      
                }
            }
            if(r >= t){
                result[0].first = r;
                result[0].second = 'R';
            }    
            else{
                result[0].first = t;
                result[0].second = 'T';
            }
        }
        if(survey[i] == "FC" || survey[i] == "CF" ){
            if(survey[i][0]== 'F'){
                switch(choices[i]){
                    case 1: f += 3; break;
                    case 2: f += 2; break;
                    case 3: f += 1; break;
                    case 5: c += 1; break;
                    case 6: c += 2; break;
                    case 7: c += 3; break;
                    default: break;      
                }    
            }else{
                switch(choices[i]){
                    case 1: c += 3; break;
                    case 2: c += 2; break;
                    case 3: c += 1; break;
                    case 5: f += 1; break;
                    case 6: f += 2; break;
                    case 7: f += 3; break;
                    default: break;      
                }
            }
            if(c >= f){
                result[1].first = c;
                result[1].second = 'C';
            }    
            else{
                result[1].first = f;
                result[1].second = 'F';
            }
        }
        if(survey[i] == "MJ" || survey[i] == "JM" ){
            if(survey[i][0]== 'M'){
                switch(choices[i]){
                    case 1: m += 3; break;
                    case 2: m += 2; break;
                    case 3: m += 1; break;
                    case 5: j += 1; break;
                    case 6: j += 2; break;
                    case 7: j += 3; break;
                    default: break;      
                }    
            }else{
                switch(choices[i]){
                    case 1: j += 3; break;
                    case 2: j += 2; break;
                    case 3: j += 1; break;
                    case 5: m += 1; break;
                    case 6: m += 2; break;
                    case 7: m += 3; break;
                    default: break;      
                }
            }
            if(j >= m){
                result[2].first = j;
                result[2].second = 'J';
            }    
            else{
                result[2].first = m;
                result[2].second = 'M';
            }  
        }
        if(survey[i] == "AN" || survey[i] == "NA" ){
            if(survey[i][0]== 'A'){
                switch(choices[i]){
                    case 1: a += 3; break;
                    case 2: a += 2; break;
                    case 3: a += 1; break;
                    case 5: n += 1; break;
                    case 6: n += 2; break;
                    case 7: n += 3; break;
                    default: break;      
                }    
            }else{
                switch(choices[i]){
                    case 1: n += 3; break;
                    case 2: n += 2; break;
                    case 3: n += 1; break;
                    case 5: a += 1; break;
                    case 6: a += 2; break;
                    case 7: a += 3; break;
                    default: break;      
                }
            }
            if(a >= n){
                result[3].first = a;
                result[3].second = 'A';
            }    
            else{
                result[3].first = n;
                result[3].second = 'N';
            }   
        }
    }
    
    for(int i=0; i<result.size();i++){
        answer.push_back(result[i].second);
    }
    
    return answer;
}