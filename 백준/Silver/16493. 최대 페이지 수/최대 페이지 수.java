import java.io.*;
import java.util.*;

public class Main {
  static int N, M;

  static class INFO {
    int r, p;

    INFO(int r, int p) {
      this.r = r;
      this.p = p;
    }
  }

  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    // init
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    INFO[] chapter = new INFO[M];
    int[][] dp = new int[M][N+1];

    for(int i=0;i<M;i++) {
      st = new StringTokenizer(br.readLine());

      int r = Integer.parseInt(st.nextToken());
      int p = Integer.parseInt(st.nextToken());

      chapter[i] = new INFO(r, p);

      for(int j=0;j<=N;j++) dp[i][j] = -1;
    }

    // run
    dp[0][0] = 0;
    if(N >= chapter[0].r) dp[0][chapter[0].r] = chapter[0].p;
    for(int i=1;i<M;i++) {
      for(int j=0;j<=N;j++) {
        dp[i][j] = dp[i-1][j];

        if(j-chapter[i].r >= 0 && dp[i-1][j-chapter[i].r] > -1) {
          dp[i][j] = Math.max(dp[i][j], dp[i-1][j-chapter[i].r] + chapter[i].p);
        }
      }
    }
    
    int ans = 0;
    for(int i=0;i<=N;i++) ans = Math.max(ans, dp[M-1][i]);

    System.out.println(ans);
  }
}
