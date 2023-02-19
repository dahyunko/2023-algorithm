#include <string>
#include <vector>
#include<limits.h>
#include<queue>
#include<tuple>

using namespace std;
typedef tuple<int, int, int> info;

bool find_level = false;
int l_cnt = INT_MAX;

int bfs(vector<string> &maps,vector<vector<bool>> &visited, int v_i, int v_j, int cnt, int N, int M, char f_char){
    queue<info> q;
    q.push(make_tuple(v_i, v_j, cnt));
    visited[v_i][v_j] = true;
    
    while(!q.empty()){
        info v = q.front();
        q.pop();
        v_i= get<0>(v);
        v_j= get<1>(v);
        cnt= get<2>(v);
        
        if(maps[v_i][v_j] == f_char ){//확인
            find_level = true;
            l_cnt = min(cnt, l_cnt);
            return l_cnt;
        }
        
        if(v_i-1>=0){
         if(maps[v_i-1][v_j] != 'X'){
            if(!visited[v_i-1][v_j]) {
                visited[v_i-1][v_j] = true;
                q.push(make_tuple(v_i-1, v_j, cnt+1));
            }
         }   
        }
        if(v_i+1<=N){
         if(maps[v_i+1][v_j] != 'X'){
             if(!visited[v_i+1][v_j]) {
                 visited[v_i+1][v_j] = true;
                q.push(make_tuple(v_i+1, v_j, cnt+1));
             }
         }   
        }
        if(v_j-1>=0){
         if(maps[v_i][v_j-1] != 'X'){
             if(!visited[v_i][v_j-1]) {
                 visited[v_i][v_j-1] = true;
                q.push(make_tuple(v_i, v_j-1, cnt+1));
             }
         }   
        }
        if(v_j+1<=M){
         if(maps[v_i][v_j+1] != 'X'){
             if(!visited[v_i][v_j+1]) {
                visited[v_i][v_j+1] = true;
                q.push(make_tuple(v_i, v_j+1, cnt+1));   
             }
         }   
        } 
    }
    
    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;
    int N_i = maps.size();
    int N_j = maps[0].size();
    vector<vector<bool>> visited(N_i, vector<bool> (N_j, false));
    int a, b;
    
    //시작점 찾기
    for(int i=0;i<N_i;i++){
        for(int j=0;j<N_j;j++){
            if(maps[i][j] == 'S'){
                a = bfs(maps, visited, i, j, 0, N_i-1, N_j-1, 'L');
                break;
            }
        }
    }
    
    //방문 배열 초기화
    for(int i=0;i<N_i;i++){
        fill(visited[i].begin(), visited[i].end(), false);
    }
    
    //s가 l을 찾았을 때, level 찾고 end 찾기
    if(find_level){
        l_cnt = INT_MAX;
        find_level = false;
        for(int i=0;i<N_i;i++){
            for(int j=0;j<N_j;j++){
                if(maps[i][j] == 'L'){
                    b = bfs(maps, visited, i, j, 0, N_i-1, N_j-1, 'E');
                    break;
                }
            }
        }
    }
    
    if(a !=-1 && b != -1) answer = a+b;
    else answer = -1;        
    return answer;
}