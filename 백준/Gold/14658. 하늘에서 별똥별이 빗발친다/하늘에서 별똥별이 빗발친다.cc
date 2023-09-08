/*14658*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
#include <cmath>
#include<limits.h>
#include<set>
#include<map>

using namespace std;

int main() {
	int N, M, L, K;
	cin >> N >> M >> L >> K;

	vector<pair<int, int>> ground(K);

	//별동별
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		
		ground[i] = { b,a };
	}
	
	int ans = 0;
	
	//시간 복잡도 + 공간 복잡도
	//별동별의 개수로 접근해야함
	//별동별은 최대 100개 임으로 이를 K^3 을 진행해도 됨
	//별동별 2개 잡고 a.x, b.y 를 기준으로 별동별 탐색 진행해야함
	//K^3 이기 때문에 a와 b가 바뀌고 현재 자신도 보기 때문에 모든 경우 탐색 가능
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++) {
			int temp = 0;
			int a = ground[i].first;
			int b = ground[j].second;
			for (int k = 0; k < K; k++) {
				int na = ground[k].first;
				int nb = ground[k].second;
				//별동별이 떨어지는 위치여서 길이기 L이면 L+1개의 점을 확인해야함
				if (a <= na && a + L >= na && b <= nb && b + L >= nb) temp++;
			}
			ans = max(ans, temp);
		}
	}
    //튕겨나간 별동별 개수
	cout << K - ans;
}