import java.io.*;
import java.util.*;

class Solution {
    public int[] solution(int[] sequence, int k) {
        int[] answer = new int[2];
        Queue<Integer> queue = new LinkedList<>();
        
        int N = sequence.length;
        int start, end, length = N+1;
        int sum, cnt;
        
        start = end = 0;
        sum = cnt = 0;
        
        for(int i=0;i<N;i++) {
            while(sum + sequence[i] > k) {
                if(queue.isEmpty()) break;
                int v = queue.poll();
                sum -= sequence[v];
                cnt--;
            }
            
            queue.add(i);
            sum += sequence[i];
            cnt++;
            
            if(sum == k) {
                if(cnt >= length) continue;
                length = cnt;
                start = queue.peek();
                end = i;
            }
        }
        
        answer[0] = start;
        answer[1] = end;
        
        return answer;
    }
}