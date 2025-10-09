import java.util.*;
import java.io.*;

public class Main {

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    // init
    int N = Integer.parseInt(br.readLine());
    int[] arr = new int[N];
    int[] dp = new int[N];

    StringTokenizer st = new StringTokenizer(br.readLine());
    for(int i=0;i<N;i++) {
      arr[i] = Integer.parseInt(st.nextToken());
    }

    // run
    dp[0] = 1;
    for(int i=1;i<N;i++) {
      dp[i] = 1;
      for(int j=0;j<i;j++) {
        if(arr[i] <= arr[j]) continue;
        dp[i] = Math.max(dp[i], dp[j] + 1);
      }
    }

    int ans = 0;
    for(int i=0;i<N;i++) {
      ans = Math.max(ans, dp[i]);
    }

    System.out.println(ans);
  }
}