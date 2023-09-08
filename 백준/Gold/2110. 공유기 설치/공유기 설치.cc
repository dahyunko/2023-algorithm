#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<limits.h>
#include<cmath>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, C;
	ll ans = 0;
	cin >> N >> C;

	vector<ll>A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A.begin(), A.end());

	//이분 탐색
	//idea - 떨어지는 거리 기준으로 찾는 것임
	//첫 공유기와 마지막 공유기는 항상 설치 되어야 함
	// -> 최대 거리이기 때문
	ll start = 1;//최소 떨어지는 거리
	ll end = A[N - 1] - A[0];//최대 떨어지는 거리

	while (start <= end) {
		ll mid = (start + end) / 2;
		int router = 1;//0번째는 꼭 설치되기 때문
		ll loc = A[0];

		for (int i = 1; i < N; i++) {
			if (A[i] - loc >= mid) {
				router++;
				loc = A[i];
			}
		}

		if (router >= C) {
			ans = max(ans, mid);
			start = mid + 1;
		}
		else end = mid - 1;
	}

	cout << ans;
}