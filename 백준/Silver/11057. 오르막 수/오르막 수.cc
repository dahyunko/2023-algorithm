/*11057*/
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

static int mod = 10007;

int main() {
	int N;

	cin >> N;

	vector<vector<long>> A(N + 1, vector<long>(10, 0));

	for (int i = 0; i < 10; i++) A[0][i] = 1;

	for (int i = 1; i <= N; i++) {
		A[i][0] = A[i - 1][0];
		for (int j = 1; j < 10; j++) {
			A[i][j] = (A[i][j - 1] + A[i - 1][j]) % mod;
		}
	}

	cout << A[N][9];
}