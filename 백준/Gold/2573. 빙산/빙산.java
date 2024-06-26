import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static int board[][] = new int[301][301];
    static int[] a = {1, -1, 0, 0};
    static int[] b = {0, 0, 1, -1};

    static class Info{
        int x, y;

        Info(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
    static boolean check(int x, int y){
        return (x>= 0 && x<N && y >= 0 && y < M);
    }

    static void meltIce(int [][] tempBoard){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(board[i][j] == 0) continue;
                for(int t=0;t<4;t++){
                    int xx = i + a[t];
                    int yy = j + b[t];

                    if(check(xx, yy) && board[xx][yy] == 0 ){
                        tempBoard[i][j]++;
                    }
                }
            }
        }

        // 얼음 녹이기
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(board[i][j] <= tempBoard[i][j]){
                    board[i][j] = 0;
                }
                else {
                    board[i][j] -= tempBoard[i][j];
                }
            }
        }
    }

    static void bfs(boolean visited[][], int x, int y){
        Deque<Info> q = new ArrayDeque<>();
        q.add(new Info(x, y));

        while(!q.isEmpty()){
            Info v = q.poll();

            if(visited[v.x][v.y]) continue;
            visited[v.x][v.y] = true;

            for(int i=0;i<4;i++){
                int xx = v.x + a[i];
                int yy = v.y + b[i];

                if(check(xx, yy) && board[xx][yy] > 0 && !visited[xx][yy]){
                    q.add(new Info(xx, yy));
                }
            }
        }
    }
    static int searchPlace(){
        int place = 0;

        boolean[][] visited = new boolean[N+1][M+1];

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(board[i][j] == 0 || visited[i][j]) continue;

                bfs(visited, i, j);
                place++;
            }
        }

        return place;
    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for(int i=0;i<N;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<M;j++){
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int day = 0;
        while(true){
            day++;
            int[][] tempBoard = new int[N+1][M+1];
            meltIce(tempBoard);

            // 구역 확인
            int temp = searchPlace();
            if(temp >= 2) {
                System.out.println(day);
                break;
            }
            if(temp == 0){
                System.out.println(0);
                break;
            }
        }
    }
}