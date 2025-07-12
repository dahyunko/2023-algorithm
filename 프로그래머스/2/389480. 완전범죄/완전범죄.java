import java.io.*;
import java.util.*;

class Solution {
    static int[][] list, dp;
    static int N, M, C, result = Integer.MAX_VALUE;
    static Set<String> visitSet = new HashSet<>();
    
    static void dfs(int cnt, int aSum, int bSum) {
        if(cnt == C) {
            result = Math.min(result, aSum);
            return;
        }
        
        if(result <= aSum) return;
        if(aSum >= N || bSum >= M) return;
        
        // set으로 확인해줘야함
        String key = cnt + " " + aSum + " " + bSum;
        if(visitSet.contains(key)) return;
        visitSet.add(key);
        
        if(aSum + list[cnt][0] < N) {
            dfs(cnt + 1, aSum + list[cnt][0], bSum);
        }
        
        if(bSum + list[cnt][1] < M) {
            dfs(cnt + 1, aSum, bSum + list[cnt][1]);
        }
    }
    
    public int solution(int[][] info, int n, int m) {
        int answer = 0;
        
        N = n;
        M = m;
        C = info.length;
        
        list = new int[C+1][2];
        
        for(int i=0;i<C;i++) {
            list[i][0] = info[i][0];
            list[i][1] = info[i][1];
        }
        
        dfs(0, 0, 0);
        
        return result != Integer.MAX_VALUE ? result : -1 ;
    }
}