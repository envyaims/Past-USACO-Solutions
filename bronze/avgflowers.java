import java.util.*;
import java.io.*;
// http://usaco.org/index.php?page=viewproblem2&cpid=1060
public class avgflowers {
    public static void main(String[] args) throws Exception {
        // add all the flowers in an array
        // loop through every subarray
        // run another loop that adds every element of the subarray up
        // divide it by the amount in the subarray
        // run another loop through the subarray to see if the average is one of the flowers
        // add one to the total count
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] flowers = new int[n];
        for(int i = 0; i < n; i++){
            flowers[i] = Integer.parseInt(st.nextToken());
        }
        int output = 0;
        for(int i = 0; i < n; i++){ // subarray
            for(int j=i+1; j < n+1; j++){
                int[] subarray = new int[j-i];
                for(int k = i; k < j; k++){
                    subarray[k-i] = flowers[k];
                }
                int total = 0;
                for(int k = 0; k < j-i; k++){
                    total += subarray[k];
                }
                if(total % (j-i) == 0){
                    total = total/(j-i);
                }
                else{
                    continue;
                }
                for(int k = 0; k < j-i; k++){
                    if(total == subarray[k]){
                        output += 1;
                        break;
                    }
                }

            }
        }
        pw.println(output);
        pw.close();


    }
}
