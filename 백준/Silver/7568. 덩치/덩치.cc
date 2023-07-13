/*7568*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
#include<limits.h>
#include<tuple>

using namespace std;

struct info {
	int weight;
	int height;
};

int main() {
	int N;
	cin >> N;

	vector<info>A;
	vector<int>result;

	for (int t = 0; t < N; t++) {
		int w, h;
		cin >> w >> h;

		A.push_back({ w, h });
	}
	
	for (int i = 0; i < N; i++) {
		int rank = 1;
		for (int j = 0; j < N; j++) {
			if (i == j) continue;

			if (A[i].height < A[j].height && A[i].weight < A[j].weight) rank++;
		}
		result.push_back(rank);
	}

	for (auto it : result)cout << it << ' ';
}