import java.io.*;
import java.util.*;

public class Main {
    static int N, T;
    static List<Info> menu = new ArrayList<>();

    static class Info implements Comparable<Info>{
        int a,b,sub;

        Info(int a, int b, int sub){
            this.a = a;
            this.b = b;
            this.sub = sub;
        }

        @Override
        public int compareTo(Info o){
            return o.sub - this.sub;
        }

        public String toString(){
            return "[" + a + " , " + b + "]";
        }

    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());

        for(int i=0;i<N;i++){
            int A,B;
            st = new StringTokenizer(br.readLine());
            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());

            menu.add(new Info(A, B, A - B));
        }

        Collections.sort(menu);

        int idx = 0;
        int ans = 0;
        while(true){
            // 1000원이 더 비싸지는 순간 그다음 부터는 1000만 더함
            if(menu.get(idx).a < menu.get(idx).b) {
                break;
            }

            // 5000원 짜리를 먹어도 모든 날을 다 먹을 수 있는지
            if((T - 5000)/1000 < (N-idx-1)){
                break;
            }
            T -= 5000;
            ans += menu.get(idx).a;
            idx++;
        }

        while(idx<N){ // 매일 1000원치 먹어야 함 
            ans += menu.get(idx).b;
            idx++;
        }

        System.out.println(ans);
    }
}