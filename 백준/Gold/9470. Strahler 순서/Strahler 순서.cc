/*strahler 순서*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

#include<queue>

int main() {
	int T, K, M, P;

	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> K >> M >> P;
		vector<vector<int>>graph(M+1);
		vector<int>d(M + 1, 0);
		vector<int>s(M + 1);
		vector<vector<int>>b(M + 1);

		for (int i = 0; i < P; i++) {
			int s, e;
			cin >> s >> e;
			graph[s].push_back(e);
			d[e]++;
		}

		queue<int>q;
		for (int i = 1; i < M + 1; i++) { 
			if (d[i] == 0) { s[i] = 1; q.push(i); }
		}
		
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			if (!b[v].empty()) {
				int max = 0;
				bool flag = false;

				for (int i = 0; i < b[v].size(); i++) {
					if (b[v][i] > max) {
						max = b[v][i];
						flag = false;
					}
					else if (max == b[v][i]) flag = true;
				}
				if (flag)s[v] = max + 1;
				else s[v] = max;
				
			}


			for (int i = 0; i < graph[v].size(); i++) {
				int n = graph[v][i];
				d[n]--;
				b[n].push_back(s[v]);
				if (d[n] == 0) q.push(n);
			}
		}
		cout << K << ' ' << *max_element(s.begin(), s.end()) << '\n';
	}
}