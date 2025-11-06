import java.io.*;
import java.util.*;

public class Main{
  static int N;
  static List<String> strs = new ArrayList<>();
  static List<String> words = new ArrayList<>();
  static List<List<Integer>> graph = new ArrayList<>();
  static boolean[] visited;
  static StringBuilder sb = new StringBuilder();

  static void dfs(int v, int depth) {
    if(visited[v]) return;
    visited[v] = true;

    if(depth > 0) {
      String str = "";
      for(int i=0;i<depth-1;i++) str += "--";
      str += words.get(v);
      sb.append(str);
      sb.append("\n");
    }

    for(int next : graph.get(v)) {
      dfs(next, depth+1);
    }
  }

  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    N = Integer.parseInt(br.readLine());
    
    for(int i=0;i<N;i++) {
      st = new StringTokenizer(br.readLine());    

      int M = Integer.parseInt(st.nextToken());
      String str = "";
      for(int j=0;j<M;j++) {
        str += st.nextToken() + " ";
      }

      strs.add(str);
    }

    Collections.sort(strs);

    words.add("default");
    graph.add(new ArrayList<>());

    for(int i=0;i<strs.size();i++) {
      String[] list = strs.get(i).split(" ");
      int idx = 0;

      for(int j=0;j<list.length;j++) {
        int next = -1;

        for(int node : graph.get(idx)) {
          if(words.get(node).equals(list[j])) {
            next = node;
            break;
          }
        }

        if(next == -1) {
          words.add(list[j]);
          graph.add(new ArrayList<>());
          next = words.size() - 1;
          graph.get(idx).add(next);
        }
        idx = next;
      }
    }

    // print
    visited = new boolean[words.size()];
    dfs(0, 0);

    System.out.println(sb.toString());
  }
}
