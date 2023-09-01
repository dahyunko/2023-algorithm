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
	int N;
	cin >> N;
	vector<string> sen(N);
	
	for (int i = 0; i < N; i++) cin >> sen[i];
	
	int cnt =0;
	string ans1, ans2;

	//문자열 비교
	for (int i = 0; i < N; i++) {
		if (cnt > sen[i].length()) continue;

		for (int j = i + 1; j < N; j++) {
			if (sen[i] == sen[j]) continue;

			//비교
			string s1 = sen[i];
			string s2 = sen[j];

			if (s1.length() > s2.length()) swap(s1, s2);

			int c = 0;
			for (int t = 0; t < s1.length(); t++) {
				if (s1[t] != s2[t]) break;
				c++;
			}

			if (cnt < c) {
				cnt = c;
				ans1 = sen[i];
				ans2 = sen[j];
			}
		}
	}
	
	cout << ans1 << '\n' << ans2;
}