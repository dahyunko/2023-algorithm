import java.io.*;
import java.util.*;

public class Main {
  static int N, M, k;
  static int[] payment;
  static List<Integer>[] graph;
  static boolean[] visited;
  static int money, cnt;
  static int ansMoney = 0, ansCnt = 0;

  static void dfs(int now){
    cnt++;
    visited[now] = true;
    money = Math.min(money, payment[now]);

    for(int i=0;i<graph[now].size();i++){
      int next = graph[now].get(i);

      if(visited[next]) continue;
      dfs(next);
    }
  }
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());  
    M = Integer.parseInt(st.nextToken());  
    k = Integer.parseInt(st.nextToken());  

    payment = new int[N+1];
    graph = new ArrayList[N+1];
    visited = new boolean[N+1];

    st = new StringTokenizer(br.readLine());
    for(int i=1;i<=N;i++){
      payment[i] = Integer.parseInt(st.nextToken());  
      visited[i] = false;
      graph[i] = new ArrayList<>();
    }

    int a, b;
    for(int i=0;i<M;i++){
      st = new StringTokenizer(br.readLine());
      a = Integer.parseInt(st.nextToken());  
      b = Integer.parseInt(st.nextToken());  
      
      if(a == b) continue;
      graph[a].add(b);
      graph[b].add(a);
    }

    // 친구 찾기
    for(int i=1;i<=N;i++){
      if(visited[i]) continue;
      money = payment[i];
      cnt = 0;

      dfs(i);

      ansCnt += cnt;
      ansMoney += money;
    }

    // System.out.println("ansCnt" + ansCnt);
    // System.out.println("ansMoney" + ansMoney);
    if(ansCnt == N && ansMoney <= k){
      System.out.println(ansMoney);
    }
    else {
      System.out.println("Oh no");
    }
  }
  
}
