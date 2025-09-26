import java.util.*;

class Solution {
    static int N, des;
    static List<Integer>[] graph;
    static int[] cost;
    
    static class INFO{
        int n, w;
        
        INFO(int n, int w){
            this.n = n;
            this.w = w;
        }
    }
    
    static int getDis(int s){
        boolean[] visited = new boolean[N];
        int result = -1;
        
        Queue<INFO> q = new LinkedList<>();
        q.add(new INFO(s, 0));
        
        while(!q.isEmpty()){
            INFO v = q.poll();
            
            if(visited[v.n]) continue;
            visited[v.n] = true;
            cost[v.n] = v.w;
            
            for(int next:graph[v.n]){
                if(visited[next]) continue;
                q.add(new INFO(next, v.w + 1));
            }
        }
        
        return result;
    }
    
    public int[] solution(int n, int[][] roads, int[] sources, int destination) {
        int[] answer = new int[sources.length];
        
        N = n;
        graph = new ArrayList[N];
        cost = new int[N];
        for(int i=0;i<N;i++) {
            graph[i] = new ArrayList<>();
            cost[i] = Integer.MAX_VALUE;
        }
        // init
        for(int i=0;i<roads.length;i++){
            int a = roads[i][0]-1;
            int b = roads[i][1]-1;
            
            graph[a].add(b);
            graph[b].add(a);
        }
        
        getDis(destination-1);
        for(int i=0;i<sources.length;i++){
            answer[i] = (cost[sources[i]-1] == Integer.MAX_VALUE) ? -1 : cost[sources[i]-1];
        }
        
        return answer;
    }
}