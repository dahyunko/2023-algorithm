/*13164*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;
typedef long long ll;
bool comp(int a, int b) {
	return a > b;
}

int main() {
	int N, K;
	cin >> N >> K;
	
	ll answer = 0;
	vector<ll> children(N);
	vector<ll> dist;

	cin >> children[0];
	for (int i = 1; i < N; i++) {
		cin >> children[i];

		dist.push_back(children[i] - children[i - 1]);
		answer += children[i] - children[i - 1];
	}

	sort(dist.begin(),dist.end(), comp);

	for (int i = 0; i < K - 1;i++) {
		answer -= dist[i];
	}

	cout << answer;
}