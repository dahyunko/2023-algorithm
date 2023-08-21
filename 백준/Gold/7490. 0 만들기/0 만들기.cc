/*7490*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
#include <cmath>
#include<limits.h>
#include<set>
#include<map>

using namespace std;

int N;
char list[18];

void dfs(int c, int sum , int t, int flag) {
	if (c == 2 * N - 1) {
		if (t != 0) {
			if (flag == 0) sum += t;
			else sum -= t;
		}
		if (sum == 0) {
			for (int i = 0; i < 2 * N - 1; i++) cout << list[i];
			cout << '\n';
		}
		return;
	}

	int num = list[c + 1] - '0', temp = sum;
	if (flag == 0) temp += t;
	else temp -= t;
    
    //정답 출력 순서 있음
    list[c] = ' ';
	dfs(c + 2, sum , t * 10 + num, flag);
	list[c] = '+';
	dfs(c + 2, temp, num, 0);
	list[c] = '-';
	dfs(c + 2, temp, num, 1);
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N;

		int v = 0;
		for (int i = 0; i < N; i++) {
			list[v] = i + 1 + '0';
			v += 2;
		}

		dfs(1, 0, 1, 0);

		cout << '\n';
	}
}