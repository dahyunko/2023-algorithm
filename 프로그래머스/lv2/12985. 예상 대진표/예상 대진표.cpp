#include <iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(int n, int a, int b)
{
//1 2 3 4 5 6 7 8
//1 2 3 4
//1 2
    n = 0;
    while(a != b){
        if(a%2 == 0) a = a/2;
        else a= a/2+1;
        if(b%2 == 0) b = b/2;
        else b = b/2+1;
        n++;
    }
    
    return n;
}