/*21921*/
#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<map>
#include<set>
#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int X, N;
	cin >> X >> N;

	queue<int>q;
	int answer = 0, temp = 0, cnt=0;
	for (int i = 0; i < X; i++) {
		int now;
		cin >> now;
		if (q.size() < N) {
			temp += now;
			q.push(now);
			if (q.size() == N) {
				answer = temp;
				cnt = 1;
			}
			continue;
		}
		
		int v = q.front();
		q.pop();
		temp -= v;
		temp += now;
		q.push(now);

		if (answer < temp) { 
			answer = temp; 
			cnt = 1;
		}
		else if (answer == temp) cnt++;
	}

	if (answer == 0 && temp > 0) {
		answer = temp;
		cnt = 1;
	}
	if (answer == 0) cout << "SAD";
	else { 
		cout << answer<<'\n';
		cout << cnt;
	}
}