import java.io.*;
import java.util.*;

class Solution {
    static int N, M;
    static boolean[][][] visited;
    static String[] Grid;
    static List<Integer> list = new ArrayList<>();
    
    // up right down left
    static int[] a = {-1, 0, 1, 0};
    static int[] b = {0, 1, 0, -1};
     
    static class INFO{
        int x, y, z;
        
        INFO(){}
        
        INFO(int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }
    }
    
    static int reflect(INFO v) {
        int cnt = 0;
        
        while(!visited[v.x][v.y][v.z]) {
            visited[v.x][v.y][v.z] = true;
            cnt++;
            
            char value = Grid[v.x].charAt(v.y);    
            if(value == 'L') {
                // 왼쪽
                v.z = (v.z + 1) % 4;
            }
            else if(value == 'R') {
                // 오른쪽
                v.z = (v.z + 3) % 4;
            }
            
            v = new INFO((v.x + a[v.z] + N) % N, (v.y + b[v.z] + M) % M, v.z);
        }
        
        return cnt;
    } 
    
    public int[] solution(String[] grid) {            
        Grid = grid;
        N = grid.length;
        M = grid[0].length();
        
        // init
        visited = new boolean[N][M][4];
        
        for(int i=0;i<grid.length;i++) {
            for(int j=0;j<grid[0].length();j++) {
                for(int t=0;t<4;t++){
                    if(visited[i][j][t]) continue;
                    list.add(reflect(new INFO(i, j, t)));           
                }
            }
        }
        
        Collections.sort(list);
        int[] answer = new int[list.size()];
        for(int i=0;i<list.size();i++) answer[i] = list.get(i);
        return answer;
    }
}