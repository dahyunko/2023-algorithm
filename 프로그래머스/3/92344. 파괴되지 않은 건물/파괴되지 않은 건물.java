import java.io.*;
import java.util.*;

class Solution {
    static int N, M;
    static int[][] tBoard = new int[1002][1002];
    
    public int solution(int[][] board, int[][] skill) {
        int answer = 0;
        
        // init
        N = board.length;
        M = board[0].length;
        
        // 누적합
        int x1, y1, x2, y2, degree;
        for(int t=0;t<skill.length;t++){
            x1 = skill[t][1];
            y1 = skill[t][2];
            x2 = skill[t][3];
            y2 = skill[t][4];
            degree = skill[t][5] * (skill[t][0] == 1 ? -1 : 1 );
            
            tBoard[x1][y1] += degree;
            tBoard[x1][y2+1] += degree*(-1);
            tBoard[x2+1][y1] += degree*(-1);
            tBoard[x2+1][y2+1] += degree;
        }
        
        // 가로 누적합
        for(int i=0;i<=N;i++){
            for(int j=1;j<=M;j++){
                tBoard[i][j] += tBoard[i][j-1];
            }
        }
        
        // 세로 누적합
        for(int i=0;i<=M;i++){
            for(int j=1;j<=N;j++){
                tBoard[j][i] += tBoard[j-1][i];
            }
        }
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(tBoard[i][j] + board[i][j] > 0) answer++;
            }
        }
        
        return answer;
    }
}