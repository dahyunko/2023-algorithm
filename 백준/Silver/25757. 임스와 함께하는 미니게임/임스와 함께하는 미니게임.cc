/*25757*/
#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<map>
#include<set>
#include<queue>
#include<stack>

using namespace std;

int main() {
	int N;
	char c;
	cin >> N >> c;

	map<string, int>m;
	for (int i = 0; i < N; i++) {
		string now;
		cin >> now;

		m[now]++;
	}

	int size = m.size();
	int cnt;
	if (c == 'Y')cnt = 1;
	if (c == 'F')cnt = 2;
	if (c == 'O')cnt = 3;

	cout << size / cnt;
}