import java.util.*;

class Solution {
    public int solution(String s) {
        int answer = 0;
        
        int idx = 0;
        int N = s.length();
        
        while(idx<N){
            Stack<Character> stack = new Stack<>();
            boolean isWrong = false;
            
            for(int i=0;i<N;i++){
                char now = s.charAt((idx + i) % N);
                
                if(now == '{' || now == '[' || now == '(') {
                    stack.push(now);
                    continue;
                }
                if(stack.isEmpty()) {
                    isWrong = true;
                    break;
                }
                
                if((now == '}' && stack.peek() == '{') 
                   || (now == ']' && stack.peek() == '[')
                   || (now == ')' && stack.peek() == '(')){
                    stack.pop();   
                }
                else {
                    isWrong = true;
                    break;
                }
                
            }
            idx++;
            if(!isWrong && stack.isEmpty()) answer++;
        }
        return answer;
    }
}