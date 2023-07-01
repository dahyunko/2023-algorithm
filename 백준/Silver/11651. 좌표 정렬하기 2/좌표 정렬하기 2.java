import java.util.Arrays;
import java.util.Scanner;
import java.util.Comparator;

public class Main {
	//StringBuilder: 시간 단축 해줌 string의 6초 -> 0초 단축
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int arr[][] = new int[N][2];
		
		for(int t=0;t<N;t++) {
			arr[t][1] = sc.nextInt();//x
			arr[t][0] = sc.nextInt();//y
		}
		
		Arrays.sort(arr, (e1, e2)->{
			if(e1[0] == e2[0]) {
				return e1[1] - e2[1];
			}else {
				return e1[0] - e2[0];
			}
		});
		
		//comparator
		/*
        Arrays.sort(arr,new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				if(o1[1] == o2[1]) return o1[0] - o1[0];
				else return o1[1] - o1[1];
			}
		});*/
		
		StringBuilder sb = new StringBuilder();
		for(int i=0;i<N;i++) sb.append(arr[i][1] + " "+ arr[i][0]+'\n');
		
		System.out.println(sb);
		sc.close();
	}
}