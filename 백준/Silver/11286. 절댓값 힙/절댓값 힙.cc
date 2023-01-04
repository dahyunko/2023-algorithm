/*014-절대값 힙 구현하기*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>//절대값 구하는 함수: asb
//float, double: cmath 이용

using namespace std;

struct cmp {
	//절대값이 더 작은 값에 우선순위를 높게 주고,
	//절대값이 같다면 더 작은 값에 우선순위를 높게 준다.
	bool operator()(int n1, int n2) {
		if (abs(n1) > abs(n2)) {
			return true;
		}
		else if (abs(n1) == abs(n2)) {
			if (n1 > n2) return true;
			else return false;
		}
		return false;
	}

};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	priority_queue <int, vector<int>, cmp > que;//우선순위 큐 선언
	
	cin >> N;
	vector<int> x(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}

	for (int i = 0; i < N; i++) {
		if (x[i] == 0) {
			//cout << "out" << '\n';
			//배열이 빈 경우 0출력
			if (que.empty()) {
				cout << '0' << '\n';
			}
			else {
				cout << que.top() << '\n'; 
				que.pop();
			}
		}
		else {//추가
			que.push(x[i]);
		}
	}
}