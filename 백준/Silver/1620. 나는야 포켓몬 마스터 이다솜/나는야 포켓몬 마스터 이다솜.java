import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		Map<Integer, String> map = new HashMap<Integer, String>();
		Map<String, Integer> map2 = new HashMap<String, Integer>();
		
		// 이름 입력 받음
		for (int i = 0; i < N; i++) {
			String now = br.readLine();
			map.put(i+1, now);
			map2.put(now, i+1);
		}
		
		// 맞춰야하는 이름
		for (int i = 0; i < M; i++) {
			String now = br.readLine();
			if(now.charAt(0) >= '1' && now.charAt(0) <= '9') {
				// 이름 반환
				sb.append(map.get(Integer.parseInt(now))+ "\n");
			}
			else { // 번호 반환
				sb.append(map2.get(now)+ "\n");
			}
		}
		
		System.out.println(sb);
	}
}