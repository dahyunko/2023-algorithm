/*1446*/
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

struct info {
	int start, end, weight;
};

bool comp(info a, info b) {
	return a.start < b.start;
}

int main() {
	int N, D;
	cin >> N >> D;

	vector<info>graph;
	int dp[10001];

	for (int i = 0; i < N; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		graph.push_back({ s, e, w });
	}

	//출발 순으로 sort진행
	sort(graph.begin(), graph.end(), comp);
	
	//길이 먼저 저장
	for (int i = 0; i < 10001; i++) dp[i] = i;
	
	for (int i = 0; i < N; i++) {
		info v = graph[i];
		if (dp[v.end] > dp[v.start] + v.weight) {
			dp[v.end] = dp[v.start] + v.weight;
			//숫자 갱신
			for (int j = v.end; j <= D; j++) dp[j] = min(dp[j], dp[v.end] + (j - v.end));
		}
	}
	cout << dp[D];
}