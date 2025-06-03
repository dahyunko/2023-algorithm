import java.io.*;
import java.util.*;

public class Main {
  public static void main(String strs[]) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N, K;

    N = Integer.parseInt(st.nextToken());
    K = Integer.parseInt(st.nextToken());

    List<Integer> list = new ArrayList<>();

    st = new StringTokenizer(br.readLine());
    for(int i=0;i<N;i++){
      list.add(Integer.parseInt(st.nextToken()));
    }

    int[] dp = new int[K+1];
    for(int j=1;j<=K;j++) dp[j] = Integer.MAX_VALUE;
    dp[0] = 0;

    for(int i=0;i<N;i++){
      int now = list.get(i);

      // 놓치는 것이 없어야 해서 뒤로 탐색해야함함
      for(int j=K;j>=0;j--){
        if(j-now >= 0 && dp[j-now] != Integer.MAX_VALUE) {
          dp[j] = Math.min(dp[j], dp[j-now] + 1);
        }
      }
    }

    if(dp[K] == Integer.MAX_VALUE) System.out.println(-1);
    else System.out.println(dp[K]);
  }
  
}