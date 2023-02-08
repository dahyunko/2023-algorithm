/*1947*/
#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

static long mod = 1000000000;

int main() {
	int N;
	cin >> N;

	vector<long> A(N + 1, 0);
	A[1] = 0;
	A[2] = 1;
	for (int i = 3; i <= N; i++) {
		A[i] = (i - 1) * (A[i - 1] + A[i - 2]) % mod;
	}

	cout << A[N];
}