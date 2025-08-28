import java.io.*;
import java.util.*;

public class Main {
  static int N, M;
  static int[][] board = new int[501][501];
  
  static int numOneTwoBlock(int x, int y){
    int temp1 = 0;
    // 직선 가로 4개
    for(int i=0;i<4;i++){
      if(!isIn(x, y+i)){
        temp1 = 0;
        break;
      }
      temp1 += board[x][y + i];
    }
    
    // 직선 세로 4개
    int temp2 = 0;
    for(int i=0;i<4;i++){
      if(!isIn(x+i, y)){
        temp2 = 0;
        break;
      }
      temp2 += board[x+i][y];
    }

    // 정사각형 4개
    int temp3 = 0;
    for(int i=0;i<2;i++){
      for(int j=0;j<2;j++){
        if(!isIn(x+i, y+j)){
        temp3 = 0;
        break;
      }
      temp3 += board[x+i][y+j];
      }
    }
    return Math.max(Math.max(temp1, temp2), temp3);
  }

  static int numThreeFourFiveBlock(int x, int y){
    // 직사각형 6개 가로
    int total1 = 0, result = 0;
    for(int i=0;i<2;i++){
      for(int j=0;j<3;j++){
        if(!isIn(x+i, y+j)){
          total1 = 0;
          break;
        }

        total1 += board[x+i][y+j];
      }
    }

    // 구멍 뚫기 가로
    int[][] blank1 = {
      {0, 0, 0, 1}, // 3
      {1, 0, 1, 1}, // 3
      {0, 1, 0, 2}, // 3
      {1, 1, 1, 2}, // 3
      {0, 0, 1, 2}, // 4
      {1, 0, 0, 2}, // 4
      {1, 0, 1, 2}, // 5
      {0, 0, 0, 2}, // 5
    };

    if(total1 > 0){
      for(int t=0;t<8;t++){
        int temp = total1 - board[x+ blank1[t][0]][y+ blank1[t][1]] - board[x+ blank1[t][2]][y+ blank1[t][3]];
        result = Math.max(result, temp);
      }
    }
      
    // 직사각형 6개 세로
    int total2 = 0;
    for(int i=0;i<3;i++){
      for(int j=0;j<2;j++){
        if(!isIn(x+i, y+j)){
          total2 = 0;
          break;
        }

        total2 += board[x+i][y+j];
      }
    }

    // 구멍 뚫기 세로
    int[][] blank2 = {
      {0, 0, 1, 0}, // 3
      {0, 1, 1, 1}, // 3
      {1, 0, 2, 0}, // 3
      {1, 1, 2, 1}, // 3
      {0, 0, 2, 1}, // 4
      {0, 1, 2, 0}, // 4
      {0, 1, 2, 1}, // 5
      {0, 0, 2, 0}, // 5
    };

    if(total2 > 0){
      for(int t=0;t<8;t++){
        int temp = total2 - board[x+ blank2[t][0]][y+ blank2[t][1]] - board[x+ blank2[t][2]][y+ blank2[t][3]];
        result = Math.max(result, temp);
      }
    }

    return result;
  }

  static boolean isIn(int x, int y){
    return (x>=0 && x<N && y>=0 && y<M);
  }

  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    // init
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    for(int i=0;i<N;i++){
      st = new StringTokenizer(br.readLine());
      for(int j=0;j<M;j++){
        board[i][j] = Integer.parseInt(st.nextToken());
      }
    }    

    // find
    int result = 0;
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        // 1, 2번 블록
        result = Math.max(numOneTwoBlock(i,j), result);

        // 3, 4, 5번 블록
        result = Math.max(numThreeFourFiveBlock(i,j), result);
      }
    }

    System.out.println(result);
  }  
}
