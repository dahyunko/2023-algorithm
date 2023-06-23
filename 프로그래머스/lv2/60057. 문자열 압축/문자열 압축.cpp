#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int solution(string s) {
    int answer = 0;
    int n = s.length();
    answer = n;
    int t = n/2;
    
    for(int p=1;p<=t;p++){
        string ans;
        int i=0;
        while(i< n){
            string s1 = s.substr(i,p);
            int c = 0;
            int j = i;
            while(j<n){
                string s2 = s.substr(j,p);
                if(s2 != s1) break;
                j += p;
                c++;
            }
            if(c == 1) ans += s1;
            else ans+= to_string(c)+s1;
            
            i = j;
        }
        int cnt = ans.length();
        //cout<< ans<<'\n';
        answer = min(cnt, answer);
    }
        
    return answer;
}