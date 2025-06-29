import java.io.*;
import java.util.*;

class Solution {
    static int total, N, M;
    static char[][] con;
    static int[] x = {0, 0, 1, -1};
    static int[] y = {1, -1, 0, 0};
    
    static class Info{
        int a, b;
        
        Info(int a, int b){
            this.a = a;
            this.b = b;
        }
    }
    
    static boolean isIn(int a, int b){
        return a >= 0 && a < N+2 && b >= 0 && b < M+2;
    }
    
    static void deleteOuter(char c){
        // bfs로 겉에 부분 탐색
        boolean[][] visited = new boolean[N+2][M+2];
        Queue<Info>q = new LinkedList<>();
        q.add(new Info(0, 0));
        // System.out.println("============");
        while(!q.isEmpty()){
            Info v = q.poll();
            
            if(visited[v.a][v.b]) continue;
            visited[v.a][v.b] = true;
            
            
            for(int i=0;i<4;i++){
                int aa = v.a + x[i];
                int bb = v.b + y[i];
                
                if(isIn(aa, bb) && !visited[aa][bb]){
                    
                    // System.out.println("x: " + aa + ", y: " + bb + ", char: " + con[aa][bb]);
                    // 이동할 수 있는 거리
                    if(con[aa][bb] == '-'){
                        q.add(new Info(aa, bb));    
                    }
                    
                    // 접근 지역
                    if(con[aa][bb] == c){
                        visited[aa][bb] = true;
                        con[aa][bb] = '-';
                        total--;
                    }
                }
            }
        }
        
        // for(int i=0;i<N+2;i++){
        //     for(int j=0;j<M+2;j++){
        //         if(visited[i][j]) System.out.print("1" + con[i][j] + " ");
        //         else System.out.print("0" + con[i][j] + " ");
        //     }
        //     System.out.println();
        // }   
    }
    
    static void deleteAll(char c){
        for(int i=1;i<= N;i++){
            for(int j=1;j<= M;j++){
                if(con[i][j] == c){
                    con[i][j] = '-';
                    total--;
                }
            }
        }
    }
    
    public int solution(String[] storage, String[] requests) {
        int answer = 0;
        N = storage.length;
        M = storage[0].length();
        total = N * M;
        
        con = new char[N + 2][M + 2];
        
        for(int i=0;i<N+2;i++){
            for(int j=0;j<M+2;j++){
                con[i][j] = '-';
            }
        }
        
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                con[i][j] = storage[i-1].charAt(j-1);
            }
        }
        
        for(int t=0;t<requests.length;t++){
            char c = requests[t].charAt(0);
            int l = requests[t].length();
            
            if(l == 1){
                // 밖에 부분만 지움
                deleteOuter(c);
            }
            else if(l > 1) {
                // 전체 다 삭제
                deleteAll(c);
            }
        }
        
        return total;
    }
}