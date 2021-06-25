import java.util.*;
import java.io.*;

class social2{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("socdist2.in"));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[][] cows = new int[n][2];
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            cows[i][0] = Integer.parseInt(st.nextToken());
            cows[i][1] = Integer.parseInt(st.nextToken());
        }

        int radius = 1000001;
        for(int i = 0; i < cows.length;i++){
            if(cows[i][1] == 0){
                for(int j = 0; j < cows.length; j++){
                    int distance = Math.abs(cows[i][0] - cows[j][0]);
                    if(j != i && distance < radius && cows[j][1] == 1){
                        radius = distance;
                    }
                }
            }
        }

        boolean[] isinfected = new boolean[1000001];
        int[] cowsorder = new int[n];
        for(int i = 0; i < n;i++){
            if(cows[i][1] == 1){
                isinfected[cows[i][0]] = true;
            }
            cowsorder[i] = cows[i][0];
        }
        Arrays.sort(cowsorder);
        int infections = 0;
        for(int i = 0; i < n-1; i++){
            if(cowsorder[i+1]-radius < cowsorder[i]){
                infections++;
            }
        }
        int infectedcows = 0;
        for(int i = 0; i < n; i++){
            if(cows[i][1] == 1){
                infectedcows++;
            }
        }
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(new File("socdist2.out"))));
        pw.print(infectedcows - infections);
        pw.close();

    }

}
