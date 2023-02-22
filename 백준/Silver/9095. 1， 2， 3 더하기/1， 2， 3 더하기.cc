/*9095*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int result = 0;
int T, N;

void dfs(int cnt) {
	if (cnt == N) {result++; return;}

	for (int i = 1; i <= 3; i++) {
		if (cnt + i <= N) dfs(cnt + i);
	}
}

int main() {
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		cin >> N;

		result = 0;
		dfs(0);
		cout << result << '\n';
	}
}