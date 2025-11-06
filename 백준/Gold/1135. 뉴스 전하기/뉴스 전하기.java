import java.io.*;
import java.util.*;

public class Main {
  static int N;
  static List<Integer>[] graph;
  static boolean visited[];
  static int[] parent;

  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;

    N = Integer.parseInt(br.readLine());
    graph = new ArrayList[N];
    visited = new boolean[N];
    parent = new int[N];

    for(int i=0;i<N;i++){
      graph[i] = new ArrayList<>();
      visited[i] = false;
    }

    st = new StringTokenizer(br.readLine());
    for(int i=0;i<N;i++){
      int p = Integer.parseInt(st.nextToken());
      parent[i] = p;
      if(p == -1) continue;
      graph[p].add(i);
    }

    Queue<Integer> q = new LinkedList<>();
    int[] dp = new int[N];

    // leaf 부터 넣기
    for(int i=0;i<N;i++) {
      dp[i] = -1;
      if(graph[i].size() > 0) continue;
      q.add(i);
    }
    
    while(!q.isEmpty()) {
      int v = q.poll();

      if(dp[v] != -1) continue;

      boolean notVisit = false;
      List<Integer> list = new ArrayList<>();
      for(int child : graph[v]){
        if(dp[child] == -1) {
          notVisit = true;
        }
        list.add(dp[child]);
      } 
      Collections.sort(list, Comparator.reverseOrder());
      
      int temp = graph[v].size();
      for(int i=0;i<list.size();i++) {
        temp = Math.max(temp, list.get(i) + i);
      }

      if(notVisit) {
        q.add(v);
        continue;
      }
      dp[v] = temp + 1;
      if(parent[v] != -1) q.add(parent[v]);
    }

    System.out.println(dp[0] - 1);
  }
}