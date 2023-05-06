#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, string> info;

vector<string>split(string input, char delimiter){
    vector<string>result;
    stringstream mystream(input);
    string splitdata;
    
    while(getline(mystream, splitdata, delimiter)){
        result.push_back(splitdata);
    }
    return result;
}

string solution(string s) {
    string answer = "";
    
    priority_queue<info, vector<info>, greater<info>>pq;
    vector<string>A = split(s, ' ');
    for(int i=0;i<A.size();i++){
        int num;
        num = stoi(A[i]);//'-' 인식 함
        
        pq.push(info(num, A[i]));
    }
    
    for(int i=0;i<pq.top().second.length();i++) answer.push_back(pq.top().second[i]);   
    answer.push_back(' ');
    while(pq.size()>1) pq.pop();
    for(int i=0;i<pq.top().second.length();i++) answer.push_back(pq.top().second[i]);   
    
    return answer;
}