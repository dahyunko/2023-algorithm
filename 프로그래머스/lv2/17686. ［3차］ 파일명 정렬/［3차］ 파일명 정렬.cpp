#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cctype>

using namespace std;
struct info{
    string head, number, tail, all;
    int num, idx;
};

bool cmp(info a, info b){
    if(a.head == b.head){
        if(a.num == b.num) return a.idx < b.idx;
        return a.num < b.num;
    }
    return a.head < b.head;
}

vector<string> solution(vector<string> files) {
    int N = files.size();
    vector<info>A(N);

    for(int i=0;i<files.size();i++){
        A[i].all = files[i];
        A[i].idx = i;
        int flag =0;
        for(int j=0;j<files[i].length();j++){
            char c = files[i][j];
            if(flag == 0){
                if(c >= '0' && c<='9') flag = 1;
                else A[i].head += tolower(c);
            }
            if(flag == 1){
                if(c >= '0' && c<='9') {
                    if(A[i].number.length() == 5) flag = 2;
                    else A[i].number += c;
                }
                else flag = 2;
            }
            if(flag == 2) A[i].tail += c;
        }
        A[i].num = stoi(A[i].number);
        //cout<< A[i].all<<'/'<< A[i].head<<'/'<< A[i].num<<'/'<< A[i].tail<<'/'<<'\n';
    }

    sort(A.begin(), A.end(), cmp);

    vector<string> answer;
    for(int i=0;i<A.size();i++) answer.push_back(A[i].all);    
    return answer;
}