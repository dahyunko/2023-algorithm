/*가르침*/
//백트래킹
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;
typedef pair<char, bool>info;

int N, K;
int result = 0;
vector<info> list(27);
vector<char>A;

void dfs(int c, int t,vector<string>&word){
	if (c == K) {
		int cnt = 0;
		for (int i = 0; i < word.size(); i++) {
			bool flag = false;
			for (int j = 0; j < word[i].length(); j++) {
				char now = word[i][j];

				if (now < 'a' || now>'z') {
					flag = true;
					break;
				}
				//못찾음
				if (!list[now-'a'].second) {
					flag = true;
					break;
				}
			}
			if(!flag) cnt++;
		}
		result = max(cnt, result);
		return;
	}

	for (int i = t; i < A.size(); i++) {
		char v = A[i];
		int now = v - 'a';
		if (!list[now].second) {
			list[now].second = true;
			dfs( c + 1, i, word);
			list[now].second = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	vector<string>word(N);
	vector<bool>c(27, false);

	for (int i = 0; i < N; i++) cin >> word[i];

	if (K < 5) cout << 0;
	else if (K == 26) cout << N;
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < word[i].length(); j++) {
				char now = word[i][j];
				if (now<'a' || now>'z') {
					continue; 
				}
				c[now - 'a'] = true;
			}
		}

		list['a'-'a'] = info('a',true);
		list['c'-'a'] = info('c',true);
		list['t'-'a'] = info('t',true);
		list['i'-'a'] = info('i',true);
		list['n'-'a'] = info('n',true);

		for (int i = 0; i < c.size(); i++) {
			char now = i + 'a';
			if (now == 'a' || now == 'c' || now == 't' || now == 'i' || now == 'n') continue;
			if (c[i]) A.push_back(now);
		}

		K -= 5;

		if (A.size() < K) result = N;
		else dfs(0, 0, word);
	
		cout << result;
	}
}