import java.io.*;
import java.util.*;


public class Main {
  static int N, M;
  static int[][] graph, dp;
  static int[] x = {0, 0, 1, -1};
  static int[] y = {1, -1, 0, 0};

  /*
   * dfs + dp 문제로 top-bottom 으로 진입해야함
   */
  static int findWay(int a, int b){

    // 진입한 적있는 요소
    if(dp[a][b] != -1){
      return dp[a][b];
    }

    dp[a][b] = 0;
    for(int i=0;i<4;i++){
      int aa = a + x[i];
      int bb = b + y[i];

      if(aa>=0 && aa<N && bb>=0 && bb <M){
        if(graph[aa][bb] > graph[a][b]) dp[a][b] += findWay(aa, bb);
      }
    }

    return dp[a][b];
  }
  public static void main(String str[]) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    
    graph = new int[N][M];
    dp = new int[N][M];

    for(int i=0;i<N;i++){
      st = new StringTokenizer(br.readLine());
      for(int j=0;j<M;j++){
        graph[i][j] = Integer.parseInt(st.nextToken());
        dp[i][j] = -1;
      }
    }

    dp[0][0] = 1;

    System.out.println(findWay(N-1, M-1));
  } 
}
