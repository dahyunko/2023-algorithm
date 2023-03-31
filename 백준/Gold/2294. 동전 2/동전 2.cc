/*동전 2*/
#include<limits.h>
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

int main() {
	int n, k;

	cin >> n >> k;

	vector<int> A;
	vector<int> d(k + 1, INT_MAX);

	for (int i = 0; i < n; i++) { 
		int now;
		cin >> now;
		if (now > k) continue;
		A.push_back(now);
	}

	sort(A.begin(), A.end());

	d[0] = 0;
	for (int i = 0; i < A.size(); i++) {
		for (int j = A[i]; j <= k; j++) {
            if (d[j - A[i]] == INT_MAX) continue;
			if (d[j] == INT_MAX) {
				d[j] = d[j - A[i]] + 1;
			}
			else if (d[j] > d[j - A[i]] + 1) {
				d[j] = d[j - A[i]] + 1;
			}
		}
	}

	if (d[k] == INT_MAX) cout << -1;
	else cout << d[k];
}