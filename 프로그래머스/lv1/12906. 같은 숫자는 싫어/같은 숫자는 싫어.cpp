#include <vector>
#include <iostream>
#include<stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int>s;
    s.push(arr[0]);
    
    for(int i=1;i<arr.size();i++){
        int v = s.top();
        if(v == arr[i]) continue;
        else {
            answer.push_back(v);
            s.pop();
            s.push(arr[i]);
        }
    }
    if(!s.empty())answer.push_back(s.top());
    
    return answer;
}