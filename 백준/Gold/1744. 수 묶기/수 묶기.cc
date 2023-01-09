/*034(1744)-수 묶어서 최대값 만들기*/
#include<queue>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N, result = 0, zero = 0;
	priority_queue<int, vector<int>,less<int>> pq_positive;
	//양수는 큰 값부터 나오고
	priority_queue<int, vector<int>, greater<int>> pq_negative;
	//음수는 작은 값부터 나와야함
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		int now;
		cin >>now;

		if (now == 1) {//1은 더해준다
			result += now;
		}
		else if (now > 1) {//양수는 양수끼리 따로 넣어준다.
			pq_positive.push(now);
		}
		else if (now < 0) {//음수는 음수끼리
			pq_negative.push(now);
		}
		else if (now == 0) {//0은 음수가 홀수개 존재시 사용
			zero++;
		}
	}

	//양수 부터
	while (!pq_positive.empty()) {
		if (pq_positive.size() == 1) {//하나 남았을 경우 그냥 더해준다
			result += pq_positive.top();
			pq_positive.pop();
		}
		else {
			int a, b;
			a = pq_positive.top();
			pq_positive.pop();
			b = pq_positive.top();
			pq_positive.pop();
			result += a * b;
		}
	}

	//음수
	while (!pq_negative.empty()) {
		if (pq_negative.size() == 1) {//하나 남았을 경우 그냥 더해준다
			if (zero ==  0) {//0이 없을 시 계산하고 있을 경우 0
				result += pq_negative.top();
			}
			pq_negative.pop();
		}
		else {
			int a, b;
			a = pq_negative.top();
			pq_negative.pop();
			b = pq_negative.top();
			pq_negative.pop();
			result += a * b;
		}
	}

	cout << result << '\n';
}