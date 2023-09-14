#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

//idea: 피타고라스 이용하여 높이로 구하는 방법

long long solution(int r1, int r2) {
    long long answer = 0;
    
    for(int i=1;i< r2;i++){
        int h1, h2;
        if(i < r1) h1 = (int)ceil(sqrt((ll)r1*r1 - (ll)i*i)); // 올림
        else h1 = 1;
        h2 = (int)floor(sqrt((ll)r2*r2 - (ll)i*i)); // 내림
        
        //cout<< h2<<' '<<h1 <<'\n';
        answer += h2 - h1 + 1;
        
    }
    //cout<< answer;
    answer = (answer + r2 - r1 + 1) * 4;
    
    return answer;
}