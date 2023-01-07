#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> list(1000001);//임시배열

void Merge(vector<int>& A, int start, int mid, int end) {
	int i = start, j = mid + 1;
	int k = start;

	while (i <= mid && j <= end) {
		if (A[i] > A[j]) {
			list[k++] = A[j++];
		}
		else {
			list[k++] = A[i++];
		}
	}

	//남은것 삽입
	while (j <= end) list[k++] = A[j++];
	while (i<= mid) list[k++] = A[i++];

	for (int t = start; t <= end; t++) {
		A[t] = list[t];
	}
}

void MergeSort(vector<int>& A, int start, int end) {
	if (start >= end) return;
	
	int mid = (start + end) / 2;
	MergeSort(A, start, mid);
	MergeSort(A, mid+1, end);
	Merge(A, start, mid, end);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N ;
	vector<int> A(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	//퀵 정렬
	MergeSort(A, 0, N - 1);

	for (int i = 0; i < N; i++) {
		cout << A[i]<<'\n';
	}
}