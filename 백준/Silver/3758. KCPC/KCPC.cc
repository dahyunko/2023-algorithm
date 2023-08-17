/*3758*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
#include <cmath>
#include<limits.h>
#include<set>
#include<map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n, k, Team_ID, m;
		cin >> n >> k >> Team_ID >> m;

		vector<vector<int>>A(n + 1, vector<int>(3, 0));//합계, 제출 횟수, 마지막 제출 시간
		vector<vector<int>>problem(n+1, vector<int>(k+1, 0));

		//로그 출력
		for (int i = 0; i < m; i++) {
			int ID, j, s;
			cin >> ID >> j >> s;

			A[ID][2] = i;
			A[ID][1]++;
			if (problem[ID][j] < s) {
				A[ID][0] += (s- problem[ID][j]);
				problem[ID][j] = s;
			}
		}

		//Team 등수 찾기
		int cnt = 1;
		for (int i = 1; i <= n; i++) {
			if (Team_ID == i) continue;
			if (A[Team_ID][0] > A[i][0]) continue;

			if (A[Team_ID][0] == A[i][0]) {
				if (A[Team_ID][1] > A[i][1]) cnt++;
				else if (A[Team_ID][1] == A[i][1]) {
					if (A[Team_ID][2] > A[i][2]) cnt++;
				}
			}
			else cnt++;
		}
		cout << cnt << '\n';
	}
}