/*10815*/
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

typedef pair<long, int> info;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	
	cin >> N;
	vector<long>A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A.begin(), A.end());

	cin >> M;
	vector<info>B;
	vector<long>result(M, 0);
	for (int i = 0; i < M; i++) {
		long now;
		cin >> now;
		B.push_back(info(now, i));
	}
	sort(B.begin(), B.end());

	int a = 0, b = 0;
	while (a < N && b < M) {
		if(A[a] == B[b].first){//같은 것
			result[B[b].second] = 1;
			a++;
			b++;
		}
		else {
			if (A[a] > B[b].first) b++;
			else a++;
		}
	}

	for (int i = 0; i < M; i++) cout<< result[i]<<' ';
}