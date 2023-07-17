/*1205*/
#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<map>

using namespace std;

typedef pair<long, int> info;

bool cmp(info a, info b) {
	return a.first > b.first;
}

int main() {
	int N, score, P;
	
	cin >> N >> score >> P;
	vector<info>A;
	map<long, int>m;

	for (int i = 0; i < N; i++) {
		long now;
		cin >> now;

		m[now]++;
	}
	m[score]++;

	for (auto it : m) A.push_back({ it.first, it.second });

	//정렬
	sort(A.begin(), A.end(), cmp);
	
	//score가 클 경우
	if (A[0].first == score) {
		if (A[0].second > P) cout << -1;
		else cout << 1;
		return 0;
	}
	int idx = 1, flag = 0;
	long temp = INT_MAX;

	for (int i = 0; i < A.size(); i++) {
		if (A[i].first == score) {
			if (idx + A[i].second - 1 <= P) {
				cout << idx;
			}
			else cout << -1;
			break;
		}
		idx += A[i].second;
	}
}