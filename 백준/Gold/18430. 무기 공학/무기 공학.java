import java.io.*;
import java.util.*;

public class Main {
  static int[][] board = new int[6][6];
  static boolean[][] visited = new boolean[6][6];
  static int N, M;
  static int[] a = {-1, 0, 1, 0};
  static int[] b = {0, 1, 0, -1};  

  static boolean isTrue(int x, int y){
    return (x>=0 && x<N && y>=0 && y<M);
  }

  static int Boomerang(int x, int y){
    int result = 0;

    for(int t=0;t<4;t++){
      int x1 = x + a[t];
      int y1 = y + b[t];
      int x2 = x + a[(t+1)%4];
      int y2 = y + b[(t+1)%4];

      if(!isTrue(x1, y1) || !isTrue(x2, y2)) continue;
      if(visited[x1][y1] || visited[x2][y2]) continue;

      int sum = board[x][y] * 2 + board[x1][y1] + board[x2][y2];

      visited[x][y] = true;
      visited[x1][y1] = true;
      visited[x2][y2] = true;

      int c = y+1;
      int temp = 0;
      for(int i=x;i<N;i++){
        for(int j = c;j<M;j++){
          if(visited[i][j]) continue;
          temp = Math.max(temp, Boomerang(i, j));
        }
        c = 0;
      }

      visited[x][y] = false;
      visited[x1][y1] = false;
      visited[x2][y2] = false;

      result = Math.max(result, sum + temp);
    }

    return result;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    
    for(int i=0;i<N;i++){
      st = new StringTokenizer(br.readLine());
      for(int j=0;j<M;j++){
        board[i][j] = Integer.parseInt(st.nextToken());
        visited[i][j] = false;
      }
    }

    int answer = 0;
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        answer = Math.max(Boomerang(i, j), answer);
      }
    }
    System.out.println(answer);
  } 
}