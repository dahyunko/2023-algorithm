/*사탕게임*/
#include<map>
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

int N;
map<char, int> m;
vector<string>B(N);

void search1(int i) {
	char now = B[i][0];
	int j = 1, cnt = 1;
	while (j < N) {
		if (now == B[i][j]) cnt++;
		else {
			m[now] = max(cnt, m[now]);
			now = B[i][j];
			cnt = 1;
		}
		if (j == N - 1) {
			m[now] = max(cnt, m[now]);
		}
		j++;
	}
}

void search2(int i) {
	char now = B[0][i];
	int j = 1, cnt = 1;
	while (j < N) {
		if (now == B[j][i]) cnt++;
		else {
			m[now] = max(cnt, m[now]);
			now = B[j][i];
			cnt = 1;
		}
		if (j == N - 1) {
			m[now] = max(cnt, m[now]);
		}
		j++;
	}
}

int main() {
	cin >> N;

	m.insert({ 'C',0 });
	m.insert({ 'P',0 });
	m.insert({ 'Z',0 });
	m.insert({ 'Y',0 });

	for (int i = 0; i < N; i++) { 
		string now;
		cin >> now;
		B.push_back(now);
	}

	//변하기 전의 최대 개수 세기
	for (int i = 0; i < N; i++) search1(i);
	for (int i = 0; i < N; i++) search2(i);

	//자리 바꿈
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N-1; j++) {
			if (B[i][j] != B[i][j + 1]) {
				swap(B[i][j], B[i][j + 1]);
				search1(i);
				search2(j);
				search2(j+1);
				swap(B[i][j], B[i][j + 1]);
			}
		}
	}
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N-1; i++) {
			if (B[i][j] != B[i + 1][j]) {
				swap(B[i][j], B[i + 1][j]);
				search1(i);
				search1(i+1);
				search2(j);
				swap(B[i][j], B[i + 1][j]);
			}
		}
	}
	int ans = 0;
	ans = max(m['C'], ans);
	ans = max(m['P'], ans);
	ans = max(m['Z'], ans);
	ans = max(m['Y'], ans);

	cout << ans;
}