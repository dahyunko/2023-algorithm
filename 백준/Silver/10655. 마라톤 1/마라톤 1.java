import java.io.*;
import java.util.*;

public class Main {

  static int calDis(int x, int y, int a, int b) {
    return Math.abs(a-x) + Math.abs(b-y);
  }
  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;

    // init
    int N = Integer.parseInt(br.readLine());
    int[][] CP = new int [N][2];
    int total = 0, answer = Integer.MAX_VALUE;
    for(int i=0;i<N;i++) {
      st = new StringTokenizer(br.readLine());
      CP[i][0] = Integer.parseInt(st.nextToken());
      CP[i][1] = Integer.parseInt(st.nextToken());

      if(i == 0) continue;
      // 전체 거리 저장
      total += calDis(CP[i][0], CP[i][1], CP[i-1][0], CP[i-1][1]);
    }

      for(int i=1;i<N-1;i++) {
        int temp = total;
        temp -= calDis(CP[i][0], CP[i][1], CP[i-1][0], CP[i-1][1]);
        temp -= calDis(CP[i][0], CP[i][1], CP[i+1][0], CP[i+1][1]);
        temp += calDis(CP[i+1][0], CP[i+1][1], CP[i-1][0], CP[i-1][1]);
        answer = Math.min(answer, temp);
      }

    System.out.println(answer);
  }
}
