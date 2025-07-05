import java.io.*;
import java.util.*;

// 부르트포스
// 각 차례마다 각 개수 만큼 뽑아서 가능한지 확인해야할듯

class Solution {
    static int N,M, result = 0;
    static boolean[] visited; // 선택 숫자 방문 여부
    static int[] cloneAns;
    static int[][] cloneQ;
    
    static void selectNum(int cnt, int j){
        if(cnt == 5){
            int ans = 0;
            for(int i=0;i<M;i++){
                int temp = 0;
                for(int b=0;b<5;b++){
                    if(visited[cloneQ[i][b]]) temp++;
                }
                if(temp == cloneAns[i]) ans++;
                else {
                    break;
                }
            }
            
            if(ans == M) result++;
            return;
        }
        
        for(int i=j;i<=N;i++){
            if(visited[i]) continue;
            
            visited[i] = true;    
            selectNum(cnt+1, i+1);
            visited[i] = false;    
        }
    }
    
    public int solution(int n, int[][] q, int[] ans) {
        int answer = 0;
        
        N = n;
        M = q.length; // 시도한 횟수
        
        visited = new boolean[N+1];
        
        // 입력값 복제
        cloneAns = new int[M];
        cloneQ = new int[M][5];
        for(int i=0;i<M;i++){
            for(int j=0;j<5;j++){
                cloneQ[i][j] = q[i][j];
            }
            cloneAns[i] = ans[i];
        }
        
        selectNum(0, 1);
        
        return result;
    }
}