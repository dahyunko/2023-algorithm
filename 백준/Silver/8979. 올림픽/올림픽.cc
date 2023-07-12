/*8979*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
#include<limits.h>
#include<tuple>

using namespace std;

struct medal {
	int name;
	int g;
	int s;
	int b;
};

bool cmp(medal a, medal b) {
	if (a.g == b.g) {
		if (a.s == b.s) return a.b > b.b;
		return a.s > b.s;
	}
	return a.g > b.g;
}

int main() {
	int N, K;
	cin >> N >> K;

	vector<medal>site;

	for (int i = 0; i < N; i++) {
		int now, g, s, b;
		cin >> now >> g >> s >> b;

		site.push_back({ now, g,s,b });
	}

	sort(site.begin(), site.end(), cmp);

	if (site[0].name == K) cout << 1;
	else {
		medal it = site[0];
		int rank = 1;
		for (int i = 1; i < site.size(); i++) {
			if (it.g == site[i].g) {
				if (it.s == site[i].s) {
					if (it.b == site[i].b) {
						it = site[i];
					}
					else if (it.b > site[i].b) {
						it = site[i];
						rank = i + 1;
					}
				}
				else if (it.s > site[i].s) {
					it = site[i];
					rank = i + 1;
				}
			}
			else if (it.g > site[i].g) {
				it = site[i];
				rank = i+1;
			}

			if (site[i].name == K) break;
		}

		cout << rank;
	}
}