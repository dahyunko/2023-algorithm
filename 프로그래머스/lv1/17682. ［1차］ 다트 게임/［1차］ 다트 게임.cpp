#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(string dartResult) {
    int other_score = 0, pre = 0, now = 0;
    
    for(int i=0;i<dartResult.length();i++){
        char c = dartResult[i];
        if(c >= '0' && c<='9'){
            if(c == '1' && i+1 < dartResult.length() && dartResult[i+1] == '0'){
                i++;
                other_score += pre;
                pre = now;
                now = 10;
            }
            else {
                other_score += pre;
                pre = now;
                now = c-'0';
            }
        }
        else if(c == 'S') continue;
        else if(c == 'D') now = pow(now, 2);
        else if(c == 'T') now = pow(now, 3);
        else if(c == '*'){
            pre = pre*2;
            now = now*2;
        }
        else if(c == '#') now = now*(-1);
    }
    
    
    int answer = now + pre + other_score;
    return answer;
}