import java.io.*;
import java.util.*;

public class Main {
  static int N, M;
  static int[] a = {0, 0, 1, -1};
  static int[] b = {1, -1, 0, 0};

  static class PAIR {
    int x, y;
    PAIR(int x, int y) {
      this.x = x;
      this.y = y;
    }
  }

  static class INFO {
    int x, y, w, f;
    INFO(int x, int y, int w, int f) {
      this.x = x;
      this.y = y;
      this.w = w;
      this.f = f;
    }
  }

  static boolean isIn(int x, int y) {
    return x>=0 && x<N && y>=0 && y<M;
  }

  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    M = Integer.parseInt(st.nextToken());
    N = Integer.parseInt(st.nextToken());

    // init
    char[][] board = new char[N][M];
    PAIR[] edge = new PAIR[2];
    int cnt = 0, result = Integer.MAX_VALUE;

    for(int i=0;i<N;i++) {
      String str = br.readLine();
      for(int j=0;j<M;j++) {
        board[i][j] = str.charAt(j);
        if(board[i][j] == 'C') {
          edge[cnt++] = new PAIR(i, j);
        }
      }
    }

    // process
    Queue<INFO> q = new LinkedList<>();
    q.add(new INFO(edge[0].x, edge[0].y, 0, 0));
    q.add(new INFO(edge[0].x, edge[0].y, 0, 1));
    q.add(new INFO(edge[0].x, edge[0].y, 0, 2));
    q.add(new INFO(edge[0].x, edge[0].y, 0, 3));
    
    int[][][] dp = new int[N][M][4];
    for(int i=0;i<N;i++) {
      for(int j=0;j<M;j++) {
        dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = dp[i][j][3] =  Integer.MAX_VALUE;
      }
    }
    
    while(!q.isEmpty()) {
      INFO v = q.poll();

      if(v.x == edge[1].x && v.y == edge[1].y) {
        result = Math.min(v.w, result);
        continue;
      }
      
      if(dp[v.x][v.y][v.f] <= v.w) continue;
      dp[v.x][v.y][v.f] = v.w;

      for(int t=0;t<4;t++) {
        int xx = v.x + a[t];
        int yy = v.y + b[t];

        if(isIn(xx, yy) && board[xx][yy] != '*') {
          q.add(new INFO(xx, yy, v.w + (v.f != t ? 1 : 0), t));
        }
      }
    }

    System.out.println(result);
  }
}
