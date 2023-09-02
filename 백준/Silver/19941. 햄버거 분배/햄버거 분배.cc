/*19941*/
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
	int N, K;
	cin >> N >> K;
	vector<char>A(N);
	queue<int>h;
	queue<int>p;

	char now;
	for (int i = 0; i < N; i++) {
		cin >> now;

		if (now == 'H') h.push(i);
		else p.push(i);
	}
	
	int cnt = 0;
	while (!p.empty()) {
		int per = p.front();
		p.pop();

		while (!h.empty()) {
			int ham = h.front();

			if (ham >= per - K && ham <= per + K) {
				cnt++;
				h.pop();
				break;
			}
			else if (ham < per - K) h.pop();
			else if (ham > per + K) break;
		}
	}

	cout << cnt;
}