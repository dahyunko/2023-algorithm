#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);

	int N, now;
	int num=1;
	int flag = 0;//no 출력 여부

	stack<int> stack;
	vector<char> result;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> now;
		
		//stack 추가
		while (num <= now) {
			stack.push(num++);
			result.push_back('+');
		}
		//now와 같을 경우 pop
		if (stack.top() == now) {
			stack.pop();
			result.push_back('-');
		}
		else {//잘못된 스택
			flag = 1;
			break;
		}
	}

	if (flag == 0) {
		for (int i = 0; i < result.size(); i++) cout << result[i] << '\n';
	}else cout << "NO" << '\n';
}