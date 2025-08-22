import java.io.*;
import java.util.*;

public class Main {
  static int N, sharkSize = 2, time = 0, eatCnt = 0;
  static int[][] board;
  static INFO shark;
  static List<INFO>[] sharkList = new ArrayList[7];
  static int[] a = {0, 0, 1, -1};
  static int[] b = {1, -1, 0, 0};

  static class INFO{
    int x, y;

    INFO(){}
    INFO(int x, int y){
      this.x = x;
      this.y = y;
    }
  }

  static boolean isIn(int x, int y){
    return (x>=0 && x<N && y>=0 && y<N);
  }

  static int bfs(int x, int y){
    int[][] timeBoard = new int[N][N];

    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++) timeBoard[i][j] = Integer.MAX_VALUE;
    }

    Queue<int[]> q = new LinkedList<>();
    q.add(new int[]{shark.x, shark.y, 0});

    while(!q.isEmpty()){
      int[] v = q.poll();

      if(timeBoard[v[0]][v[1]] <= v[2]) continue;
      timeBoard[v[0]][v[1]] = v[2];

      if(v[0] == x && v[1] == y){
        continue;
      }

      for(int t=0;t<4;t++){
        int xx = v[0] + a[t];
        int yy = v[1] + b[t];
        
        if(isIn(xx, yy) && board[xx][yy] <= sharkSize){
          q.add(new int[]{xx, yy, v[2] + 1});
        }
      }
    }

    return timeBoard[x][y];
  }

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;

    N = Integer.parseInt(br.readLine());
    board = new int[N][N];

    // init
    for(int i=0;i<7;i++){
      sharkList[i] = new ArrayList<>();
    }

    for(int i=0;i<N;i++){
      st = new StringTokenizer(br.readLine());

      for(int j=0;j<N;j++){
        board[i][j] = Integer.parseInt(st.nextToken());
        if(board[i][j] == 0) continue;
        else if(board[i][j] == 9){ 
          shark = new INFO(i, j); 
          board[i][j] = 0;
        }
        else { sharkList[board[i][j]].add(new INFO(i, j)); }
      }
    }

    // 상어 잡아 먹기
    while(true){

      // 먹을 수 있는 상어
      INFO eatShark = new INFO(-1, -1);
      int eatSharkTime = Integer.MAX_VALUE;
      for(int i=1;i<(sharkSize > 6 ? 7 : sharkSize);i++){
        for(int j = 0;j<sharkList[i].size();j++){
          int xx = sharkList[i].get(j).x;
          int yy = sharkList[i].get(j).y;
          
          if(board[xx][yy] == -1) continue;
          int reachTime = bfs(xx, yy);

          // 도달할 수 없음
          if(reachTime == Integer.MAX_VALUE) continue;

          if(eatSharkTime < reachTime) continue;
          if(eatSharkTime == reachTime){
            // 위쪽, 왼쪽
            if(eatShark.x > xx){  
              eatShark.x = xx;
              eatShark.y = yy;
            }
            else if( eatShark.x == xx && eatShark.y > yy){
              eatShark.x = xx;
              eatShark.y = yy;
            }
          }
          else {
            eatShark.x = xx;
            eatShark.y = yy;
            eatSharkTime = reachTime;
          }
        }
      }

      // 상어 못 먹음
      if(eatShark.x == -1 && eatShark.y == -1){ break; }

      // 먹은 상어 갯수, 위치 갱신
      eatCnt++;
      time += eatSharkTime;
      shark.x = eatShark.x;
      shark.y = eatShark.y;
      board[shark.x][shark.y] = -1;
      
      // 상어 사이즈 갱신
      if(eatCnt == sharkSize){
        sharkSize++;
        eatCnt = 0;
      }
    }

    System.out.println(time);
  }
}