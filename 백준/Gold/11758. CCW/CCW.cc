/*097(11758)- CCW*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    long x1, y1, x2, y2, x3, y3;
    long result = 0;

    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    result = (x1 * y2 + x2 * y3 + x3 * y1) - (x1 * y3 + x3 * y2 + x2 * y1);

    //시계 방향
    if (result < 0) cout << -1;
    //반시계 방향
    if (result > 0) cout << 1;
    //일직선
    if (result == 0) cout << 0;
}