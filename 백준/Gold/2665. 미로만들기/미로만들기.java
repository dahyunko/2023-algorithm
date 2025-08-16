import java.io.*;
import java.util.*;

public class Main {
  static int[][] board;
  static int[][] area;
  static int N;
  static int[] a = {-1, 1, 0 , 0};
  static int[] b = {0 , 0, -1, 1};

  static boolean isIn(int x, int y){
    return x >= 0 && x < N && y >= 0 && y < N;
  }

  static void dfs(int x, int y, int c){
    if(x == N - 1 && y == N - 1){
      area[x][y] = Math.min(c, area[x][y]);
      return;
    }
    if(area[x][y] <= c) return;
    area[x][y] = c;

    for(int t =0;t<4;t++){
      int xx = x + a[t];
      int yy = y + b[t];

      if(!isIn(xx, yy)) continue;

      if(board[xx][yy] == 1){
        dfs(xx, yy, c);
      }
      else {
        dfs(xx, yy, c + 1);
      }
    }
  }

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    N = Integer.parseInt(br.readLine());
    board = new int[N+1][N+1];
    area = new int[N+1][N+1];

    for(int i=0;i<N;i++){
      String str = br.readLine();
      for(int j=0;j<N;j++){
        board[i][j] = str.charAt(j) - '0';
        area[i][j] = Integer.MAX_VALUE;
      }
    }

    dfs(0, 0, 0);
    System.out.println(area[N-1][N-1]);
  }
}
