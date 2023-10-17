#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<limits.h>
#include<cmath>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int>road(N - 1);
	for (int i = 0; i < N - 1; i++) cin >> road[i];

	vector<int>oil(N);
	for (int i = 0; i < N; i++) cin >> oil[i];

	int result = 0;
	int o = oil[0];//처음은 무조건 오일 사용해야함

	for (int i = 0; i < N - 1; i++) {
		o = min(o, oil[i]);
		result += o * road[i];
	}
	cout << result;
}