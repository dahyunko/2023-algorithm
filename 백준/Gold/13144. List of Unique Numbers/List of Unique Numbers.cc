/*13144*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
#include<limits.h>
#include<tuple>

using namespace std;

bool visited[100001];

int main() {
	int N;
	cin >> N;

	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];

	long long cnt = 0;
    int start = 0, end = 0;
	
	for (int start = 0; start < N; start++) {
		while (end < N) {
			if (visited[A[end]]) break;
			visited[A[end]] = true;
			end++;
		}

		cnt += end - start;
		visited[A[start]] = false;
	}

	cout << cnt;
}