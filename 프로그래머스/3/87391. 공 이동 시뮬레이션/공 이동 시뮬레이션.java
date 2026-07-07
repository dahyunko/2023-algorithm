import java.io.*;
import java.util.*;

class Solution {
    static long N,M,A1,B1,A2,B2;
    
    static private long isInA(long a) {
        if(a >= 0 && a < N) return a;
        else if(a < 0) return 0;
        else return N-1;
    } 
    
    static private long isInB(long b) {
        if(b >= 0 && b < M) return b;
        else if(b < 0) return 0;
        else return M-1;
    } 
    
    public long solution(int n, int m, int x, int y, int[][] queries) {
        long answer = 0;
        int queryCnt = queries.length;
        
        N = n; M = m;
        // 범위로 접근 해야함
        A1 = A2 = x; B1 = B2 = y;
        
        // 종착지에서 역방향으로 진행해야 함
        for(int i=queryCnt-1;i>=0;i--) {
            int dx = queries[i][1];

            if(queries[i][0] == 0){
                if(B1 > 0) B1 += dx;
                B2 = Math.min(M-1, B2 + dx);
            }
            else if(queries[i][0] == 1) {
                if(B2 < M-1) B2 -= dx;
                B1 = Math.max(0, B1 - dx);
            }
            else if(queries[i][0] == 2) {
                if(A1 > 0) A1 += dx;
                A2 = Math.min(N-1, A2 + dx);
            }
            else if(queries[i][0] == 3) {
                if(A2 < N-1) A2 -= dx;
                A1 = Math.max(0, A1 - dx);
            }
            
            if(A1 >= N || A2 < 0 || B1 >= M || B2 < 0 ) return 0;
        }
        
        
        System.out.println("A1 : " + A1 + " B1 :" + B1);
        System.out.println("A2 : " + A2 + " B2 :" + B2);
        answer = (A2 - A1 + 1) * (B2 - B1 + 1);
        
        return answer;
    }
}