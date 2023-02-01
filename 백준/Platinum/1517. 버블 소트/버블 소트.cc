/*1517- 버블 소트*/
//합병 정렬 이용
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

static long cnt = 0;
static int N;
static int list[500001];

void merge(int* A, int start, int end, int mid) {

	int i = start, j = mid + 1;
	int k = start;
	while (i <= mid && j <= end) {
		if (A[i] <= A[j]) {
			list[k++] = A[i++];
		}
		else { 
			list[k++] = A[j++]; 
			cnt = cnt + j - k;//swap 몇번 되는 지 계산
		}
	}

	if (i > mid) {
		for (int t = j; t <= end; t++) {
			list[k++] = A[t];
		}
	}
	else {
		for (int t = i; t <= mid; t++) {
			list[k++] = A[t];
		}
	}

	for (int t = start; t <= end; t++) {
		A[t] = list[t];
	}
}

void merge_sort(int *A, int start, int end) {
	if (start >= end)return;
	int mid = (start + end) / 2;
	merge_sort(A, start, mid);
	merge_sort(A, mid+1, end);
	merge(A, start, end, mid);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int A[500001];

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	merge_sort(A, 0, N - 1);
	cout << cnt;
}
