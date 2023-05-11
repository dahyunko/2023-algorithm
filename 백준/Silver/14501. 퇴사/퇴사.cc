/*14501*/
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
	int N;
	cin >> N;

	vector<int>d(N + 2, 0);
	vector<int> T(N+1);
	vector<int> P(N+1);

	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}

	for (int i = N; i > 0; i--) {
		if (i + T[i] - 1 > N) { 
			d[i] = d[i + 1];
			continue; 
		}

		d[i] = max(d[i + T[i]] + P[i], d[i + 1]);
	}

	cout << d[1];
}