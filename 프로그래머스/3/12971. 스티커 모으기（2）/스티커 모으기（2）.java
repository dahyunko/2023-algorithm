import java.io.*;
import java.util.*;

class Solution {
    public int solution(int sticker[]) {
        int answer = 0;
        int N = sticker.length;
        int[][] dp = new int[N+1][2]; // 0 : 맨 앞에 스티커 사용, 1 : 맨 앞 스티커 사용 안함
        
        // 스티커가 1개면 예외 처리
        if(N == 1) return sticker[0];
        
        dp[0][0] = sticker[0];
        dp[1][1] = sticker[1];
        
        for(int i=2;i<N;i++) {
            dp[i][0] = sticker[i];
            dp[i][1] = sticker[i];
            
            
            for(int j=i-3 < 0 ? 0 : i-3 ;j<i-1;j++) {
                if(i < N-1) dp[i][0] = Math.max(dp[i][0], dp[j][0] + sticker[i]);
                dp[i][1] = Math.max(dp[i][1], dp[j][1] + sticker[i]);
            }
        }
        
        for(int i=0;i<N;i++) {
            // System.out.println(dp[i][0] + " , " + dp[i][1]);
            answer = Math.max(answer, dp[i][0]);
            answer = Math.max(answer, dp[i][1]);
        }
        return answer;
    }
}