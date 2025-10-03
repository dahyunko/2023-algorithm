import java.io.*;
import java.util.*;

public class Main {
  static int N;
  static int[] L, J;

  public static void main(String[] strs) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    N = Integer.parseInt(br.readLine());
    L = new int[N];
    J = new int[N];
    int[][] dp = new int[N][100];

    // init
    StringTokenizer st = new StringTokenizer(br.readLine());
    for(int i=0;i<N;i++) L[i] = Integer.parseInt(st.nextToken());
    st = new StringTokenizer(br.readLine());
    for(int i=0;i<N;i++) J[i] = Integer.parseInt(st.nextToken());
    
    for(int i=0;i<N;i++){
      for(int j=0;j<100;j++) dp[i][j] = -1;
    }
    
    // run
    dp[0][0] = 0;
    if(L[0] < 100) dp[0][L[0]] = J[0];
    for(int i=1;i<N;i++){
      for(int j=0;j<100;j++){
        dp[i][j] = dp[i-1][j];
        if(j - L[i] >= 0 && dp[i-1][j - L[i]] > -1) {
          dp[i][j] = Math.max(dp[i][j], dp[i-1][j - L[i]] + J[i]);
        }
      }
    }

    int ans = 0;
    for(int i=0;i<100;i++) ans = Math.max(dp[N-1][i], ans);
    System.out.println(ans);
  }  
}
