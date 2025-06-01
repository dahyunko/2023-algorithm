import java.io.*;
import java.util.*;

public class Main {

  public static void main(String str[]) throws Exception{
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st = new StringTokenizer(br.readLine());

      int N, M, H;

      N = Integer.parseInt(st.nextToken());
      M = Integer.parseInt(st.nextToken());
      H = Integer.parseInt(st.nextToken());

      int[][] dp = new int[N][H+1]; // 블록 개수 저장

      // 초기 리스트 설정
      List<List<Integer>> list = new ArrayList<>();

      for(int i=0;i<N;i++){
        list.add(new ArrayList<>());
        st = new StringTokenizer(br.readLine());

        while(st.hasMoreTokens()){
          int now = Integer.parseInt(st.nextToken());
          if(now > H) continue;
          list.get(i).add(now);
        }

        // 오름차순 정렬
        Collections.sort(list.get(i));
      }

      // 첫 블록은 쌓는다
      for(int i=0;i<list.get(0).size();i++){
        dp[0][list.get(0).get(i)]++;
      }

      // 다음 블록 부터 dp 시작
      for(int i=1;i<N;i++){

        // 첫번째 값 전에 세팅
        for(int t=1;t<=H;t++){
          dp[i][t] = dp[i-1][t];
        }

        // 비교 시작
        for(int j=0;j<list.get(i).size();j++){
          int block = list.get(i).get(j);
          dp[i][block]++;
          dp[i][block] %= 10007;

          for(int z = block + 1; z <= H ; z++){
              dp[i][z] = (dp[i][z] + dp[i-1][z-block]) % 10007;
          }
        }
      }

      System.out.println(dp[N-1][H]);
  }
}