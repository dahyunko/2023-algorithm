#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int M;
	vector<int>S;
	cin >> M;

	for (int t = 0; t < M; t++) {
		string now;
		int x;
		cin >> now;

		if (now == "add") {
			cin >> x;
			//있을 경우
			if (find(S.begin(), S.end(), x) != S.end()) continue;
			S.push_back(x);
		}
		else if(now =="remove") {
			cin >> x;
			if (find(S.begin(), S.end(), x) == S.end()) continue;
			//값으로 삭제
			S.erase(remove(S.begin(), S.end(), x), S.end());
		}
		else if (now == "check") {
			cin >> x;
			if (find(S.begin(), S.end(), x) != S.end()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (now == "toggle") {
			cin >> x;
			if (find(S.begin(), S.end(), x) != S.end()) {
				S.erase(remove(S.begin(), S.end(), x), S.end());
			}
			else {
				S.push_back(x);
			}
		}
		else if (now == "all") {
			S = { 1, 2, 3, 4, 5,6,7,8,9,10, 11,12,13,14,15,16,17,18,19,20 };
		}
		else if (now == "empty") {
			S.clear();
		}
	}
}