import java.util.*;
import java.io.*;
public class limits {
    public static void main(String[] args) throws Exception {
      // http://usaco.org/index.php?page=viewproblem2&cpid=1085
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
      StringTokenizer st = new StringTokenizer(br.readLine());
      int n = Integer.parseInt(st.nextToken());
      int[] stalls = new int[n];
      int[] cows = new int[n];
      st = new StringTokenizer(br.readLine());
      for(int i = 0; i < n; i++){
        cows[i] =Integer.parseInt(st.nextToken());
      }
      st = new StringTokenizer(br.readLine());
      for(int i = 0; i < n; i++){
        stalls[i] =Integer.parseInt(st.nextToken());
      }
      Arrays.sort(cows);
      Arrays.sort(stalls);
      int[] limits = new int[n];
      // for(int i = 0; i < n; i++){
      //   int fits = 0;
      //   for(int j = 0; j < n; j++){
      //       if(stalls[j]-cows[i] >= 0){
      //         fits++;
      //       }
      //   }
      //   limits[i] = fits;
      // }

      for(int i = n-1; i >= 0; i--){
        int fits = 0;
        int j = n-1;
        while(cows[i]<=stalls[j]){
            fits++;
            j--;
        }
        limits[i] = fits;
      }

      Arrays.sort(limits);
      long output = 1;
      int subtract = 0;
      for(int i = 0; i <n; i++){
          output *= (limits[i]-subtract);
          subtract++;
      }
      pw.print(output);
      pw.close();
    }
}
