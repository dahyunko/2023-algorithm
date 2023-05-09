/*2775*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<tuple>
#include<limits.h>

using namespace std;

int main() {
	int A[15][15] = { 0 };

	for (int i = 0; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			if (i == 0) A[i][j] = j;
			else A[i][j] = A[i - 1][j] + A[i][j-1];
		}
	}

	int T;
	cin >> T;
	for (int i = 0; i < T; i++){
		int k, n;
		cin >> k >> n;

		cout << A[k][n] << '\n';
	}
}