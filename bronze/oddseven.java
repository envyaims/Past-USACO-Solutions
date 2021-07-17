import java.util.*;
import java.io.*;

public class oddseven {
    public static void main(String[] args) throws Exception {
      // odd + even = odd
      // even + even = even
      // odd + odd = even
      // if an equation has a odd number of odds, the result is odd
      // otherwise it is even
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
      StringTokenizer st = new StringTokenizer(br.readLine());
      int n = Integer.parseInt(st.nextToken());
      st = new StringTokenizer(br.readLine());
      int[] cows = new int[n];
      int oddcount = 0;
      int evencount = 0;
      for(int i = 0; i < n; i++){
        cows[i] = Integer.parseInt(st.nextToken());
        if(cows[i] % 2 == 0){
          evencount++;
        }
        else{
          oddcount++;
        }
      }
      // loop through every one member group first. i.e: 10, 3
      // if there is not any more evens, pair up the odds
      // if there is not enough odds, just add up the ones that can be made with even

      int output = 0;
      // pw.println(oddcount);
      // pw.println(evencount);
      if(evencount > oddcount){
        pw.println(oddcount*2+1);
      }
      else if(oddcount > evencount){
        // since the order is always even, odd, even, odd after
        // if the oddcount is 2, 5, 8, 11 (3%n==2) they can make two groups in every 3 odds. There will be two left over but they can make even
        // if the oddcount is 1, 4,7,10 (3%n==1) they can make two groups every three odds BUT there will always be a leftover
        // if the oddcount is 3,6,9 (3%n==0) they can make two groups every three odds
        // i am dividing by 3 to find the groups of three, x2 since every group of three can make two groups, and adding the leftover conditions

        output += evencount * 2;
        oddcount -= evencount;
        if(oddcount % 3 == 2){
          output += oddcount/3 * 2 +1;
        }
        else if(oddcount % 3 == 1){
          output += oddcount/3 *2 -1;

        }
        else{
          output += oddcount/3 * 2;
        }
        pw.println(output);
      }
      else{
        pw.println(evencount*2+1);
      }
    pw.close();
    }
}
