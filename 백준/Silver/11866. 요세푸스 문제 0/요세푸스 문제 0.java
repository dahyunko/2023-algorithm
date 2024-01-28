import java.io.*;
import java.util.*;

public class Main {
	// 1 2  4 5 7
	// 3 6 2 7 5 1 4
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		sb.append("<");
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		List<String> list = new LinkedList<>();
		
		for(int i=1;i<=N;i++) list.add(Integer.toString(i));
	
		int i=M-1;
		while(!list.isEmpty()) {
			if(list.size() <= i) {
				while(i >= list.size()) {
					i -= list.size();	
				}
			}
			sb.append(list.remove(i));
			i+=M-1;
			if(!list.isEmpty()) sb.append(", ");
		}
		
		sb.append(">");
		System.out.println(sb);
	}

}