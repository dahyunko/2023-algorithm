import java.io.*;
import java.util.*;

public class Main {

  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;

    long result = 0;
    long T = Long.parseLong(br.readLine());
    int N = Integer.parseInt(br.readLine());
    long[] aArr = new long[N+1];

    st = new StringTokenizer(br.readLine());
    for(int i=1;i<=N;i++) { // 누적합
      aArr[i] = Integer.parseInt(st.nextToken()) + aArr[i-1];
    }

    int M = Integer.parseInt(br.readLine());
    long[] bArr = new long[M+1];

    st = new StringTokenizer(br.readLine());
    for(int i=1;i<=M;i++) { // 누적합
      bArr[i] = Integer.parseInt(st.nextToken()) + bArr[i-1];
    }

    HashMap<Long, Long> map = new HashMap<>();

    // b 부분 집합 탐색
    for(int a=0;a<M;a++) {
      for(int b=a+1;b<=M;b++) {
        long temp = bArr[b] - bArr[a];
        long cnt = map.getOrDefault(temp, 0L);
        map.put(temp, cnt+1);
      }
    }

    // A의 부분 집합
    for(int i=0;i<N;i++) {
      for(int j=i+1;j<=N;j++) {
        long aSum = aArr[j] - aArr[i];
        long temp = T - aSum;
        result += map.getOrDefault(temp, 0L);
      }
    }

    System.out.println(result);
  }
}
