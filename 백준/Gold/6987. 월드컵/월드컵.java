import java.io.*;
import java.util.*;
import java.lang.*;

public class Main {
	static int result;
	static int[] A = { 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 5 };
	static int[] B = { 2, 3, 4, 5, 6, 3, 4, 5, 6, 4, 5, 6, 5, 6, 6 };
	static int[][][] list = new int[4][7][3];
	static int[] ans = { 0, 0, 0, 0 };

	static int[] win = new int[7];
	static int[] draw = new int[7];
	static int[] lose = new int[7];

	static void makeGame(int cnt) {
		if (cnt == 15) {
			for (int i = 0; i < 4; i++) {
				int temp = 0;
				for (int j = 1; j <= 6; j++) {
					if (list[i][j][0] == win[j] && list[i][j][1] == draw[j] && list[i][j][2] == lose[j]) {
						temp++;
					} else
						break;
				}
				
				if(temp == 6) {
					ans[i] = 1;
				}
			}

			return;
		}

		// 이기고
		win[A[cnt]]++;
		lose[B[cnt]]++;
		makeGame(cnt + 1);
		win[A[cnt]]--;
		lose[B[cnt]]--;

		// 지고
		win[B[cnt]]++;
		lose[A[cnt]]++;
		makeGame(cnt + 1);
		win[B[cnt]]--;
		lose[A[cnt]]--;

		// 비기고
		draw[A[cnt]]++;
		draw[B[cnt]]++;
		makeGame(cnt + 1);
		draw[A[cnt]]--;
		draw[B[cnt]]--;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;

//		printStrs();
		for (int i = 0; i < 4; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j < 7; j++) {
				list[i][j][0] = Integer.parseInt(st.nextToken());
				list[i][j][1] = Integer.parseInt(st.nextToken());
				list[i][j][2] = Integer.parseInt(st.nextToken());
			}
		}

		makeGame(0);
		for (int i = 0; i < 4; i++) {
			sb.append(ans[i]).append(" ");
		}
		System.out.println(sb);
	}
}