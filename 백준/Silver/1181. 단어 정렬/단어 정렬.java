import java.util.Arrays;
import java.util.Scanner;
import java.util.Comparator;

public class Main {
	//StringBuilder: 시간 단축 해줌 string의 6초 -> 0초 단축
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		String word[] = new String[N];
		
		for(int t = 0;t<N;t++) {
			word[t] = sc.next();
		}
			
		Arrays.sort(word, (e1, e2)->{
			if(e1.length() == e2.length() ) {
				return e1.compareTo(e2);
			}
			else return e1.length() -e2.length(); 
		});
		
		StringBuilder sb = new StringBuilder();
		sb.append(word[0]+'\n');
		for(int i=1;i<N;i++) {
			//중복제거
			if(!word[i].equals(word[i-1])) sb.append(word[i]+'\n');
		} 
		
		System.out.println(sb);
		sc.close();
	}
}