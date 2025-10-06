import java.io.*;
import java.util.*;

public class Main {
  static int N, a, b, result = Integer.MAX_VALUE;
  static List<Integer>[] graph;
  static int[] dp;

  static void dfs(int v, int cnt) {
    if(dp[v] <= cnt) return;
    dp[v] = cnt;

    if(v == b){
      result = Math.min(result, dp[v]);
      return;
    }

    for(int it : graph[v]) {
      dfs(it, cnt + 1);
    }    
  }

  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    // init
    N = Integer.parseInt(br.readLine());
    graph = new ArrayList[N+1];
    dp = new int[N+1];
    for(int i=0;i<=N;i++) {
      graph[i] = new ArrayList<>();
      dp[i] = Integer.MAX_VALUE;
    }

    StringTokenizer st = new StringTokenizer(br.readLine());
    a = Integer.parseInt(st.nextToken());
    b = Integer.parseInt(st.nextToken());

    int M = Integer.parseInt(br.readLine());
    for(int i=0;i<M;i++){
      st = new StringTokenizer(br.readLine());
      int x = Integer.parseInt(st.nextToken());
      int y = Integer.parseInt(st.nextToken());

      graph[x].add(y);
      graph[y].add(x);
    }

    dfs(a, 0);
    
    System.out.println(result == Integer.MAX_VALUE ? -1 : result);
  }
}
