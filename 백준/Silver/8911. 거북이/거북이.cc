/*거북이- 8911*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main() {
	int N;

	cin >> N;
	vector<string>A(N);
	for (int i = 0; i < N; i++) cin >> A[i];

	for (int i = 0; i < N; i++) {
		int m = A[i].length();
		//vector<vector<int>>graph(m * 2 + 1, vector<int>(m * 2 + 1, 0));

		int move[2] = { 0,0 };
		int v1[2] = { 0,0 };
		int v2[2] = { 0,0 };
		
		char flag = 1;
		for (int j = 0; j < m; j++) {
			if (A[i][j] == 'F') {
				if (flag == 1) move[1]++;
				else if (flag == 2) move[0]++;
				else if (flag == 3) move[1]--;
				else if (flag == 4) move[0]--;
			}
			else if (A[i][j] == 'B') {
				if (flag == 1) move[1]--;
				else if(flag == 2) move[0]--;
				else if(flag == 3) move[1]++;
				else if (flag == 4) move[0]++;
			}
			else if (A[i][j] == 'L') {
				if (flag == 1) flag = 4;
				else if (flag == 2) flag = 1;
				else if (flag == 3) flag = 2;
				else if (flag == 4) flag = 3;
			}
			else if (A[i][j] == 'R') {
				if (flag == 1) flag = 2;
				else if (flag == 2) flag = 3;
				else if (flag == 3) flag = 4;
				else if (flag == 4) flag = 1;
			}

			v1[0] = min(v1[0], move[0]);
			v2[0] = max(v2[0], move[0]);
			v1[1] = min(v1[1], move[1]);
			v2[1] = max(v2[1], move[1]);
		}

		int sum = (v2[0] - v1[0]) * (v2[1] - v1[1]);
		if (sum < 0) sum *= -1;

		cout << sum << '\n';
	}
}