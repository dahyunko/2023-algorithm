#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include <string>

using namespace std;

/*2504, 괄호의 값*/

int main() {
	string sen;
	stack<long> S;
	//(:  -1, [: -2

	cin >> sen;

	int flag = 0;
	for (int i = 0; i < sen.length(); i++) {
		if (sen[i] == '(') S.push(-1);
		else if (sen[i] == ')') {
			if (S.empty()) { flag = 1; break; }
			
			long now = S.top();
			S.pop();
			if (now == -1) S.push(2);
			else if (now == -2) { flag = 1; break; }
			else {
				long num = now;
				if (!S.empty()) {
					long prev = S.top();
					while (prev != -1 && prev != -2) {
						S.pop();
						num += prev;
						if (S.empty())break;
						prev = S.top();
					}
					if(prev == -1 || prev == -2)S.pop();
					if (prev == -2) { flag = 1; break; }

					num *= 2;
					S.push(num);
				}
				else { flag = 1; break; }
			}
		}
		else if (sen[i] == '[') S.push(-2);
		else if (sen[i] == ']') {
			if (S.empty()) { flag = 1; break; }

			long now = S.top();
			S.pop();
			if (now == -2) S.push(3);
			else if (now == -1 ) { flag = 1; break; }
			else {
				long num = now;
				if (!S.empty()) {
					long prev = S.top();
					while (prev != -1 && prev != -2) {
						S.pop();
						num += prev;
						if (S.empty())break;
						prev = S.top();
					}
					if (prev == -1 || prev == -2)S.pop();
					if (prev == -1) {flag = 1; break;}

					num *= 3;
					S.push(num);
				}
				else { flag = 1; break; }
			}
		}
	}

	if (flag == 1) cout << 0;
	else {
		long now = S.top();
		S.pop();
		if (now == -1 || now == -2) cout << 0;
		else {
			long num = now;
			if (!S.empty()) {
				long prev = S.top();
				while (prev != -1 && prev != -2) {
					S.pop();
					num += prev;
					if (S.empty())break;
					prev = S.top();
				}
				if (prev == -1 || prev == -2)cout << 0;
				else cout << num;

				while (!S.empty()) S.pop();
			}
			else cout << num;
		}
	}
}