/*013- 카드게임*/
#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	//큐 생성
	queue<int> que;
	for (int i = 1; i <= N; i++) {
		que.push(i);
	}

	while (que.size() > 1) {
		//앞 버리기
		que.pop();
		//2번째 뒤로 밀기
		int n = que.front();
		que.pop();
		que.push(n);
	}

	cout << que.front() << '\n';
}

/*
* queue: FIFO, 제일 처음 넣은 데이터가 처음으로 나오는 것
* push, pop, empty, front, back, swap
*/