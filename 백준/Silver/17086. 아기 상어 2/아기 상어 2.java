import java.io.*;
import java.util.*;

public class Main {
  
  public static void main(String[] args) throws Exception{
    
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    int N = Integer.parseInt(st.nextToken());
    int M = Integer.parseInt(st.nextToken());

    List<int[]> shark = new LinkedList<>();

    for(int i=0;i<N;i++) {
      st = new StringTokenizer(br.readLine());
      for(int j=0;j<M;j++) {
        int now = Integer.parseInt(st.nextToken());
        if(now == 0) continue;
        shark.add(new int[]{i, j});
      }
    }

    int ans = 0;
    for(int i=0;i<N;i++) {
      for(int j=0;j<M;j++) {
        int result = Integer.MAX_VALUE;
        for(int[] s: shark) {
          result = Math.min(result, Math.max(Math.abs(i - s[0]), Math.abs(j - s[1])));
        }
        ans = Math.max(ans, result);
      }
    }

    System.out.println(ans);
  }
}
