import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		String sen = sc.next();
		int c = 0;
		
		int i=0;
		while(i<sen.length()) {
			char now = sen.charAt(i);
			
			if(now == 'c') {
				if(i+1 < sen.length()) {
					char next = sen.charAt(++i);
					
					if(next == '=' || next == '-') c++;
					else { c++; i--;}
				}
				else c++;
			}
			else if(now == 'd') {
				if(i+1 < sen.length()){
					char next = sen.charAt(++i);
					
					if(next == '-') c++;
					else if(next == 'z') {
						if(i+1 < sen.length()){
							if(sen.charAt(++i) == '=') c++;
							else {c+=2; i--;}
						}else c+=2;
					}
					else {c++; i--;}
				}
				else c++;
			}
			else if(now =='l' || now =='n' ) {
				if(i+1 < sen.length()) {
					char next = sen.charAt(++i);
					
					if(next == 'j') c++;
					else { c++; i--;}
				}
				else c++;
			}
			else if(now =='s'|| now =='z') {
				if(i+1 < sen.length()) {
					char next = sen.charAt(++i);
					
					if(next == '=') c++;
					else { c++; i--;}
				}
				else c++;
			}
			else if(now >='a' && now <= 'z') c++;
			
			i++;
		}
		
		System.out.println(c);
		sc.close();
	}
}