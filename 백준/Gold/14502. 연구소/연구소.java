import java.io.*;
import java.util.*;
import java.lang.*;

public class Main {
	static int N, M, result;
	static int board[][] = new int[9][9];
	static List<Pair> holes = new ArrayList<>();
	static int[] list = new int[3];
	static boolean[] visited = new boolean[65];
	static Deque<Pair> deque = new LinkedList<>();

	static int A[] = { 0, 0, 1, -1 };
	static int B[] = { 1, -1, 0, 0 };

	static class Pair {
		int x, y;

		Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static boolean check(int x, int y) {
		if (x >= 0 && x < N && y >= 0 && y < M)
			return true;
		return false;
	}

	static void bfs(int x, int y, boolean[][] visited) {
		deque.clear();

		int xx, yy;
		deque.add(new Pair(x, y));
		while (!deque.isEmpty()) {
			Pair v = deque.poll();

			if (visited[v.x][v.y])
				continue;
			visited[v.x][v.y] = true;

			for (int i = 0; i < 4; i++) {
				xx = v.x + A[i];
				yy = v.y + B[i];

				if (check(xx, yy) && !visited[xx][yy] && board[xx][yy] != 1) {
					deque.add(new Pair(xx, yy));
				}
			}
		}
	}

	static int findPure() {
		int temp = 0;
		for (int i = 0; i < 3; i++) {
			Pair now = holes.get(list[i]);
			board[now.x][now.y] = 1;
//			System.out.print("[" + now.x + " ," + now.y + "] ");
		}
//		System.out.println();

		boolean[][] visited = new boolean[N][M];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] == 2 && !visited[i][j]) {
					bfs(i, j, visited);
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] == 0 && !visited[i][j]) {
					temp++;
				}

//				System.out.print("[" + visited[i][j] + ", " + board[i][j] + "] ");
			}
//			System.out.println();
		}

		for (int i = 0; i < 3; i++) {
			Pair now = holes.get(list[i]);
			board[now.x][now.y] = 0;
		}

//		System.out.println(temp);
		result = Math.max(result, temp);
		return 0;
	}

	static void backtracking(int cnt, int j) {
		if (cnt == 3) {
			findPure();
			return;
		}

		for (int i = j; i < holes.size(); i++) {
			list[cnt] = i;
			backtracking(cnt + 1, i + 1);
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());

				if (board[i][j] == 0) {
					holes.add(new Pair(i, j));
				}
			}
		}

//		System.out.println(holes.size());
		result = 0;
		backtracking(0, 0);
		System.out.println(result);
	}
}