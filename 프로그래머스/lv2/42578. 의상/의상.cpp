#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include<iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    map<string, int> map;
    
    for(int i=0;i<clothes.size();i++)map[clothes[i][1]]++;
    
    int ans=1;
    for(auto it : map){
        ans *= it.second+1;
        //cout<<map[types[i]]<<'\n';
    }
    answer = ans -1;
    
    return answer;
}