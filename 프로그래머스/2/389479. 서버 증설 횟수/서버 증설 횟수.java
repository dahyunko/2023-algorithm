import java.io.*;
import java.util.*;

class Solution {
    public int solution(int[] players, int m, int k) {
        int answer = 0;
        
        Queue<int[]> q = new LinkedList<>();
        int nowServer = 0;
        
        for(int t=0;t<players.length;t++) {
            if(players[t] == 0) continue;
            
            int serverCnt = players[t]/m;
            if(q.isEmpty()){
                q.add(new int[]{serverCnt, t + k});
                answer += serverCnt;
                nowServer += serverCnt;
                continue;
            }
            
            // 시간 지난 서버 날리기
            while(!q.isEmpty()) {
                int[] v = q.peek();
                
                if(v[1] > t) break;
                q.poll();
                nowServer -= v[0];
            }
            
            if(nowServer >= serverCnt) continue;
            q.add(new int[]{serverCnt - nowServer, t + k});
            answer += serverCnt - nowServer;
            nowServer = serverCnt;
        }
        
        return answer;
    }
}