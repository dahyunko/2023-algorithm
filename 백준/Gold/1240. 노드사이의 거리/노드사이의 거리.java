import java.io.*;
import java.util.*;

public class Main {
  static int N, M;

  static class Node{
    int v, w;

    Node(int v, int w){
      this.v = v;
      this.w = w;
    }
  }

  public static void main(String[] str) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    StringBuilder sb = new StringBuilder();

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    // 그래프 생성
    List<Node>[] graph = new ArrayList[N+1];
    for(int i=0;i<=N;i++){
      graph[i] = new ArrayList<>();
    }

    int a, b, c;
    for(int i=0;i<N-1;i++){
      st = new StringTokenizer(br.readLine());
      a = Integer.parseInt(st.nextToken());
      b = Integer.parseInt(st.nextToken());
      c = Integer.parseInt(st.nextToken());

      graph[a].add(new Node(b, c));
      graph[b].add(new Node(a, c));
    }

    // 탐색
    for(int t=0;t<M;t++){
      st = new StringTokenizer(br.readLine());
      a = Integer.parseInt(st.nextToken());
      b = Integer.parseInt(st.nextToken());

      // 노드 거리 저장
      int[] D = new int[N+1];
      for(int j=0;j<=N;j++) D[j] = Integer.MAX_VALUE;

      Queue<Node> q = new LinkedList<>();
      q.add(new Node(a, 0));

      while(!q.isEmpty()){
        Node now = q.poll();

        if(D[now.v] <= now.w) continue;
        D[now.v] = now.w;

        if(now.v == b){
          break;
        }

        for(int i=0;i<graph[now.v].size();i++){
          Node next = graph[now.v].get(i);
          q.add(new Node(next.v, now.w + next.w));
        }
      }

      sb.append(D[b]).append('\n');
    }

    System.out.println(sb.toString());
  }
}