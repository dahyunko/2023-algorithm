#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

/*1141*/

int main() {
	int ans=0, N;
	cin >> N;
	vector<string>words(N);
	vector<bool>check(N, false);

	for (int i = 0; i < N; i++) cin >> words[i];

	sort(words.begin(), words.end());

	for (int i = 0; i < words.size()-1; i++) {
		for (int j = i + 1; j < words.size(); j++) {
			if (words[j].substr(0, words[i].length()) == words[i]) {
				check[i] = true;
				break;
			}
		}
	}

	for (auto i : check) {
		if (!i) ans++;
	}

	cout << ans;
}