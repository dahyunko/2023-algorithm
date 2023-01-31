#include <iostream>
#include <string>

using namespace std;

int main() {   
    //시간 초과
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int dn, qn;//data, 질의 개수
	int data;
	int S[100001]={};//합배열
	int a,b;//질의

	//입력
	cin >> dn >> qn;
	for (int i = 1; i <= dn; i++) {
		cin >> data;
		S[i] = S[i - 1] + data;
	}
	for (int i = 1; i <= qn; i++) {
		cin >> a >> b;
        cout<< S[b] - S[a - 1]<<'\n';
	}
}