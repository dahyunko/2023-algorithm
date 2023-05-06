/*1744*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

int main() {
	int N, cnt_zero =0, sum=0;
	cin >> N;

	priority_queue<int, vector<int>, less<int>>p_pq;
	priority_queue<int, vector<int>, greater<int>>m_pq;

	for (int i = 0; i < N; i++) {
		int v;
		cin >> v;
		
		if (v == 0) cnt_zero++;
		else if (v == 1)sum++;
		else if (v > 1) p_pq.push(v);
		else m_pq.push(v);
	}

	while (p_pq.size() > 1) {
		int a = p_pq.top();
		p_pq.pop();
		int b = p_pq.top();
		p_pq.pop();

		sum += a * b;
	}
	if (!p_pq.empty()) { 
		sum += p_pq.top(); 
		p_pq.pop();
	}

	while (m_pq.size() > 1) {
		int a = m_pq.top();
		m_pq.pop();
		int b = m_pq.top();
		m_pq.pop();

		sum += a * b;
	}
	if (!m_pq.empty()) {
		if (cnt_zero > 0) m_pq.pop();
		else {
			sum += m_pq.top();
			m_pq.pop();
		}
	}
	
	cout << sum;
}