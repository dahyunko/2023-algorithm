import java.io.*;
import java.util.*;

public class Main {
  static int N;
  static int[] L, J;

  static class INFO implements Comparable<INFO>{
    int l, j;

    INFO(int l, int j){
      this.l = l;
      this.j = j;
    }

    @Override
    public int compareTo(INFO o){
      return this.l - o.l;
    }
  }

  public static void main(String[] strs) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    N = Integer.parseInt(br.readLine());
    L = new int[N];
    J = new int[N];
    INFO[] infos = new INFO[N];
    int[][] dp = new int[N][100];

    // init
    StringTokenizer st = new StringTokenizer(br.readLine());
    for(int i=0;i<N;i++) L[i] = Integer.parseInt(st.nextToken());
    st = new StringTokenizer(br.readLine());
    for(int i=0;i<N;i++) J[i] = Integer.parseInt(st.nextToken());

    for(int i=0;i<N;i++) infos[i] = new INFO(L[i], J[i]);
    Arrays.sort(infos);
    
    for(int i=0;i<N;i++){
      for(int j=0;j<100;j++) dp[i][j] = -1;
    }
    
    // run
    dp[0][0] = 0;
    if(infos[0].l < 100) dp[0][infos[0].l] = infos[0].j;
    for(int i=1;i<N;i++){
      // copy
      for(int j=0;j<100;j++) dp[i][j] = dp[i-1][j];
      
      INFO now = infos[i];
      for(int j=now.l;j<100;j++){
        if(dp[i-1][j - now.l] > -1) {
          dp[i][j] = Math.max(dp[i][j], dp[i-1][j - now.l] + now.j);
        }
      }
    }

    int ans = 0;
    for(int i=0;i<100;i++) ans = Math.max(dp[N-1][i], ans);

    System.out.println(ans == -1 ? 0:ans);
  }  
}
