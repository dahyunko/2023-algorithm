import java.io.*;
import java.util.*;
import java.lang.*;

public class Solution {
	static int T, N;
	static double E;
	static List<Pair> Nodes = new ArrayList<>();
	static List<List<Edge>> graph = new ArrayList<>();
	static PriorityQueue<Edge> pq = new PriorityQueue<>();
	static boolean[] visited;
	
	static class Pair {
		double x, y;

		Pair(double x, double y) {
			this.x = x;
			this.y = y;
		}
	}

	static class Edge implements Comparable<Edge>{
		int v;
		double weight;

		Edge(int next, double weight) {
			this.v = next;
			this.weight = weight;
		}
		
		@Override
		public int compareTo(Edge o) {
			return Double.compare(this.weight, o.weight);
		}
		@Override
		public String toString() {
			return "[" + this.v + ", " + this.weight + "]";
		}
		
	}

	static void makeEdges(int a, int b) {
		double temp;
		temp = (Math.pow(Math.abs(Nodes.get(a).x - Nodes.get(b).x), 2)
				+ Math.pow(Math.abs(Nodes.get(a).y - Nodes.get(b).y), 2)) * E;

		graph.get(a).add(new Edge(b, temp));
		graph.get(b).add(new Edge(a, temp));
	}
	
	static void printGraph() {
		for(int i=0;i<N;i++) {
			for(Edge now : graph.get(i)) {
				System.out.print(now.toString());
			}
			System.out.println();
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;

		// 프림(Elog(V) -> E 엣지, V 노드)
		T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			N = Integer.parseInt(br.readLine());
			visited = new boolean[N];
			graph.clear();
			Nodes.clear();
			pq.clear();

			double a, b;
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N; i++) {

				a = Double.parseDouble(st.nextToken());

				Nodes.add(new Pair(a, 0));
				graph.add(new ArrayList<Edge>());
			}
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N; i++) {
				b = Double.parseDouble(st.nextToken());

				Nodes.get(i).y = b;
			}
			E = Double.parseDouble(br.readLine());

			// 간선 만들기
			for (int i = 0; i < N; i++) {
				for (int j = i + 1; j < N; j++) {
					makeEdges(i, j);
				}
			}
			
			//printGraph();
			
			int cnt = 0;
			double total = 0;
			pq.add(new Edge(0, 0));
			
			while(!pq.isEmpty()) {
				Edge now = pq.poll();
			
				if(visited[now.v]) continue;
				visited[now.v] = true;
				cnt++;
				total += now.weight; 
				if(cnt == N) break;
				
				for(Edge next: graph.get(now.v)) {
					if(!visited[next.v]) {
						pq.add(next);
					}
				}
			}

			sb.append("#").append(t).append(" ").append(Math.round(total)).append('\n');
		}
		System.out.println(sb);
	}
}