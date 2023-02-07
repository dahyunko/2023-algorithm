/*2775- 부녀회장이 될테야*/
#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

int A[15][15] = { 0 };

int main() {
	int T;

	cin >> T;

	for (int i = 0; i < 15; i++) {
		A[i][0] = 0;
		A[0][i] = i;
	}

	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			A[i][j] = A[i][j - 1] + A[i - 1][j];
		}
	}

	for (int i = 0; i < T; i++) {
		int k, n;//k층 n호

		cin >> k >> n;
		cout << A[k][n] << '\n';
	}
}