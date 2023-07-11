/*22233*/
#include<unordered_set>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>

using namespace std;

vector<string> spilt(string input, char delimeter) {
	vector<string>result;
	stringstream s(input);
	string sen;

	while (getline(s, sen, delimeter)) result.push_back(sen);
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;

	cin >> N >> M;
	unordered_set<string> s;
	for (int i = 0; i < N; i++) { 
		string now;
		cin >> now;

		s.insert(now);
	}

	for (int t = 0; t < M; t++) {
		string now;
		cin >> now;

		vector<string>gahi = spilt(now, ',');

		for (int i = 0; i < gahi.size(); i++) {
			if(s.find(gahi[i]) != s.end()) s.erase(gahi[i]);
		}
		cout << s.size()<<'\n';
	}
}