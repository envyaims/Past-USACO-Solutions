import java.util.*;
import java.io.*;

public class acowdemia {
    public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
      StringTokenizer st = new StringTokenizer(br.readLine());
      int n = Integer.parseInt(st.nextToken());
      int l = Integer.parseInt(st.nextToken());
      int[] nums = new int[n];
      st = new StringTokenizer(br.readLine());
      for(int i = 0; i < n; i++){
          nums[i] = Integer.parseInt(st.nextToken());
      }
      Arrays.sort(nums);
      int hindex = -1;
      for(int i = n-1; i >= 0; i--){
        if(n-i > nums[i]){
          hindex = n-i-1;
          break;
        }
      }

      if(l > 0 && Arrays.binarySearch(nums,hindex) >= 0){
          hindex++;
      }
      pw.println(hindex);
      pw.close();
    }
}
