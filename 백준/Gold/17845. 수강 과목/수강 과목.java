import java.util.*;
import java.io.*;

public class Main {
  static class Info{
    int I, T;

    Info(int I, int T){
      this.I = I;
      this.T = T;
    }
  }
  public static void main(String str[]) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    
    int N, K;
    List<Info> Study = new ArrayList<>();

    N = Integer.parseInt(st.nextToken());
    K = Integer.parseInt(st.nextToken());
  
    int I, T;
    for(int i=0;i<K;i++){
      st = new StringTokenizer(br.readLine());
      
      I = Integer.parseInt(st.nextToken());
      T = Integer.parseInt(st.nextToken());
      Study.add(new Info(I, T));
    }

    int[] dp = new int[N+1];

    for(int i=0;i<=N;i++) dp[i] = -1;
    dp[0] = 0;

    for(int i=0;i<K;i++){
      Info now = Study.get(i);

      for(int j = N; j> 0 ;j--){
        if(j-now.T >= 0 && dp[j-now.T] != -1){
          dp[j] = Math.max(dp[j], dp[j-now.T] + now.I);
        }
      }
    }
    
    int answer = 0;
    for(int i=0;i<=N;i++){
      answer = Math.max(answer, dp[i]);
    }
    System.out.println(answer);
  }
}
