import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    StringBuilder sb = new StringBuilder();

    Long T, K, answer;
    T = Long.parseLong(br.readLine());

    for(int t=0;t<T;t++){
      K = Long.parseLong(br.readLine());
      st = new StringTokenizer(br.readLine());
      answer = 0L;

      PriorityQueue<Long> pq = new PriorityQueue<>();

      for(int i=0;i<K;i++){
        pq.add(Long.parseLong(st.nextToken()));
      }

      Long a, b, temp;
      while(pq.size() > 1){
        a = pq.poll();
        b = pq.poll();

        temp = a + b;
        answer += temp;
        pq.add(temp);
      }

      sb.append(answer).append('\n');
    }

    System.out.println(sb.toString());
  }  
}