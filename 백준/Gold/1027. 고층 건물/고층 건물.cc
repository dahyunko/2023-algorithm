/*1027*/
#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	cin >> n;

	vector<int>count(n, 0);
	vector<int>A(n);

	for (int i = 0; i < n; i++) cin >> A[i];

	for (int i = 0; i < n; i++) {
		double max_h = -1000000000;

		for (int j = i + 1; j < n; j++) {
            int h = A[j] - A[i];
            int w = j-i;
			double temp = h * 1.0 / w;

			if (max_h < temp) {
				count[i]++;
				count[j]++;
				max_h = temp;
			}
		}
	}

	cout << *max_element(count.begin(), count.end());
}