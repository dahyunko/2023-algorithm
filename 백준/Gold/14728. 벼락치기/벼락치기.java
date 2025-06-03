import java.io.*;
import java.util.*;


public class Main {
  
  static class Info {
    int I, T; // 중요도, 시간

    Info(){}

    Info(int I, int T){
      this.I = I;
      this.T = T;
    }
  }

  public static void main(String str[]) throws Exception{
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st = new StringTokenizer(br.readLine());

      int N, K;

      N = Integer.parseInt(st.nextToken());
      K = Integer.parseInt(st.nextToken());

      int[] dp = new int[K+1];
      
      List<Info> study = new ArrayList<>();

      // 과목 입력
      for(int t=0;t<N;t++){
        int I, T;
        st = new StringTokenizer(br.readLine());
        T = Integer.parseInt(st.nextToken());
        I = Integer.parseInt(st.nextToken());

        study.add(new Info(I, T));
      }

      Arrays.fill(dp, -1);
      dp[0] = 0;

      for(int i=0;i<N;i++){
        Info now = study.get(i);

        for(int j = K ; j > 0 ;j--){
          if(j-now.T >= 0 && dp[j-now.T] != -1){
            dp[j] = Math.max(dp[j], dp[j-now.T] + now.I);
          }
        }
      }

      int answer = 0;
      for(int i=0;i<=K;i++)answer = Math.max(answer, dp[i]);

      System.out.println(answer);
  }
}