#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N,M,ans = 0;
char list[31][31];

void drop_block(){
    for(int i=N-2;i>=0;i--){
        for(int j = 0;j < M;j++){
            if(list[i][j] == 'n') continue;
            int tmp = i+1;
            char c = list[i][j];
            while(tmp < N && list[tmp][j] == 'n') tmp++;
            list[i][j] = 'n';
            list[tmp - 1][j] = c;
        }
    }
}

bool find_block(){
    bool visited[31][31] = {false};
    
    bool flag = false;
    for(int i=0;i < N - 1;i++){
        for(int j = 0;j< M - 1;j++){
            if(list[i][j] == 'n') continue;
            
            char c = list[i][j];
            //2*2 다 같은 이모티콘 인지
            if(list[i][j+1] == c && list[i+1][j] == c && list[i+1][j+1] == c ) {
                visited[i][j] = true;
                visited[i][j+1] = true;
                visited[i+1][j] = true;
                visited[i+1][j+1] = true;
                flag = true;
            }   
        }
    }
    
    if(!flag) return flag;
    //블록 삭제
    for(int i=0;i< N;i++){
        for(int j = 0;j< M;j++){
            if(!visited[i][j]) continue;
            list[i][j] = 'n';
            ans++;
        }
    }    
    
    return true;
}


int solution(int m, int n, vector<string> board) {
    //초기 전역변수 할당
    N = m;
    M = n;
    for(int i=0;i<N;i++){
        for(int j = 0;j < M;j++) list[i][j] = board[i][j];
    }
    
    while(true){
        //블록 떨어뜨리기
        drop_block();  
        
        //2*2인 블록 찾기
        if(!find_block()) break;  
    }
    
    return ans;
}