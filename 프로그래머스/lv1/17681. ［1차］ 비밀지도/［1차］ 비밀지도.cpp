#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
char board[17][17];

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    for(int i=0;i<arr1.size();i++){
        vector<int> A(n, 0);
        int idx = 0;
        while(arr1[i] != 0){
            A[idx++] = arr1[i]%2;
            arr1[i] /= 2;
        }
        reverse(A.begin(), A.end());
        for(int j=0;j<A.size();j++){
            if(A[j] == 0) board[i][j] = ' ';
            else board[i][j] = '#';
        }
    }
    for(int i=0;i<arr2.size();i++){
        vector<int> A(n, 0);
        int idx = 0;
        while(arr2[i] != 0){
            A[idx++] = arr2[i]%2;
            arr2[i] /= 2;
        }
        reverse(A.begin(), A.end());
        for(int j=0;j< n ;j++){
            if(A[j] == 0 && board[i][j] == ' ') continue;
            else board[i][j] = '#';
        }
    }
    
    vector<string> answer(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) answer[i].push_back(board[i][j]);
    }
    
    return answer;
}