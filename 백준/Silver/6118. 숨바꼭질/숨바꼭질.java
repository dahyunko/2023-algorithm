import java.io.*;
import java.util.*;

public class Main {
  static int N, M;

  static class Info{
    int v, w;

    Info(int v, int w){
      this.v = v;
      this.w = w;
    }
  }

  public static void main(String str[]) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    List<List<Integer>> graph = new ArrayList<>();

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    
    int[] dis = new int[N];

    for(int i=0;i<N;i++){
      graph.add(new ArrayList<>());
      dis[i] = Integer.MAX_VALUE;
    }

    int a, b;
    for(int t = 0 ; t< M ; t++){
      st = new StringTokenizer(br.readLine());
      a = Integer.parseInt(st.nextToken()) - 1;
      b = Integer.parseInt(st.nextToken()) - 1;

      graph.get(a).add(b);
      graph.get(b).add(a);
    }

    // 거리 탐색
    Queue<Info> q = new LinkedList<>();
    q.add(new Info(0, 0));
    while(!q.isEmpty()){
      Info now = q.peek();
      q.poll();

      if(dis[now.v] <= now.w){
        continue;
      }
      dis[now.v] = now.w;

      for(int i : graph.get(now.v)){
        q.add(new Info(i, dis[now.v] + 1));
      }
    }
    // 확인
    int v = 0, d = 0, cnt = 0, maxDis = 0;

    for(int i=0; i< dis.length ; i++){
      if(maxDis > dis[i]){
        continue;
      }
      else if(maxDis == dis[i]){
        cnt++;
      }
      else if(maxDis < dis[i]){
        cnt = 1;
        v = i;
        d = dis[i];
        maxDis = dis[i];
      }
    }

    v++;
    System.out.println(v + " " + d + " " + cnt);
  }
}