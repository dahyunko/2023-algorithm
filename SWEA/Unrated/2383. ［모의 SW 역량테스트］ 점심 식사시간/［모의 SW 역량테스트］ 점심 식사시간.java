import java.io.*;
import java.util.*;

public class Solution {
	static int T, N, result, pSize;
	static List<Pair> person = new ArrayList<>();
	static List<Info> stairs = new ArrayList<>();
	static int list[] = new int[11];
	static List<Info> pStair1 = new ArrayList<>();
	static List<Info> pStair2 = new ArrayList<>();
	static Deque<Integer> deque = new ArrayDeque<>();

	static class Info implements Comparable<Info> {
		int x, y, s;

		Info(int x, int y, int s) {
			this.x = x;
			this.y = y;
			this.s = s;
		}

		@Override
		public int compareTo(Info o) {
			return this.s - o.s;
		}

		@Override
		public String toString() {
			return "[" + x + ", " + y + ", " + s + "]";
		}
	}

	static class Pair {
		int x, y;

		Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static int calDistance(int p, int s) {
		return Math.abs(person.get(p).x - stairs.get(s).x) + Math.abs(person.get(p).y - stairs.get(s).y);
	}

	static int calTime(List<Info> pStair, Info stair) {
		deque.clear();

		Collections.sort(pStair); // 오름차순
//		System.out.println(pStair.toString());
		// 시간 계산
		int idx = 0;
		int time = 0;

		while (true) {
			if (idx == pStair.size()) {
				break;
			}

			// 시간 지난 것 빼기
			while (!deque.isEmpty()) {
				if (deque.peek() <= time) {
					deque.poll();
				} else {
					break;
				}
			}

			// 계단 투입
			while (deque.size() < 3 && idx < pStair.size()) {
				int now = pStair.get(idx).s;
				if (now + 1 <= time) {
					deque.add(time + stair.s);
					idx++;
				} else
					break;
			}
			time++;
		}

		while (!deque.isEmpty()) {
			time = Math.max(time, deque.poll());
		}

		return time;
	}

	static void backTracking(int cnt, int c, int j) {
		if (cnt == c) {
			int temp = 0;

			// 계단에 들어가는 사람 분할
			pStair1.clear();
			pStair2.clear();
			boolean[] visited = new boolean[pSize];
			for (int i = 0; i < c; i++) {
				visited[list[i]] = true;
				pStair1.add(new Info(person.get(list[i]).x, person.get(list[i]).y, calDistance(list[i], 0)));
			}
			if (pStair1.size() != 0) {
				temp = calTime(pStair1, stairs.get(0));
			}

			for (int i = 0; i < pSize; i++) {
				if (visited[i])
					continue;
				pStair2.add(new Info(person.get(i).x, person.get(i).y, calDistance(i, 1)));
			}

			if (pStair2.size() != 0) {
				temp = Math.max(temp, calTime(pStair2, stairs.get(1)));
			}

			result = Math.min(temp, result);
			return;
		}

		for (int i = j; i < pSize; i++) {
			list[cnt] = i;// nCr :
			backTracking(cnt + 1, c, i + 1);
		}

	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;

		T = Integer.parseInt(br.readLine());

		for (int t = 1; t <= T; t++) {
			sb.append("#").append(t).append(" ");
			N = Integer.parseInt(br.readLine());
			person.clear();
			stairs.clear();
			pSize = 0;

			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < N; j++) {
					int now = Integer.parseInt(st.nextToken());
					if (now == 1) {
						person.add(new Pair(i, j));
					} else if (now >= 2) {
						stairs.add(new Info(i, j, now));
					}
				}
			}

			// 모든 경우의 수
			pSize = person.size();
			result = Integer.MAX_VALUE;
			for (int i = 0; i <= pSize; i++) { // [0, pSize] [1,N-1] ... [pSize, 0]
				backTracking(0, i, 0);
			}

			sb.append(result).append("\n");
		}
		System.out.println(sb);
	}
}
