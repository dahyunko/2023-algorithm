import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n,c = 0;
		
		n = sc.nextInt();
		
		for(int t=0;t<n;t++) {
			String s;
			s = sc.next();
			int arr[] = new int[28];
			int flag = 0;
			
			char temp = s.toCharArray()[0];
			arr[temp-'a']++;
			
			for(int i=1;i<s.length();i++) {
				if(temp == s.toCharArray()[i]) continue;
				
				//다를 때
				temp = s.toCharArray()[i];
				if(arr[temp-'a'] > 0) {
					flag = 1;
					break;
				}
				else if(arr[temp-'a'] == 0) arr[temp-'a']++;
			}
			
			if(flag == 0) c++;
		}
		
		System.out.println(c);
		sc.close();
	}
}