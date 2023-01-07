#include <queue>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*033(1715)- 카드 정렬하기*/
#include<queue>// 오름차순 priority_queue

int main() {
	int N, result=0;

	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N; i++) {
		int now;
		cin >> now;
		pq.push(now);
	}

	while (pq.size()>1) {
		int t;
		t = pq.top();
		pq.pop();
		t += pq.top();
		pq.pop();
		pq.push(t);
		result += t;
	}

	cout << result;
}