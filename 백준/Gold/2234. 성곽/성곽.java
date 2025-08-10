import java.io.*;
import java.util.*;

public class Main {
  static int N, M, roomCnt = 0;
  static int[][][] wallInfo = new int[51][51][4];
  static int[][] roomInfo = new int[51][51];
  static int[] room = new int[2501];

  // 서1, 북2, 동4, 남8
  static int[] a = {0, -1, 0, 1};
  static int[] b = {-1, 0, 1, 0};

  // 벽 설치
  static void installWall(int x, int y, int num){
    int temp = 8;
    int a = 3;

    while(num > 0){
      if(num >= temp){
        num -= temp;
        wallInfo[x][y][a] = 1;
      }
      else { wallInfo[x][y][a] = 0;}
            
      temp /= 2;
      a--;
    }
  }

  static boolean isIn(int x, int y){
    return (x>=0 && x<M && y>=0 && y<N);
  }

  static class Pair{
    int x, y;
    Pair(int x, int y){
      this.x = x;
      this.y = y;
    }
  }

  static int searchRoom(int x, int y){
    int size = 0;

    Queue<Pair> q = new LinkedList<>();
    q.add(new Pair(x, y));

    while(!q.isEmpty()){
      Pair v = q.poll();

      if(roomInfo[v.x][v.y] != -1) continue;
      roomInfo[v.x][v.y] = roomCnt;
      size++;

      for(int t=0;t<4;t++){
        int xx = v.x + a[t];
        int yy = v.y + b[t];

        if(isIn(xx, yy) && wallInfo[v.x][v.y][t] == 0 && roomInfo[xx][yy] == -1){
          q.add(new Pair(xx, yy));
        }
      }
    }

    return size;
  }

  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    StringBuilder sb = new StringBuilder();

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    for(int i=0;i<M;i++){
      st = new StringTokenizer(br.readLine());

      for(int j=0;j<N;j++){
        int now = Integer.parseInt(st.nextToken());
        installWall(i, j , now);
        roomInfo[i][j] = -1;
      }
    }

    // find room
    for(int i=0;i<M;i++){
      for(int j=0;j<N;j++){
        if(roomInfo[i][j] > -1) continue;
        roomCnt++;
        room[roomCnt] = searchRoom(i, j);
      }
    }

    sb.append(roomCnt);
    sb.append("\n");
    
    // find max room
    int maxRoom = 0;
    for(int i=1;i<=roomCnt;i++){
      maxRoom = Math.max(maxRoom, room[i]);
    }
    sb.append(maxRoom);
    sb.append("\n");

    // uninstall wall
    Set<String> set = new HashSet<>();
    int result = 0;
    for(int i=0;i<M;i++){
      for(int j=0;j<N;j++){
        for(int t =0;t<4;t++){
          int xx = i + a[t];
          int yy = j + b[t];

          if(isIn(xx, yy) && roomInfo[xx][yy] != roomInfo[i][j]){
            result = Math.max(room[roomInfo[xx][yy]] + room[roomInfo[i][j]], result);
          }
        }
      }
      
    }
    sb.append(result);

    System.out.println(sb.toString());
  }  
}
