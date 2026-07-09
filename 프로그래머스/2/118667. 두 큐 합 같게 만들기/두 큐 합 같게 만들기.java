import java.io.*;
import java.util.*;

class Solution {
    static int calCnt (int S, int E, int mid) {
        if(mid == E) {return S - 1;}
        else if(mid < E){
            if(S <= mid) {return S - 1 + E - mid;}
            else {return S + E - mid - 1;}
        }
        else {return S + E + mid - 1;}
    }
    
    public int solution(int[] queue1, int[] queue2) {
        int answer = Integer.MAX_VALUE;
        int[] array = new int[600002];
        
        if(queue1.length != queue2.length) return -1;
        
        int mid = queue1.length;
        int N = mid * 2 + 1;
        int S, E;
        long sum, half;
        int cnt = 0;
        
        sum = half = 0L;
        S = E = 1;
        
        for(int i=1;i<=mid;i++) {
            array[i] = queue1[i-1];
            array[mid+i] = queue2[i-1];
            
            sum += queue1[i-1] + queue2[i-1];
        }
        
        half = sum / 2;
        sum = 0;
        
        Queue<Integer> q = new LinkedList<>();
        
        for(int i=1;i<N;i++) {
            q.add(i);
            sum += array[i];
            
             while(!q.isEmpty() && sum > half) {
                int v = q.poll();
                sum -= array[v];
            }
            
            if(sum == half){
                S = q.poll();
                E = i;
                sum -= array[S];
                
                answer = Math.min(answer, calCnt(S, E, mid));
            }
        }
        
        if(answer == Integer.MAX_VALUE) return -1;

        return answer;
    }
}