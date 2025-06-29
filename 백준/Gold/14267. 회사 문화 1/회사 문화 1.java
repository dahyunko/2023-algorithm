import java.io.*;
import java.util.*;

public class Main {
  static int N, M;
  static int[] parent, proud;
  static List<Info> infos;
  static List<Integer>[] graph;

  static class Info implements Comparable<Info>{
    int v, w;
    
    Info(int v, int w){
      this.v = v;
      this.w = w;
    }

    @Override
    public int compareTo(Info o){
      return this.v - o.v;
    }
  }

  static int dfs(int now){
    if(parent[now] == -1 || proud[now] > 0) return proud[now];

    return proud[now] += dfs(parent[now]);
  }

  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    StringBuilder sb = new StringBuilder();

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    parent = new int[N+1]; // 상사 정보
    proud = new int[N+1];
    infos = new ArrayList<>();
    graph = new ArrayList[N+1]; // 부하 정보

    for(int i=0;i<=N;i++){
      graph[i] = new ArrayList<>();
    }
    
    st = new StringTokenizer(br.readLine());
    for(int i=1;i<=N;i++){
      parent[i] = Integer.parseInt(st.nextToken());
      if(parent[i] == -1) continue;
      graph[parent[i]].add(i);
    }

    int a,b;
    for(int i=0;i<M;i++){
      st = new StringTokenizer(br.readLine());
      a = Integer.parseInt(st.nextToken());
      b = Integer.parseInt(st.nextToken());

      infos.add(new Info(a, b));
    }

    Collections.sort(infos);

    for(int i=0;i<M;i++){
      Info now = infos.get(i);
      dfs(now.v);
      proud[now.v] += now.w;
    }

    // 전체 그래프 한번 탐색
    Queue<Integer> q = new LinkedList<>();
    q.add(1);

    while(!q.isEmpty()){
      int v = q.poll();

      for(int i=0;i<graph[v].size();i++){
        int next = graph[v].get(i);

        if(proud[v] > proud[next]){
          proud[next] = proud[v];
        }
        q.add(next);
      }
    }

    
    for(int i=1;i<=N;i++){
      sb.append(proud[i]).append(' ');
    }
    System.out.println(sb.toString());
  }
}