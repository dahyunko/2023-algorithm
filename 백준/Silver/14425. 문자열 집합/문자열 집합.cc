/*14425*/
//map : map<string, int>m;
#include <map>
#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	int N, M;

	cin >> N >> M;
	map<string, int> m;

	//문자열 저장
	for (int i = 0; i < N; i++) {
		string now;
		cin >> now;
		m.insert(make_pair(now, i));
	}

	//탐색
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		string now;
		cin >> now;
		cnt += m.count(now);
	}

	cout << cnt;
}