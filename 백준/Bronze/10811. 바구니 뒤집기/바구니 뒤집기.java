import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n,t;
		int Arr[] = new int[101];
		
		n = sc.nextInt();
		t = sc.nextInt();
		
		for(int i=1;i<=n;i++) Arr[i] = i;
		
		for(int i=0;i<t;i++) {
			int a, b;
			a = sc.nextInt();
			b = sc.nextInt();
			
			int arr2[] = new int[101];
			
			for(int j = a;j<=b;j++) arr2[j] = Arr[j];
			
			int p = b;
			for(int j = a;j<=b;j++) {
				Arr[j] = arr2[p--];
			}
		}
		
		for(int i=1;i<=n;i++) {
			System.out.print(Arr[i]+" ");
		}
	}
}
