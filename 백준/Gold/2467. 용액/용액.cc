/*2467*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
#include <cmath>
#include<limits.h>
#include<set>
#include<map>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;

	vector<ll>A(N+1);
	for (int i = 0; i < N; i++) cin >> A[i];

	int s = 0, e = N - 1;
	vector<int>list(2);
	ll answer = abs(A[s] + A[e]);
	list[0] = A[s];
	list[1] = A[e];

	while (s < e) {
		ll num = A[s] + A[e];
		if (answer > abs(num)) {
			answer = abs(num);
			list[0] = A[s];
			list[1] = A[e];
		}
		
		//num값이 산성 -> 알칼리성, 알칼리성 -> 산성
		if (num < 0) s++;
		else e--;
	}
	sort(list.begin(), list.end());
	
	cout << list[0] << ' ' << list[1];
}