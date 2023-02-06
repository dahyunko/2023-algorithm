/*1043- 거짓말쟁이가 되긴 시러*/
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int find(vector<int>& A, int a) {
	if (A[a] == a) return a;
	return A[a] = find(A, A[a]);
}

void Union(vector<int>&A, int a, int b) {
	a = find(A, a);
	b = find(A, b);
	if (a != b) A[b] = a;
}

int main() {
	int N, M;
	int K;

	cin >> N >> M;
	vector<int> parent(N + 1, 0);
	vector<vector<int>> meet_info(M+1);

	cin >> K;//아는 사람
	vector<int> know_p(K);
	for (int i = 0; i < K; i++) {
		cin >> know_p[i];
	}

	//파티 수, 인원 입력 받음
	for (int i = 0; i < M; i++) {
		int meet_p;
		cin >> meet_p;
		for (int j = 0; j < meet_p; j++) {
			int now;
			cin >> now;
			meet_info[i].push_back(now);
		}
	}

	//부모 설정
	for (int i = 0; i <= N; i++) parent[i] = i;

	//union-find 실행
	for (int i = 0; i < M; i++) {
		int first_p = meet_info[i][0];
		for (int j = 1; j < meet_info[i].size(); j++) {
			Union(parent, first_p, meet_info[i][j]);
		}
	}

	//거짓말 가능 여부
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		bool isPossible = true;
		int cur = meet_info[i][0];
		//거짓말을 아는 사람
		for (int j = 0; j < K; j++) {
			if (find(parent, know_p[j]) == find(parent, cur)) {
				isPossible = false;
				break;
			}
		}
		if (isPossible == true) cnt++;
	}

	cout << cnt;
}