/*9017*/
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;

		int Team[601][5] = { 0 };//명수, 합계, 현재 학생 번수, 5번째, 이름
		vector<int>A(N);
		set<int> s;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
			Team[A[i]][0]++;
			s.insert(A[i]);
		}
		
		//팀원이 6명이 안되는 팀 
		int score = 0;
		for (int i = 0; i < N; i++) {
			if (Team[A[i]][0] < 6) continue;
			score++;
			Team[A[i]][2]++;
			if (Team[A[i]][2] < 5) Team[A[i]][1] += score;
			else if (Team[A[i]][2] == 5) Team[A[i]][3] = score;	
		}

		int ans, a = INT_MAX ,b = 0;
		for (int it : s) {
			if (Team[it][1] == 0) continue;
			if (a > Team[it][1]) {
				ans = it;
				a = Team[it][1];
				b = Team[it][3];
			}
			else if (a == Team[it][1]) {
				if (b > Team[it][3]) {
					b = Team[it][3];
					ans = it;
				}
			}
		}

		cout << ans << '\n';
	}
}