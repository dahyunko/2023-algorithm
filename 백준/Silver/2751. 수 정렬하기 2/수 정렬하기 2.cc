/*020- 수 정렬하기 2
병합 정렬: O(nlongn)
*/
#include <iostream>
#include <vector>

using namespace std;
vector<int> list(1000001);//임시 배열

void merge(vector<int>& A, int left, int mid, int right) {

	int i = left, j = mid+1;
	int k = left;//list 순서 정해줌

	//분할된 list 합병
	while (j <= right && i<=mid) {
		if (A[i] < A[j]) {
			list[k++] = A[i++];
		}
		else {
			list[k++] = A[j++];
		}
	}

	//남아있는 값 저장
	if (i > mid) {
		for (int t = j; t <= right; t++) list[k++] = A[t];
	}
	else {
		for (int t = i; t <= mid; t++) list[k++] = A[t];
	}

	//list -> A로 이동
	for (int t = left; t <= right; t++) {
		A[t] = list[t];
	}
}

void merge_sort(vector<int> &A, int left, int right) {
	if (left >= right) return;

	//분할
	int mid = (left + right) / 2;
	//정복(conquer)
	merge_sort(A, left, mid);
	merge_sort(A, mid+1, right);
	//병합
	merge(A, left, mid, right);
}

int main() {
	//시간 초과
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;
	vector<int> A(N, 0);
	vector<int> list(N, 0);//임시 배열

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	merge_sort(A,0, N-1);

	for (int i = 0; i < N; i++) {
		cout << A[i]<<'\n';
	}
}