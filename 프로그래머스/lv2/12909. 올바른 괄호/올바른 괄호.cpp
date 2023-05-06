#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    stack<char> stack;
    
    for(int i=0;i<s.length();i++){
        if(s[i] =='(') stack.push('(');
        else if(s[i] == ')'){
            if(!stack.empty()){
                stack.pop();
            }else {
                answer = false;
                break;
            }
        }
    }
    if(!stack.empty()) answer = false;    
    
    return answer;
}