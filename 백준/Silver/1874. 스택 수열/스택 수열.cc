#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	int N;//수열의 개수
	int num=0;
	int flag = 0;

	cin >> N;
	vector <int> A(N, 0);//수열
	vector<char> result;//결과값 저장

	stack <int> stack;//스택 선언

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		
		//수열에서 해당 숫자가 나오기 전까지 삽입
		while (num < A[i]) {
			num++;
			stack.push(num);
			result.push_back('+');//삽입
		}
		
		if (stack.top() == A[i]) {
			stack.pop();
			result.push_back('-');
		}
		if (!stack.empty() &&stack.top() > A[i]) {
			cout << "NO" << '\n';
			flag = 1;//result 출력 여부 결정
			break;
		}
	}

	if (flag == 0) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << '\n';
		}
	}
}