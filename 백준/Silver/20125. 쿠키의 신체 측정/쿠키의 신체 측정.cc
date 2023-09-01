#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
#include<stack>
#include <cmath>
#include<limits.h>
#include<set>
#include<map>

using namespace std;

struct info {
	int x, y;
};

int main() {
	int N;
	cin >> N;
	vector<vector<char>>cookie(N, vector<char>(N));
	vector<int>ans(5, 0);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> cookie[i][j];
	}

	info head;
	bool find = false;

	//머리 찾기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (cookie[i][j] == '_') continue;
			head = { i, j };
			find = true;
			break;
		}
		if (find) break;
	}

	//팔 찾기
	int temp_l = head.y-1, temp_r = head.y+1;
	while (temp_l >= 0) {
		if (cookie[head.x + 1][temp_l--] != '*') break;
		ans[0]++;
	}
	while (temp_r < N) {
		if (cookie[head.x + 1][temp_r++] != '*') break;
		ans[1]++;
	}

	//허리 찾기
	int temp_m = head.x + 2;
	while (temp_m < N) {
		if (cookie[temp_m++][head.y] != '*') break;
		ans[2]++;
	}

	//다리 찾기
	int leg_l = temp_m-1, leg_r = temp_m - 1;
	while (leg_l < N) {
		if (cookie[leg_l++][head.y - 1] != '*') break;
		ans[3]++;
	}
	while (leg_r < N) {
		if (cookie[leg_r++][head.y + 1] != '*') break;
		ans[4]++;
	}
    cout << head.x + 2 << ' ' << head.y + 1 << '\n';
	for (int i = 0; i < 5; i++) cout << ans[i] << ' ';
}