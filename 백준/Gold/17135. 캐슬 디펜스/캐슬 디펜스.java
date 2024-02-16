import java.io.*;
import java.util.*;
import java.lang.*;

public class Main {
	static int N, M, D, result = 0, deleteCnt;
	static List<Info> enemys = new LinkedList<>();
	static List<Info> enemysClone = new LinkedList<>();
	static Info[] archers = new Info[3];

	static class Info {
		int x, y;

		Info(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public String toString() {
			return "[" + x + ", " + y + "]";
		}
	}

	static boolean startWar() {
		int disTemp, enemyNum;
		List<Integer> deleteEnemys = new LinkedList<>(); // 삭제 적군 저장

		// 적군 확인
		for (int i = 0; i < 3; i++) {
			disTemp = 1000;
			enemyNum = -1;
			for (int j = 0; j < enemysClone.size(); j++) {
				// 거리 계산
				int temp = Math.abs(archers[i].x - enemysClone.get(j).x)
						+ Math.abs(archers[i].y - enemysClone.get(j).y);
				if (temp > D)
					continue;

				if (disTemp < temp)
					continue;
				else if (disTemp == temp) {// 거리가 같을 시
					if (enemysClone.get(enemyNum).y > enemysClone.get(j).y) { // 현재 적군이 왼쪽에 존재할 시
						enemyNum = j;
					}
				} else if (disTemp > temp) {
					disTemp = temp;
					enemyNum = j;
				}
			}
			if (enemyNum == -1)
				continue;
			deleteEnemys.add(enemyNum);
		}

		// 적군 삭제
		for (int i = 0; i < deleteEnemys.size(); i++) {
//			System.out.print(enemysClone.get(deleteEnemys.get(i)));
			enemysClone.get(deleteEnemys.get(i)).x = -1;
			enemysClone.get(deleteEnemys.get(i)).y = -1;
		}
//		System.out.println();

		for (int i = enemysClone.size() - 1; i >= 0; i--) {
			if (enemysClone.get(i).x == -1 && enemysClone.get(i).y == -1) { // 지우는 거
				enemysClone.remove(i);
				deleteCnt++;
			}else {
				if (++enemysClone.get(i).x >= N) { // 성 진입, 삭제
					enemysClone.remove(i);
				}
			}
		}

//		// 적군 이동
//		for (int i = enemysClone.size() - 1; i >= 0; i--) {
//			if (++enemysClone.get(i).x >= N) { // 성 진입, 삭제
//				enemysClone.remove(i);
//			}
//		}

		if (enemysClone.isEmpty())
			return true;
		return false;
	}

	static void makeEnemys() {
		for (int i = 0; i < enemys.size(); i++) {
			int x = enemys.get(i).x;
			int y = enemys.get(i).y;
			enemysClone.add(new Info(x, y));
		}
	}

	static void printArchers() {
		for(int i=0;i<3;i++) {
			System.out.print(archers[i] + " ");
		}
		System.out.println();
	}
	static void makeArchers(int cnt, int j) {
		if (cnt == 3) {
			// 궁수 설정 완료
//			printArchers();
			makeEnemys();
			deleteCnt = 0;
			while (!startWar())
				;
//			System.out.println("deleteNum : " + deleteCnt);
			result = Math.max(result, deleteCnt);
			return;
		}

		for (int i = j; i < M; i++) {
			archers[cnt] = new Info(N, i);
			makeArchers(cnt + 1, i + 1);
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				if (st.nextToken().equals("0"))
					continue;
				// 적군 저장
				enemys.add(new Info(i, j));
			}
		}

		// 궁수 생성
		makeArchers(0, 0);
		System.out.println(result);
	}
}