#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include<iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    vector<string>types;
    map<string, int> map;
    
    for(int i=0;i<clothes.size();i++){
        if(find(types.begin(), types.end(), clothes[i][1]) == types.end()){
            types.push_back(clothes[i][1]);
            map[clothes[i][1]] = 0;
        }
        map[clothes[i][1]]++;
    }
    
    int ans=1;
    for(int i=0;i<types.size();i++){
        ans *= map[types[i]]+1;
        //cout<<map[types[i]]<<'\n';
    }
    answer = ans -1;
    
    return answer;
}