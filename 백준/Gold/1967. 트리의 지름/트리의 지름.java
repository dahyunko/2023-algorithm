import java.io.*;
import java.util.*;

public class Main {
  static int N;
  static List<Node>[] graph;
  static int[] D;

  static class Node{
    int v, w;

    Node(int v, int w){
      this.v = v;
      this.w = w;
    }
  }

  static int findFarNode(int a){
    int resNode=0, ans = 0;
    for(int j=0;j<=N;j++) D[j] = Integer.MAX_VALUE;

    Queue<Node> q = new LinkedList<>();
    q.add(new Node(a, 0));

    while(!q.isEmpty()){
      Node now = q.poll();

      if(D[now.v] <= now.w) continue;
      D[now.v] = now.w;

      for(int j=0;j<graph[now.v].size();j++){
        Node next = graph[now.v].get(j);

        q.add(new Node(next.v, now.w + next.w));
      }
    }

    for(int j=0;j<=N;j++) {
      if(D[j] != Integer.MAX_VALUE && ans < D[j]){
        ans = D[j];
        resNode = j;
      }
    }

    return resNode;
  }

  public static void main(String[] strs) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;

    N = Integer.parseInt(br.readLine());

    graph = new ArrayList[N+1];
    for(int i=0;i<=N;i++) graph[i] = new ArrayList<>();
  
    int a, b, c;
    for(int i=0;i<N-1;i++){
      st = new StringTokenizer(br.readLine());
      a = Integer.parseInt(st.nextToken());
      b = Integer.parseInt(st.nextToken());
      c = Integer.parseInt(st.nextToken());

      graph[a].add(new Node(b, c));
      graph[b].add(new Node(a, c));
    }

    D = new int[N+1];

    // 루트 노드에서 가장 먼 노드 찾음
    int farNode = findFarNode(1);

    // 가장 먼 노드에서 가장 먼 노드 찾음음
    int ansNode = findFarNode(farNode);

    System.out.println(D[ansNode]);
  }
}