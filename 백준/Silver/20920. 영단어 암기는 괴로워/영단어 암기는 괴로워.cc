#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

/*20920*/
typedef pair<string, int> info;

bool cmp(info a, info b) {
	if (a.second == b.second) { 
		if(a.first.length() == b.first.length()) return a.first < b.first; 
		return a.first.length() > b.first.length();
	}
	return a.second > b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	map<string, int> m;
	vector<info> word;

	for (int i = 0; i < N; i++) {
		string now;
		cin >> now;

		if (now.length() < M)continue;
		m[now]++;
	}

	for (auto it : m) {
		word.push_back({ it.first, it.second });
	}

	sort(word.begin(), word.end(), cmp);

	for (int i = 0; i < word.size(); i++) cout << word[i].first << '\n';
}