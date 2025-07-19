import java.io.*;
import java.util.*;

class Solution {
    
    static class Loc {
        int x, y;
        Loc(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
    
    static Loc findLoc(int num, int w){
        int x, y;
        int temp = num%w;
        
        x = num/w;
        if(temp > 0) x += 1;
        
        if(x % 2 == 1) {
            if(temp == 0) y = w;
            else y = temp;            
        }
        else {
            if(temp == 0) y = 1;
            else y = w - temp + 1;            
        }
        
        return new Loc(x, y);
    }
    
    public int solution(int n, int w, int num) {
        int answer = 0;
        /*
        * idea
        * 나눈 값이 짝수면 오 -> 왼, 홀수 면 왼 -> 오
        */
        
        // 위치
        Loc numL = findLoc(num, w);
        Loc nL = findLoc(n, w);
        
        answer = nL.x - numL.x;
        
        if(nL.x % 2 == numL.x % 2){
            if(nL.x % 2 == 0 && nL.y <= numL.y) answer++;
            else if(nL.x % 2 == 1 && nL.y >= numL.y) answer++;
        }
        else {
            if(nL.x % 2 == 0 && nL.y <= numL.y) answer++;
            else if(nL.x % 2 == 1 && nL.y >= numL.y) answer++;
        }
        
        
        return answer;
    }
}