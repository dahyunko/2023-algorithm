/*017- 내림차순으로 자릿수 정렬하기*/
//선택정렬 O(n^2)시간소요
#include <iostream>
#include <vector>

using namespace std;

void swap(int *a, int *b) {
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

int main() {
	string array;

	cin >> array;

	//내림차순 정렬
	for (int i = 0; i < array.size()-1; i++) {
		for (int j = i+1; j < array.size(); j++) {
			if (array[i]< array[j]) {
				swap(array[i], array[j]);
			}
		}
	}

	cout << array << '\n';
}