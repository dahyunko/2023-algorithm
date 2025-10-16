import java.io.*;
import java.util.*;

public class Main {
  static int N, K, R, cnt = 0;
  static int[] x = {-1, 0, 1, 0};
  static int[] y = {0, 1, 0, -1};
  static int[][][] board;
  static int[][] cow;

  static int findRoad(int a, int b, int c, int d) {

    if(a > c && b == d) { // 상
      return 0;
    }
    if(a == c && b < d) { // 우
      return 1;
    }
    if(a < c && b == d) { // 하
      return 2;
    }
    return 3; //좌
  }

  static boolean isIn(int a, int b) {
    return (a>=0 && a<N && b>=0 && b<N);
  }

  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    // init
    N = Integer.parseInt(st.nextToken());
    K = Integer.parseInt(st.nextToken());
    R = Integer.parseInt(st.nextToken());

    board = new int[N][N][4];
    cow = new int[K][2];

    // 울타리
    for(int i=0;i<R;i++) {
      st = new StringTokenizer(br.readLine());

      int a,b,c,d;
      a = Integer.parseInt(st.nextToken()) - 1;
      b = Integer.parseInt(st.nextToken()) - 1;
      c = Integer.parseInt(st.nextToken()) - 1;
      d = Integer.parseInt(st.nextToken()) - 1;

      int idx1 = findRoad(a, b, c, d);
      int idx2 = findRoad(c, d, a, b);

      board[a][b][idx1] = 1;
      board[c][d][idx2] = 1;
    }

    // 소위치
    for(int i=0;i<K;i++) {
      st = new StringTokenizer(br.readLine());

      cow[i][0] = Integer.parseInt(st.nextToken()) - 1;
      cow[i][1] = Integer.parseInt(st.nextToken()) - 1;
    }

    for(int i=0;i<K-1;i++){
      ArrayDeque<int[]> q = new ArrayDeque<>();
      q.add(cow[i]);
      boolean[][] visited = new boolean[N][N];

      while (!q.isEmpty()) {
        int[] v = q.poll();

        if(visited[v[0]][v[1]]) continue;
        visited[v[0]][v[1]] = true;

        for(int t=0;t<4;t++){
          int xx = v[0] + x[t];
          int yy = v[1] + y[t];

          if(isIn(xx, yy) && !visited[xx][yy]) {
            int idx = findRoad(v[0], v[1], xx, yy);

            // 길 있어서 접근 불가
            if(board[v[0]][v[1]][idx] == 1) {
              continue;
            }
            int[] next = {xx, yy};
            q.add(next);
          }
        }
      }

      for(int j=i+1;j<K;j++) {
        if(!visited[cow[j][0]][cow[j][1]]) cnt++;
      }
    }

    System.out.println(cnt);
  }
}
