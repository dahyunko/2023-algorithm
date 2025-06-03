import java.util.*;
import java.io.*;

public class Main {
  public static void main(String str[]) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N, M;
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    int[][] graph = new int[N+1][M+1];
    int[][][] dp = new int[N+1][M+1][3]; // 0 : 왼쪽, 1 : 위쪽, 2 : 오른쪽

    for(int i=1;i<=N;i++){
      st = new StringTokenizer(br.readLine());
      for(int j=1;j<=M;j++){
        graph[i][j] = Integer.parseInt(st.nextToken());
        for(int w =0;w<3;w++) dp[i][j][w] = -101 * N* M;
      }  
    }

    dp[1][1][0] = dp[1][1][1] = dp[1][1][2] = graph[1][1];

    for(int i=1;i<=N;i++){
      for(int j=1;j<=M;j++){
        if(j > 1) dp[i][j][0] = Math.max(dp[i][j-1][0], dp[i][j-1][1]) + graph[i][j];
        if(i > 1) dp[i][j][1] = Math.max(dp[i-1][j][0], Math.max(dp[i-1][j][1], dp[i-1][j][2])) + graph[i][j];
      }  
      for(int j=M-1;j>0;j--){
        dp[i][j][2] = Math.max(dp[i][j+1][2], dp[i][j+1][1]) + graph[i][j];
      }
    }

    System.out.println(Math.max(dp[N][M][0], dp[N][M][1]));
  }
  
}