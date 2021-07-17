import java.util.*;
import java.io.*;

public class gym {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("gymnastics.in"));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int K = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        int[][] ranks = new int[K][n];
        for(int i = 0; i < K; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; j++){
                ranks[i][Integer.parseInt(st.nextToken())-1] = j;
            }
        }
        int answer = 0;

        for(int i = 0; i < n;i++){
            for(int j = 0; j < n; j++){
                int greater = 0;
                for(int k = 0; k < ranks.length;k++){
                    if(ranks[k][i] > ranks[k][j]){
                        greater++;
                    }
                }
                if(greater == K){
                    answer++;
                }
            }
        }

        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("gymnastics.out")));
        pw.println(answer);
        pw.close();

    }
}
