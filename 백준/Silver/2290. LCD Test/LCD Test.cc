/*LCD Test- 2290*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main() {
	int s;
	string n;

	cin >> s >> n;
	int m = (s + 3) * n.length();
	vector<vector<char>>mon(2 * s + 3, vector<char>(m));
	
	int t = 0;
	for (int i = 0; i < n.length(); i++) {
		switch (n[i]) {
		case '0':
			//가로
			for (int j = t + 1; j < t + s+1; j++) {
				mon[0][j] = '-';
				mon[2 * s + 2][j] = '-';
			}
			//세로
			for (int j = 1; j < 2*s + 2; j++) {
				if (j == s+1) continue;
				mon[j][t] = '|';
				mon[j][t + s + 1] = '|';
			}
			break;
		case '1':
			//세로
			for (int j = 1; j < 2 * s + 2; j++) {
				if (j == s + 1) continue;
				mon[j][t + s + 1] = '|';
			}
			break;
		case '2':
			//가로
			for (int j = t + 1; j < t + s + 1; j++) {
				mon[0][j] = '-';
				mon[s + 1][j] = '-';
				mon[2 * s + 2][j] = '-';
			}
			//세로
			for (int j = 1; j < 2 * s + 2; j++) {
				if (j == s + 1) continue;
				if (j <= s) mon[j][t + s + 1] = '|';
				if (j > s + 1)mon[j][t] = '|';
			}
			break;
		case '3':
			//가로
			for (int j = t + 1; j < t + s + 1; j++) {
				mon[0][j] = '-';
				mon[s + 1][j] = '-';
				mon[2 * s + 2][j] = '-';
			}
			//세로
			for (int j = 1; j < 2 * s + 2; j++) {
				if (j == s + 1) continue;
				mon[j][t + s + 1] = '|';
			}
			break;
		case '4':
			//가로
			for (int j = t + 1; j < t + s + 1; j++) {
				mon[s + 1][j] = '-';
			}
			//세로
			for (int j = 1; j < 2 * s + 2; j++) {
				if (j == s + 1) continue;
				if (j <= s) mon[j][t] = '|';
				mon[j][t + s + 1] = '|';
			}
			break;
		case '5':
			//가로
			for (int j = t + 1; j < t + s + 1; j++) {
				mon[0][j] = '-';
				mon[s + 1][j] = '-';
				mon[2 * s + 2][j] = '-';
			}
			//세로
			for (int j = 1; j < 2 * s + 2; j++) {
				if (j == s + 1) continue;
				if (j <= s) mon[j][t] = '|';
				if (j > s + 1) mon[j][t + s + 1] = '|';
			}
			break;
		case '6':
			//가로
			for (int j = t + 1; j < t + s + 1; j++) {
				mon[0][j] = '-';
				mon[s + 1][j] = '-';
				mon[2 * s + 2][j] = '-';
			}
			//세로
			for (int j = 1; j < 2 * s + 2; j++) {
				if (j == s + 1) continue;
				if (j <= s) mon[j][t] = '|';
				if (j > s + 1) {
					mon[j][t] = '|';
					mon[j][t + s + 1] = '|';
				}
			}
			break;
		case '7':
			//가로
			for (int j = t + 1; j < t + s + 1; j++) {
				mon[0][j] = '-';
			}
			//세로
			for (int j = 1; j < 2 * s + 2; j++) {
				if (j == s + 1) continue;
				mon[j][t + s + 1] = '|';
			}
			break;
		case '8':
			//가로
			for (int j = t + 1; j < t + s + 1; j++) {
				mon[0][j] = '-';
				mon[s + 1][j] = '-';
				mon[2 * s + 2][j] = '-';
			}
			//세로
			for (int j = 1; j < 2 * s + 2; j++) {
				if (j == s + 1) continue;
				mon[j][t] = '|';
				mon[j][t + s + 1] = '|';
			}
			break;
		case '9':
			//가로
			for (int j = t + 1; j < t + s + 1; j++) {
				mon[0][j] = '-';
				mon[s + 1][j] = '-';
				mon[2 * s + 2][j] = '-';
			}
			//세로
			for (int j = 1; j < 2 * s + 2; j++) {
				if (j == s + 1) continue;
				if (j <= s) mon[j][t] = '|';
				mon[j][t + s + 1] = '|';
			}
			break;
		default: break;
		}
		t += s + 3;
	}
	// mon(2 * s + 3, vector<char>(m));
	for (int i = 0; i < 2 * s + 3; i++) {
		for (int j = 0; j < m; j++) {
			if (!mon[i][j]) cout << ' ';
			else cout << mon[i][j];
		}
		cout << '\n';
	}
}