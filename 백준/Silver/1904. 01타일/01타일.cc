/*1904(01타일)*/
//피보나치 수열
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

typedef long long ll;

int main() {
	int N;
	
	cin >> N;
	vector<ll>A(N+1);

	A[1] = 1;
	A[2] = 2;
	for (int i = 3; i <= N; i++)
	{
		A[i] = (A[i - 1] + A[i - 2])%15746;
	}

	cout << A[N];
}