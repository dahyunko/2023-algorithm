import java.io.*;
import java.util.*;

public class Main {
  static int N;
  static int[][] graph, dp;
  static int[] x = {1, -1, 0, 0};
  static int[] y = {0, 0, 1, -1};

  static int solve(int a, int b){
    if(dp[a][b] != 0){
      return dp[a][b];
    } 

    dp[a][b] = 1;

    for(int i=0;i<4;i++){
      int aa = a + x[i];
      int bb = b + y[i];

      if(aa>=0 && aa<N && bb>=0 && bb<N){
        if(graph[aa][bb] > graph[a][b]){
          dp[a][b] = Math.max(solve(aa, bb) + 1, dp[a][b]);

        }
      }
    }
    return dp[a][b];
  }

  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    
    N = Integer.parseInt(st.nextToken());
    graph = new int[N][N];
    dp = new int[N][N];

    for(int i=0;i<N;i++){
      st = new StringTokenizer(br.readLine());
      for(int j=0;j<N;j++){
        graph[i][j] = Integer.parseInt(st.nextToken());
        dp[i][j] = 0;
      }
    }

    int answer = 0;
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        dp[i][j] = solve(i, j);
        answer = Math.max(dp[i][j], answer);
      }
    }

    System.out.println(answer);    
  }
}
