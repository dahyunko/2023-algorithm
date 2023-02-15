/*1764*/
#include<map>
#include <iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main() {
	int N, M;
	
	cin >> N >> M;
	map<string, int> m;
	vector<string>ans;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		m.insert(make_pair(str, i));
	}

	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;
		string idx;
		if (m.find(str) != m.end()) {
			ans.push_back(str);
		}
	}
	sort(ans.begin(), ans.end());
	
    cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
}