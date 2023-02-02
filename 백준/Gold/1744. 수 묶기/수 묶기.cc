/*034(1744)*/
#include<queue>
#include<numeric>
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	vector<long> result;
	priority_queue<int, vector<int>, less<int>> pq_pos;
	priority_queue<int, vector<int>, greater<int>> pq_neg;
	int cnt_Zero = 0;
	int cnt_One = 0;
	for (int i = 0; i < N; i++) {
		int now;
		cin >> now;
		
		if (now > 1) {//양수
			pq_pos.push(now);
		}
		else if (now < 0) {//음수
			pq_neg.push(now);
		}
		else if(now == 0) {
			cnt_Zero++;
		}
		else {//1일 경우
			cnt_One++;
		}
	}

	//양수 묶음
	while (!pq_pos.empty()) {
		if (pq_pos.size() == 1) {
			result.push_back(pq_pos.top());
			pq_pos.pop();
		}
		else {
			int a = pq_pos.top();
			pq_pos.pop();
			int b = pq_pos.top();
			pq_pos.pop();
			result.push_back(a * b);
		}
	}

	//음수 묶음
	while (!pq_neg.empty()) {
		if (pq_neg.size() == 1) {
			if (cnt_Zero == 0) {//0이 존재할 시 음수 제거
				result.push_back(pq_neg.top());
			}
			pq_neg.pop();
		}
		else {
			int a = pq_neg.top();
			pq_neg.pop();
			int b = pq_neg.top();
			pq_neg.pop();
			result.push_back(a * b);
		}
	}

	cout << accumulate(result.begin(), result.end(), 0) + cnt_One;
}