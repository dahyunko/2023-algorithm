/*1517*/
#include <iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

static long cnt = 0, N;

void merge(int* A, int left, int right, int mid) {
	int list[500001];
	int i = left, j = mid + 1;
	int k = left;
	while (i <= mid && j <= right) {
		if (A[i] <= A[j]) list[k++] = A[i++];
		else { 
			list[k++] = A[j++]; 
			cnt += j - k;//swap된 만큼
		}
	}

	if (i > mid) {
		for (int t = j; t <= right; t++) list[k++] = A[t];
	}
	else {
		for (int t = i; t <= mid; t++) list[k++] = A[t];
	}

	for (int t = left; t <= right; t++) A[t] = list[t];
}

void merge_sort(int* A, int left, int right) {
	if (left >= right) return;
	int mid = (left + right) / 2;
	merge_sort(A, left, mid);
	merge_sort(A, mid + 1, right);

	merge(A, left, right, mid);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int A[500001];
	for (int i = 0; i < N; i++) cin >> A[i];

	//합병 정렬
	merge_sort(A, 0, N - 1);

	cout << cnt;
}