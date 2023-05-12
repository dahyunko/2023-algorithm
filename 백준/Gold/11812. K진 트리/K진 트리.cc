/*11812*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<tuple>
#include<limits.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll N, K, Q;
	cin >> N >> K >> Q;

	for (int i = 0; i < Q; i++) {
		ll a, b;
		cin >> a >> b;
		if (K == 1) {
			cout << abs(a - b) << '\n';
			continue;
		}

		int cnt = 0;
		while (a != b) {
			while (a > b) {
				cnt++;
				a = (a + K - 2) / K;
			}
			while (b > a) {
				cnt++;
				b = (b + K - 2) / K;
			}
		}
		cout << cnt << '\n';
	}
}