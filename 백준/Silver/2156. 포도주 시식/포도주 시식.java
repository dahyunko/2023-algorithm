import java.io.*;
import java.util.*;

public class Main {

  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    int N = Integer.parseInt(br.readLine());
    int[] arr = new int[N];
    int[][] dp = new int[N][2];
    for(int i=0;i<N;i++) {
      arr[i] = Integer.parseInt(br.readLine());
    }

    if(N < 3) {
      System.out.println(arr[0] + (N == 1 ? 0 : arr[1]));
      return;
    }

    dp[0][0] = arr[0];
    dp[0][1] = arr[0]; // 이전 포도주를 마심
    dp[1][0] = arr[1];
    dp[1][1] = arr[1] + arr[0];

    int ans = arr[1] + arr[0];
    for(int i=2;i<N;i++){

      dp[i][0] = dp[i][1] = arr[i];

      if(i > 2) {
        dp[i][0] = Math.max(dp[i][1], arr[i] + Math.max(dp[i-3][0] + arr[i-2], dp[i-3][1]));
        dp[i][1] = Math.max(dp[i][1], arr[i] + arr[i-1] + Math.max(dp[i-3][0], dp[i-3][1]));
      }
      dp[i][0] = Math.max(dp[i][0], arr[i] + Math.max(dp[i-2][0], dp[i-2][1]));
      dp[i][1] = Math.max(dp[i][1], arr[i] + dp[i-1][0]);

      ans = Math.max(ans, Math.max(dp[i][0], dp[i][1]));
    }

    System.out.println(ans);
  }
  
}