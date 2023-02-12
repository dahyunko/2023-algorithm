/*1924- 2007년*/
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int main() {
	int N, M;

	cin >> N >> M;

	int day = M, mon = 1;
	while (N > mon) {
		if (mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12) {
			day += 31;
		}
		else if (mon == 2) day += 28;
		else day += 30;
		mon++;
	}

	int result = day % 7;
	switch (result)
	{
	case 1: cout << "MON";
		break;
	case 2: cout << "TUE";
		break;
	case 3: cout << "WED";
		break;
	case 4: cout << "THU";
		break;
	case 5: cout << "FRI";
		break;
	case 6: cout << "SAT";
		break;
	case 0: cout << "SUN";
		break;
	default:
		break;
	}

}