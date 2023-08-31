#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <iostream>
#include <cctype>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    list<string>L;
    if(cacheSize == 0){
        return cities.size()*5;
    }
    
    for(int i=0;i<cities.size();i++){
        for(int j=0;j<cities[i].length();j++) cities[i][j] = tolower(cities[i][j]);
        auto it = find(L.begin(), L.end(), cities[i]);
        
        //찾은 것
        if(it != L.end()){
            answer++;
            //찾으면 지우고 다시 넣어줘야함
            L.erase(it);
            L.push_back(cities[i]);
            continue;
        }
        //없을 경우
        answer += 5;
        if(L.size() >= cacheSize){//캐시 공간 없을 경우
            L.pop_front();
        }   
        L.push_back(cities[i]);
    }
    
    
    return answer;
}