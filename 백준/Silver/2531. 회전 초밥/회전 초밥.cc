/*2531*/
#include<set>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
#include<limits.h>
#include<tuple>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, d, k, c;

	cin >> N >> d >> k >> c;
	vector<int>belt(N);
	vector<int>count(d + 1, 0);

	for (int i = 0; i < N; i++) cin >> belt[i];

	int s = 0, cnt = 0;
	
	set<int> set;

	//초기 상태
	int idx = s;
	for (int i = 0; i < k; i++) {
		idx = s + i;
		if (idx > N - 1) idx = 0;

		count[belt[idx]]++;
		if (set.find(belt[idx]) == set.end()) set.insert(belt[idx]);
	}

	while (s<N) {
		s++;
		int a = s - 1, b = s + k - 1;
		if (a == -1) a = N - 1;
		if (b >= N) b -= N;
		count[belt[a]]--;
		if (set.find(belt[a]) != set.end() && count[belt[a]] == 0) set.erase(belt[a]);
		count[belt[b]]++;
		if (set.find(belt[b]) == set.end()) set.insert(belt[b]);

		int temp = set.size();
		if (set.find(c) == set.end()) temp++;
		cnt = max(cnt, temp);
	}

	cout << cnt;
}