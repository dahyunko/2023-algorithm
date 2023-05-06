#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    int left =0, right= A.size()-1, sum =0;
    
    while(A.size() && B.size()){
        right= A.size()-1;
        if(A[right] > B[right]){
            sum += A[right] * B[left];
            A.erase(A.begin()+right);
            B.erase(B.begin());
        }else{
            sum += B[right] * A[left];
            A.erase(A.begin());
            B.erase(B.begin()+right);
        }
    }
    
    answer = sum;
    return answer;
}