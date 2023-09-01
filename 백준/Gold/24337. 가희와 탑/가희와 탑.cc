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

int main() {
	int N, a, b;
	cin >> N >> a >> b;
	vector<int>list;

	if (a > b) {
		for (int i = 1; i <= a; i++) list.push_back(i);
		for (int i = b - 1; i > 0; i--) list.push_back(i);
	}
	else {
		//뒤집으면 됨
		for (int i = 1; i <= b; i++) list.push_back(i);
		for (int i = a - 1; i > 0; i--) list.push_back(i);

		reverse(list.begin(), list.end());
	}

	if (list.size() > N) cout << -1;
	else {
		cout << list[0] << ' ';
		for (int j = 0; j < N - list.size(); j++) cout << 1 << ' ';
		for (int i = 1; i < list.size(); i++) cout << list[i] << ' ';
	}
}