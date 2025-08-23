import java.io.*;
import java.util.*;

public class Main {
  static int N, result = 0;
  static int[][] board;

  // dir: 0=left, 1=down, 2=right, 3=up
  static int[] dx = {0, 1, 0, -1};
  static int[] dy = {-1, 0, 1, 0};

  // 5x5 마스크 (퍼센트)
  static int[][] LEFT = {
      {0, 0, 2, 0, 0},
      {0,10, 7, 1, 0},
      {5, 0, 0, 0, 0},
      {0,10, 7, 1, 0},
      {0, 0, 2, 0, 0}
  };
  static int[][] DOWN = {
      {0, 0, 0, 0, 0},
      {0, 1, 0, 1, 0},
      {2, 7, 0, 7, 2},
      {0,10, 0,10, 0},
      {0, 0, 5, 0, 0}
  };
  static int[][] RIGHT = {
      {0, 0, 2, 0, 0},
      {0, 1, 7,10, 0},
      {0, 0, 0, 0, 5},
      {0, 1, 7,10, 0},
      {0, 0, 2, 0, 0}
  };
  static int[][] UP = {
      {0, 0, 5, 0, 0},
      {0,10, 0,10, 0},
      {2, 7, 0, 7, 2},
      {0, 1, 0, 1, 0},
      {0, 0, 0, 0, 0}
  };

  // 마스크/오프셋 테이블화: dir 별 [mask, startOffset(2), alphaOffset(2)]
  static int[][][] MASKS = {LEFT, DOWN, RIGHT, UP};
  
  static int[][] ALPHA_OFF = {
      { 2, 1}, // left
      { 3, 2}, // down
      { 2, 3}, // right
      { 1, 2}  // up
  };

  // 현재 위치
  static int cx, cy;

  static boolean isIn(int x, int y) {
    return (x >= 1 && x <= N && y >= 1 && y <= N);
  }

  static int calSand(int sand, int per) {
    return sand * per / 100;
  }

  static void distribute(int dir) {
    // (cx, cy) 칸의 모래를 dir 방향 패턴으로 분산
    int sand = board[cx][cy];
    if (sand == 0) { // 분산할 모래가 없으면 바로 리턴
      return;
    }

    int[][] mask = MASKS[dir];
    int sx = cx - 2;
    int sy = cy - 2;

    int remaining = sand;

    // 5x5 중 0이 아닌 위치만 분산
    for (int i = 0; i < 5; i++) {
      int rowBaseX = sx + i;
      int[] maskRow = mask[i];
      for (int j = 0; j < 5; j++) {
        int per = maskRow[j];
        if (per == 0) continue;

        int amount = calSand(sand, per);
        remaining -= amount;

        int tx = rowBaseX;
        int ty = sy + j;

        if (isIn(tx, ty)) board[tx][ty] += amount;
        else result += amount;
      }
    }

    // alpha 처리
    int ax = sx + ALPHA_OFF[dir][0];
    int ay = sy + ALPHA_OFF[dir][1];
    if (isIn(ax, ay)) board[ax][ay] += remaining;
    else result += remaining;

    // 현재 칸은 모래가 모두 이동
    board[cx][cy] = 0;
  }

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;

    N = Integer.parseInt(br.readLine());
    board = new int[N + 1][N + 1];

    for (int i = 1; i <= N; i++) {
      st = new StringTokenizer(br.readLine());
      for (int j = 1; j <= N; j++) {
        board[i][j] = Integer.parseInt(st.nextToken());
      }
    }

    // 시작: 가운데(1-based)
    cx = cy = N / 2 + 1;

    // 원래 로직 유지(나선 이동 + 마지막 구간 보정)
    int cnt = 1;
    while (cnt <= N) {
      if (cnt == N) {
        // 마지막은 왼쪽으로 cnt-1번만 이동
        for (int i = 0; i < cnt - 1; i++) {
          cx += dx[0]; cy += dy[0];
          distribute(0);
        }
        break; // 끝
      }

      if ((cnt & 1) == 1) {
        // 홀수: 왼쪽 cnt, 아래 cnt
        for (int i = 0; i < cnt; i++) { cx += dx[0]; cy += dy[0]; distribute(0); }
        for (int i = 0; i < cnt; i++) { cx += dx[1]; cy += dy[1]; distribute(1); }
      } else {
        // 짝수: 오른쪽 cnt, 위 cnt
        for (int i = 0; i < cnt; i++) { cx += dx[2]; cy += dy[2]; distribute(2); }
        for (int i = 0; i < cnt; i++) { cx += dx[3]; cy += dy[3]; distribute(3); }
      }
      cnt++;
    }

    System.out.println(result);
  }
}
