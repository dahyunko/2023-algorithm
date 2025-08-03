import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer sb = new StringTokenizer(br.readLine());

    int N, K;
    N = Integer.parseInt(sb.nextToken());
    K = Integer.parseInt(sb.nextToken());

    int[][] way = new int[N][4];
    int[][] dp = new int[N][K+1];

    for(int i=0;i<N;i++){
      sb = new StringTokenizer(br.readLine());

      // 시간, 모금액
      way[i][0] = Integer.parseInt(sb.nextToken());
      way[i][1] = Integer.parseInt(sb.nextToken());
      way[i][2] = Integer.parseInt(sb.nextToken());
      way[i][3] = Integer.parseInt(sb.nextToken());

      for(int j=0;j<=K;j++){
        dp[i][j] = -1;
      }
    }

    dp[0][way[0][0]] = Math.max(way[0][1], dp[0][way[0][0]]);
    dp[0][way[0][2]] = Math.max(way[0][3], dp[0][way[0][2]]);

    for(int i=1;i<N;i++){
      for(int j=way[i][0];j<=K;j++){
        if(dp[i-1][j-way[i][0]] == -1) continue;
        dp[i][j] = Math.max(dp[i][j], way[i][1] + dp[i-1][j-way[i][0]]);
      }
      
      for(int j=way[i][2];j<=K;j++){
        if(dp[i-1][j-way[i][2]] == -1) continue;
        dp[i][j] = Math.max(dp[i][j], way[i][3] + dp[i-1][j-way[i][2]]);
      }
    }
    
    int ans = 0;
    for(int i=0;i<=K;i++){
      ans = Math.max(ans, dp[N-1][i]);
    }
    System.out.println(ans);
  }
}
