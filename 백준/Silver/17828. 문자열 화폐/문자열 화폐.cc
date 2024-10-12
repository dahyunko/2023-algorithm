/*17828*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

typedef long long ll;

int main() {
	ll N, X;
	cin >> N >> X;

	if (X > N * 26 || X < N) {
		cout << "!";
		return 0;
	}

	vector<ll>str(N, 1);

	ll total = N;
	for (int i = N - 1; i >= 0; i--) {
		total -= str[i];
		if (total + 26 <= X) str[i] = 26;
		else str[i] = X - total;
		
		total += str[i];

		if (total == X) {
			for (int j = 0; j < N; j++) {
				char c = 'A' + str[j] - 1;
				cout << c;
				//cout << "[" <<str[j] <<", " << c << "] ";
			}
			return 0;
		}
	}

	cout << "!";
	return 0;
}