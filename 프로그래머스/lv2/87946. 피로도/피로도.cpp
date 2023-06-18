#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
int N, ans=0;
int list[10] ={0};
bool visited[10]= {false};

void dfs(int k, int cnt, vector<vector<int>> &dun){
    //탐색 절차
    if(ans == N) return;
    if(cnt == N){
        int temp = k;
        int c =0;
        for(int i=0;i<N;i++){
            int t = list[i];
            if(temp < dun[t][0])break;
            c++;
            temp -= dun[t][1];
        }
        ans = max(ans, c);
        return;
    }
    
    for(int i=0;i<N;i++){
        if(!visited[i]){
            visited[i] = true;
            list[cnt] = i;
            dfs(k, cnt+1, dun);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    N = dungeons.size();
    
    dfs(k, 0, dungeons);
    return ans;
}