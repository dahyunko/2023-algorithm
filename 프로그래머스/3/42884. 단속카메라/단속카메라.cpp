#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <limits.h>
#include <iostream>

using namespace std;

struct info{
    int s, e;
};

bool comp(info &a, info &b){
    return a.s < b.s;
}

int solution(vector<vector<int>> routes) {
    int N = routes.size();
    vector<info>list(N);
    
    for(int i=0;i<N;i++){
        list[i] = {routes[i][0], routes[i][1]};
    }
    
    sort(list.begin(), list.end(), comp);
    for(int i=0;i<N;i++){
        cout<< "[" << list[i].s << ", " << list[i].e << "]";
    }
    
    int s = list[0].s;
    int e = list[0].e;
    int cnt = 1;
    for(int i=1;i<N;i++){
        info now = list[i];
        
        if(now.s <= e){ // 범위 안에 들어온 것
            if(now.e < e){
                e = now.e;    
            }
        }else if(now.s > e){ // 범위를 벗어날 시
            cnt++;
            e = now.e;
        }
    }
    
    
    int answer = cnt;
    return answer;
}