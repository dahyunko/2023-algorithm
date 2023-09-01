#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
map<int, int>m;
struct info{
    int stage;
    double num;
};

bool cmp(info a, info b){
    if(a.num == b.num) return a.stage < b.stage;
    return a.num > b.num;
}

vector<int> solution(int N, vector<int> stages) {
    int M = stages.size();
    int temp = M;
    vector<info>A;
    
    for(int i=0;i<M;i++) m[stages[i]]++;
    for(int i=1;i<=N;i++){
        if(temp == 0 && m[i] == 0 ){
            A.push_back({i, 0});
            continue;
        }
        double res = (double)m[i] / temp;
        A.push_back({i, res});
        temp -= m[i];   
    }
    sort(A.begin(), A.end(), cmp);
    
    vector<int> answer;
    for(int i=0;i<A.size();i++) answer.push_back(A[i].stage);
    return answer;
}