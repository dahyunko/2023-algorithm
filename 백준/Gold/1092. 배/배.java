import java.io.*;
import java.util.*;
public class Main {
    static int N,M, day = 0;

    public static void main(String[] str) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        List<Integer> port = new ArrayList<>();

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0;i<N;i++){
            port.add(Integer.parseInt(st.nextToken()));
        }
        Collections.sort(port, (o1, o2) -> o2-o1);

        M = Integer.parseInt(br.readLine());
        List<Integer> box = new ArrayList<>();
        boolean visited[] = new boolean[M+1];

        st = new StringTokenizer(br.readLine());
        for(int i=0;i<M;i++){
            box.add(Integer.parseInt(st.nextToken()));
        }
        Collections.sort(box, (o1, o2) -> o2-o1);

        if(box.get(0) > port.get(0)) {
            System.out.println(-1);
            return;
        }

        int idx = 0;
        while(idx < M){
            day++;
            int first = -1;
            // System.out.println("========" + day + "========");
            for(int i=0;i<N;i++){
                if(idx >= M) break;

                if(visited[idx]) {
                    i--;
                    idx++;
                    continue;
                }
                if(box.get(idx) > port.get(i)){
                    if(first == -1) first = idx;
                    i--;
                }else{
//                    System.out.println(box.get(idx));
                    visited[idx] = true;
                }
                idx++;
            }
            if(first != -1) idx = first;
        }

        System.out.println(day);
    }
}
/*
3
10 7 4
9
9 9 8 7 6 6 5 5 2
* */