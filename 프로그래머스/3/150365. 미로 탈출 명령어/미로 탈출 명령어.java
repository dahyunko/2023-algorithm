import java.io.*;
import java.util.*;

// idea 
// impossible 조건은 k 값이 S, E 차이에서 2배수 여야 이동이 가능하다
// 사전순 d l r u

class Solution {
    static int[] a = {1, 0 , 0, -1};
    static int[] b = {0, -1 , 1, 0};
    static char[] move = {'d', 'l', 'r', 'u'};
    static Pair S, E;
    static String result = "";
    static boolean flag = false;
    static int N, M;
    
    static class Pair{
        int x, y;
        
        Pair(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
    
    static int distance(Pair p1, Pair p2){
        return Math.abs(p1.x - p2.x) + Math.abs(p1.y - p2.y);
    }
    
    static boolean isIn(int x, int y){
        return x > 0 && x <= N && y > 0 && y <= M;
    }
    
    static void search(Pair now, int cnt, String str ){
        if(flag) return;
        int temp = distance(now, E);
        
        // 남은 거리가 이동할 수 있는 횟수보다 많은 경우
        if(temp > cnt) return;
        if(cnt == 0 && now.x == E.x && now.y == E.y) {
            flag = true;
            result = str;
            return;
        }
        
        for(int i=0;i<4;i++){
            int xx = now.x + a[i];
            int yy = now.y + b[i];
            
            if(!isIn(xx, yy)) continue;
            search(new Pair(xx, yy), cnt - 1, str + move[i]);
        }
        
    }
    
    public String solution(int n, int m, int x, int y, int r, int c, int k) {
        N = n;
        M = m;
        S = new Pair(x, y);
        E = new Pair(r, c);
        int cnt = distance(S, E);
        
        if(k < cnt || (k - cnt) % 2 != 0) return "impossible";
        
        search(S, k, "");
        
        return result;
    }
}



// d l r u