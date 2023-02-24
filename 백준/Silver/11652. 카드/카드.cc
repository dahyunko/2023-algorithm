/*11652*/
#include<map>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

int main() {
	int N;
	
	cin >> N;
	map<ll, ll>map;
	for (int i = 0; i < N; i++) {
		ll now;
		cin >> now;
		map[now]++;
	}
	ll value = map.begin()->first, count = 0;

	for (auto iter = map.begin(); iter != map.end(); iter++) {
		if (count <= iter->second) {
			if (count == iter->second) value = min(value, iter->first);
			else value = iter->first;
			count = iter->second;
		}
	}

	cout << value;
}