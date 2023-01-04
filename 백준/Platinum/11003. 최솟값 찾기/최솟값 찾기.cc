/*010- 최소값 찾기//슬라이딩 이용*/
/*
* deque: 배열 기반 컨테이너
* 
* 여러개의 메모리 블록으로 나누어져 있음
* push_front(), pop_front(), push_back(), pop_back()
* insert, erase도 가능 (중간에 원소 추가)
* ex) D.insert(D.begin()+2, 100);//2번째원소에 100 추가
* front(), back(), at(숫자)
* 
* vector: 스택구조 원소 앞에서 추가하는 것이 불가능한 스택 구조, 
원소를 뒤쪽으로 밀어야함
*/

#include <iostream>
#include <deque>
using namespace std;
typedef pair<int, int> Node;//노드 선언

int main() {
	//시간 초과
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L;
	int now;//들어오는 수
	deque <Node> deque;//first: 할당 수, second는 index

	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		cin >> now;

		//들어오는 값보다 큰 값은 삭제
		while (deque.size() && deque.back().first > now) {
			deque.pop_back();
		}
		deque.push_back(Node(now, i));//마지막에 노드와 인덱스 추가

		//deque의 index가 해당 범위에서 벗어나면 삭제
		if (deque.front().second <= i - L) {
			deque.pop_front();
		}

		cout << deque.front().first << '\n';
	}
}

/* O(nlogn)시간 소요로 인한 시간 초과
#include <vector>
#include <algorithm>

int main() {
	//시간 초과
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L;
	int min= 1000000000;

	cin >> N >> L;

	vector<int> A(N, 0);
	vector<int> D(L, NULL);//i-L+1~ i까지 L개 저장

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int k = 0;
	for (int i = 0; i < N; i++) {
		if (i < L) {
			D[k] = A[i];
			k++;
			if (min < A[i]) {
				min = A[i];
			}
		}
		else {
			D.erase(D.begin());//맨앞 원소 삭제
			// v.erase(v.end() - 1);//맨 끝 원소 삭제
			D.push_back(A[i]);//뒤에 추가
			
			//최소값 구하기
			min = *min_element(D.begin(), D.end());//시간 초과 예상 O(n)
		}

		cout << min<<' ';
	}
}
*/