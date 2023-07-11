/*1157*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

typedef pair<char, int> info;

bool cmp(info a, info b) {
	return a.second > b.second;
}

int main() {
	string now;

	cin >> now;
	map<char, int>m;
	vector<info>arr;

	for (int i = 0; i < now.length(); i++) { 
		now[i] = toupper(now[i]); 
		m[now[i]]++;
	}

	for (auto it : m) {
		arr.push_back({ it.first, it.second });
	}

	sort(arr.begin(), arr.end(), cmp);

	if (arr[0].second == arr[1].second) cout << '?';
	else cout << arr[0].first;

}