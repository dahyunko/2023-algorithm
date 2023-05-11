/*17298*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<tuple>
#include<limits.h>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int>ans(N);
	vector<int>A(N);
	for (int i = 0; i < N; i++) cin >> A[i];

	stack<int>s;
	s.push(A[N - 1]);
	ans[N - 1] = -1;

	for (int i = N - 2; i >= 0; i--) {
        //더 큰값을 찾는 것
		while (!s.empty() && A[i] >= s.top()) s.pop();

		if (s.empty()) {
			ans[i] = -1;
			s.push(A[i]);
			continue;
		}

		ans[i] = s.top();
		s.push(A[i]);
	}
	
	for (int i = 0; i < N; i++) cout<<ans[i]<<' ';
}