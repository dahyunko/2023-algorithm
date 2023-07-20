/*16234*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

struct info {
	int x;
	int y;
};

int board[51][51];
int a[4] = { 1, -1, 0 ,0 };
int b[4] = { 0, 0, 1, -1 };

int main() {
	int N, L, R;
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> board[i][j];
	}

	int flag = 0, cnt = 0;
	while (true) {
		if (flag == N * N) { 
			cnt--;
			break; 
		}
		flag = 0;

		bool visited[51][51] = { false };
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j]) continue;
				//국경선 공유 지역 찾기
				queue<info>site;
				queue<info>q;
				int sum = 0;
				q.push({ i,j });
				while (!q.empty()) {
					info v = q.front();
					q.pop();

					if (visited[v.x][v.y]) continue;
					visited[v.x][v.y] = true;
					site.push({ v });
					sum += board[v.x][v.y];
					
					for (int t = 0; t < 4; t++) {
						if (v.x + a[t] >= 0 && v.x + a[t] < N && v.y + b[t] >= 0 && v.y + b[t] < N) {
							int temp = abs(board[v.x][v.y] - board[v.x + a[t]][v.y + b[t]]);
							if (temp >= L && temp <= R) {
								q.push({ v.x + a[t], v.y + b[t] });
							}
						}
					}
				}

				if (site.size() == 1) {
					flag++;
					continue;
				}
				//국경선 열기, 이동
				int temp = sum / site.size();
				while (!site.empty()) {
					info v = site.front();
					site.pop();

					board[v.x][v.y] = temp;
				}
			}
		}
		cnt++;
	}

	cout << cnt;
}