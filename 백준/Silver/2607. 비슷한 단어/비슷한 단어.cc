/*2607*/
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

int main() {
	int N, cnt = 0;
	cin >> N;

	vector<string>word(N);

	for (int i = 0; i < N; i++) cin >> word[i];
	
	string a, b;
	a = word[0];
	sort(a.begin(), a.end());

	//cout << '\n';
	for (int i = 1; i < N; i++) {
		b = word[i];
		sort(b.begin(), b.end());

		int t = 0, c = 0, j = 0;
		while (j < b.length() && t < a.length()) {
			if (b[j] == a[t]) { t++; c++; }
			else if (b[j] > a[t]) { j--; t++; }
			j++;
		}

		//하나 삭제, 추가 변경 가능
		if (c == a.length()) {
			if (b.length() >= a.length() && b.length() <= a.length() + 1) cnt++;
			//cout << word[i] << '\n';
		}
		else if (c == a.length() - 1) {
			if (b.length() >= a.length() -1 && b.length() <= a.length()) cnt++;
			//cout << word[i] << '\n';
		}
	}

	cout << cnt;
}