import java.util.Arrays;
import java.util.Scanner;
import java.util.HashMap;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		
		int arr[] = new int[N];
		int sort_arr[] = new int[N];
		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		
		for(int i=0;i<N;i++) {
			sort_arr[i] = arr[i] = sc.nextInt();
		}
		Arrays.sort(sort_arr);
		
		int rank = 0;
		for(int v : sort_arr) {
			if(!map.containsKey(v)) {
				map.put(v,rank++);
			}
		}
		
		StringBuilder sb = new StringBuilder();
		
		for(int key : arr) {
			sb.append(map.get(key)+" ");
		}
		System.out.print(sb);
		sc.close();
	}
}