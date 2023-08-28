#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(int n, int t, int m, int p) {
    int temp = 0, num = 0;
    string s;
    
    s += '0';
    while(s.length() < t*m){
        //진수 변환
        temp++;
        int num = temp;
        string s1;
        while(num > 0){
            int i=0;
            i = num % n;
            num /= n;
            if(i >= 10){
                s1 += ( i - 10 + 'A');
            }else s1 += i+'0';
        }
        reverse(s1.begin(), s1.end());
        s += s1;
    }
    
    //튜브 숫자 찾기
    string answer = "";
    int idx = 1;
    for(int i=0;i<s.length();i++){
        if(idx == p) answer += s[i];   
        if(answer.length() == t) break;
        
        if(idx == m ) idx = 1;
        else idx++;
    }
    
    return answer;
}