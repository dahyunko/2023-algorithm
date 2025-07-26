import java.io.*;
import java.util.*;

public class Main {
  static int R, C, storeCnt, x, y, result = 0;
  static int[][] edge, place;

  static int distance(int x1, int y1, int x2, int y2) {
    return Math.abs(x1 - x2) + Math.abs(y1 - y2);
  }

  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    R = Integer.parseInt(st.nextToken());// 가로
    C = Integer.parseInt(st.nextToken());// 세로
    edge = new int[4][2];
    edge[0][0] = 0;
    edge[0][1] = 0;
    edge[1][0] = 0;
    edge[1][1] = R;
    edge[2][0] = C;
    edge[2][1] = 0;
    edge[3][0] = C;
    edge[3][1] = R;

    storeCnt = Integer.parseInt(br.readLine());
    
    place = new int[storeCnt][2];
    for(int i=0;i<storeCnt;i++){
      st = new StringTokenizer(br.readLine());
      
      place[i][0] = Integer.parseInt(st.nextToken());
      place[i][1] = Integer.parseInt(st.nextToken());
    }

    // 1:위, 2:아래, 3:왼, 4: 오른
    st = new StringTokenizer(br.readLine());
    x = Integer.parseInt(st.nextToken());
    y = Integer.parseInt(st.nextToken());

    switch (x) {
      case 1 : 
        x = C;
        break;
      case 2 : 
        x = 0;
        break;
      case 3 : 
        x = C - y;
        y = 0;
        break;
      case 4 : 
        x = C - y;
        y = R;
        break; 
    }
    
    int[] userDis = new int[4];
    for(int i=0;i<4;i++){
      userDis[i] = distance(x, y, edge[i][0], edge[i][1]);
    }

    for(int i=0;i<storeCnt;i++){
      int a = place[i][0];      
      int b = place[i][1];      

      switch (a) {
        case 1 : 
          a = C;
          break;
        case 2 : 
          a = 0;
          break;
        case 3 : 
          a = C - b;
          b = 0;
          break;
        case 4 : 
          a = C - b;
          b = R;
          break; 
      }

      int temp = Integer.MAX_VALUE;
      if(x==a && (x == 0 || x == C)){
        temp = distance(a, b, x, y);
      }
      if(y==b && (y == 0 || y == R)){
        temp = distance(a, b, x, y);
      }
      for(int j=0;j<4;j++){
        int tmp = userDis[j] + distance(a, b, edge[j][0], edge[j][1]);
        temp = Math.min(temp, tmp);
      }

      result += temp;
    }

    System.out.println(result);
    }
}
