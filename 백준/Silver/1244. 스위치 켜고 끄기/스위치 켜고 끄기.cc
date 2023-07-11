/*1244*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>

using namespace std;

int bolt[101];
int N, M;

void boy(int b) {
	for (int i = b; i <= N; i += b) {
		if (bolt[i] == 1) bolt[i] = 0;
		else bolt[i] = 1;
	}
}

void girl(int b) {
	int left= b, right = b;

	while (left >= 1 && right <= N) {
		left--;
		right++;
		if (bolt[left] != bolt[right]) break;
	}

	for (int i = left + 1; i <= right - 1; i++) {
		if (bolt[i] == 1) bolt[i] = 0;
		else bolt[i] = 1;
	}
}

int main() {
	cin >> N;
	
	for (int i = 1; i <= N; i++) cin >> bolt[i];
	cin >> M;

	for (int t = 0; t < M; t++) {
		int a, b;
		cin >> a >> b;

		if (a == 1) boy(b);
		else girl(b);
	}

	for (int i = 1; i <= N; i++) {
		cout << bolt[i] << ' ';
		if (i % 20 == 0) cout << '\n';
	}
}