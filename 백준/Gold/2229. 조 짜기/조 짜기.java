import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int N = Integer.parseInt(br.readLine());

    int[] arr = new int[N];
    int[][] dp = new int[N][N];
    StringTokenizer st = new StringTokenizer(br.readLine());
    for(int i=0;i<N;i++) {
      arr[i] = Integer.parseInt(st.nextToken());
    }

    for(int i=1;i<N;i++) {
      dp[i][i] = Math.abs(arr[i]-arr[0]);
      for(int j=0;j<i;j++) {
        dp[i][j] = dp[i-1][j];

        dp[i][i] = Math.max(dp[i][i], dp[i-1][j] + Math.abs(arr[i]-arr[j+1]));
      }
    }
      
    int ans = 0;
    for(int i=0;i<N;i++) ans = Math.max(ans, dp[N-1][i]);
    System.out.println(ans);
  }
}
