/*14658*/
//idea: 모든 구역을 L만큼 탐색 => 시간 초과 발생 + 메모리 초과
//따라서, 별똥별 2개를 기준으로 x, y 잡아와서 L의 범위 안에 
//별동별이 존재하는지 확인해 보는 것 => 시간, 메모리 초과 해결
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<limits.h>
#include<cmath>

using namespace std;

struct info {
	int x, y;
};

int main() {
	int N, M, L, K, ans = 0;
	cin >> N >> M >> L >> K;

	vector<info>star(K);
	for (int i = 0; i < K; i++) cin >> star[i].x >> star[i].y;

	//3중 for문 => K^3
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++) {
			int a = star[i].x;
			int b = star[j].y;
			int cnt = 0;

			for (int t = 0; t < K; t++) {
				if (star[t].x >= a && star[t].x <= a + L && star[t].y >= b && star[t].y <= b + L) cnt++;
			}
			ans = max(ans, cnt);
		}
	}

    //지구에 떨어지는 별의 개수
	cout << K - ans;
}