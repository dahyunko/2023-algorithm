#include <string>
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    for(int i=0;i<lost.size();i++){
        if(find(reserve.begin(), reserve.end(), lost[i]) != reserve.end()){
            int idx = find(reserve.begin(), reserve.end(), lost[i])-reserve.begin();
            lost[i] = -1;
            reserve[idx] = -1;
        }
    }
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    int i=0, j=0;
    for(int p =0;p<lost.size();p++) if(lost[p]!= -1) {i = p; break;}
    for(int p =0;p<reserve.size();p++) if(reserve[p]!= -1) {j = p; break;}

    while(true){
        if(lost.size()-1< i || reserve.size()-1< j) break;
        if(lost[i]>= reserve[j]-1 && lost[i] <= reserve[j]+1){
            lost[i] = -1;
            i++;
            j++;
        }else if(lost[i]> reserve[j]+1)j++;
        else if(lost[i]<reserve[j]-1) i++;
    }
    
    int cnt=0;
    for(int i=0;i<lost.size();i++) if(lost[i]!= -1) cnt++;
    
    answer = n- cnt;
    return answer;
}