#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

struct info{
  int size, cnt;  
};

bool cmp(info &a, info &b){
    return a.cnt > b.cnt;
}

map<int,int> m;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int N = tangerine.size();
    
    for(int i=0;i<N;i++){
        m[tangerine[i]]++;
    }
    
    vector<info> fruits;
    for(auto it : m){
        fruits.push_back({it.first,it.second});
    }
    
    sort(fruits.begin(), fruits.end(), cmp);
    int temp = 0;
    
    while(true){
        temp += fruits[answer].cnt;
        if(temp >= k) {
            answer++;
            break;
        }
        answer++;
    }
    
    return answer;
}