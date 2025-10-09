import java.io.*;
import java.util.*;

public class Main {
  static List<Integer>[] graph;
  static int[] parent, depth, count;
  static boolean[] visited;
  static int N, R, Q;

  static int dfs(int v) {
    if(visited[v]) return 0;
    visited[v] = true;
    count[v]++;

    for(int next: graph[v]) {
      if(visited[next]) continue;
      count[v] += dfs(next);
    }
    return count[v];
  }


  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    StringBuilder sb = new StringBuilder();

    // init
    N = Integer.parseInt(st.nextToken());
    R = Integer.parseInt(st.nextToken());
    Q = Integer.parseInt(st.nextToken());

    graph = new ArrayList[N+1];
    depth = new int[N+1];
    count = new int[N+1];
    parent = new int[N+1];
    visited = new boolean[N+1];
    for(int i=0;i<=N;i++) graph[i] = new ArrayList<>();

    for(int i=0;i<N-1;i++) {
      st = new StringTokenizer(br.readLine());

      int a = Integer.parseInt(st.nextToken());
      int b = Integer.parseInt(st.nextToken());

      graph[a].add(b);
      graph[b].add(a);
    }

    // run
    dfs(R);

    // ans
    for(int i=0;i<Q;i++) {
      int qes = Integer.parseInt(br.readLine());
      sb.append(count[qes]).append("\n");
    }

    System.out.println(sb.toString());
  }
}
