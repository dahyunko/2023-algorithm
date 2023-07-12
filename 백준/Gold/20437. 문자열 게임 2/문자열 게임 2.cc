/*20437*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
#include<limits.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, K;
	string s;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> s;
		cin >> K;

		vector<vector<int>>alpha(27);
		int min_sen = INT_MAX, max_sen = INT_MIN;

		for (int i = 0; i < s.length();i++) alpha[s[i]-'a'].push_back(i);

		//가장 짧은 문자열, 가장 긴 연속 문자열
		for (int i = 0; i < alpha.size(); i++) {
			if (alpha[i].size() < K) continue;

			for (int j = K - 1; j < alpha[i].size(); j++) {
				min_sen = min(alpha[i][j] - alpha[i][j - K + 1] + 1, min_sen);
				max_sen = max(alpha[i][j] - alpha[i][j - K + 1] + 1, max_sen);
			}
		}

		if (min_sen == INT_MAX || max_sen == INT_MIN) cout << -1 << '\n';
		else cout << min_sen << ' ' << max_sen << '\n';
	}
}