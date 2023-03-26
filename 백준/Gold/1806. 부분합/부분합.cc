/*부분합*/
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include <string>

using namespace std;

int main() {
	int N, S;

	cin >> N >> S;

	vector<int>d(N+1, 0);

	//첫번째 숫자가 S 이상일 경우 또한 고려해줘야함
	d[0] = 0;
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;

		d[i] = d[i - 1] + num;
	}

	if (d[N] < S) cout << 0;
	else {
		int s = 0, e = 0 ;
		int ans = N;

		while (s <= e) {
			if (d[e] - d[s] >= S) {
				ans = min(ans, e - s);
				s++;
			}
			else {
				e++;
				if (e > N) break;
			}
		}

		cout << ans;
	}
}