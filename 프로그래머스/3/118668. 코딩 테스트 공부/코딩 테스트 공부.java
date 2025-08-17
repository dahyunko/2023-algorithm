import java.io.*;
import java.util.*;

class Solution {
    public int solution(int alp, int cop, int[][] problems) {
        int answer = 0;

        int maxAlp = 0, maxCop = 0;

        for(int[] p : problems){
          maxAlp = Math.max(p[0], maxAlp);
          maxCop = Math.max(p[1], maxCop);
        }

        if(maxAlp <= alp && maxCop <= cop) return 0;
        alp = Math.min(alp, maxAlp);
        cop = Math.min(cop, maxCop);

        int[][] dp = new int[maxAlp+1][maxCop+1];
        for(int i=0;i<=maxAlp;i++){
          for(int j=0;j<=maxCop;j++){
            dp[i][j] = Integer.MAX_VALUE;
          }
        }
        dp[alp][cop] = 0;

        for(int a = alp; a<=maxAlp; a++){
          for(int c = cop; c<=maxCop; c++){
            if(dp[a][c] == Integer.MAX_VALUE) continue;

            // 공부로 +1
            if(a+1 <= maxAlp) dp[a+1][c] = Math.min(dp[a+1][c], dp[a][c] + 1);
            if(c+1 <= maxCop) dp[a][c+1] = Math.min(dp[a][c+1], dp[a][c] + 1);

            // 문제 풀기
            for(int[] p : problems){
              if(a >= p[0] && c >= p[1]){
                int na = Math.min(maxAlp, a + p[2]);
                int nc = Math.min(maxCop, c + p[3]);
                dp[na][nc] = Math.min(dp[na][nc], dp[a][c] + p[4]);
              }
            }
          }
        }

        return dp[maxAlp][maxCop];
    }
}