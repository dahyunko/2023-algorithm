/*빗물- 14719*/
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

int main() {
	int H, W;

	cin >> H >> W;

	vector<int>A(W);
	vector<vector<int>>S(H, vector<int>(W, 0));
	for (int i = 0; i < W; i++)cin >> A[i];

	for (int i = 0; i < W; i++) {
		int temp = 1;
		for (int j = H - 1; j >= 0; j--) {
			if (temp++ <= A[i]) S[j][i] = 1;
			else break;
		}
	}

	//빗물 탐색
	int ans = 0;
	for (int i = 0; i < H; i++) {
		int start = -1;
		for (int j = 0; j < W; j++) {
			if (S[i][j] == 1) {
				if (start == -1) start = j;
				else if (start < j) {
					ans += j - start - 1;
					start = j;
				}
			}
		}
	}

	cout << ans;
}