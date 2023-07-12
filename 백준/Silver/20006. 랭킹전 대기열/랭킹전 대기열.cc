/*20006*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
#include<limits.h>
#include<tuple>

using namespace std;

struct player {
	int level;
	string name;
};

bool cmp(player a, player b) {
	return a.name < b.name;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int p, m;
	cin >> p >> m;

	vector<vector<player>>room(301);

	int idx = 0;
	for (int t = 0; t < p; t++) {
		int level;
		string name;
		
		cin >> level >> name;

		if (t == 0) { 
			room[idx].push_back({ level, name }); 
			idx++;
			continue;
		}

		//방에 집어 넣기
		int flag = 0;
		for (int i = 0; i < idx; i++) {
			if (room[i].size() >= m) continue;
			if(level >= room[i][0].level - 10 && level <= room[i][0].level + 10) {
				room[i].push_back({ level, name });
				flag = 1;//방 들어감
				break;
			}
		}
		//들어갈 곳 없으면 새방 만든다.
		if (flag == 0) {
			room[idx].push_back({ level, name });
			idx++;
		}
	}

	for (int i = 0; i < idx; i++) {
		sort(room[i].begin(), room[i].end(), cmp);
		if (room[i].size() >= m) {
			cout << "Started!" << '\n';
			for (auto it : room[i]) cout << it.level << ' ' << it.name << '\n';
		}
		else {
			cout << "Waiting!" << '\n';
			for (auto it : room[i]) cout << it.level << ' ' << it.name << '\n';
		}
	}
}