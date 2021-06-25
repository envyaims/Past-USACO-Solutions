import java.util.*;
import java.io.*;
public class lemonade {
    public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new FileReader("lemonade.in"));
      PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("lemonade.out")));
      StringTokenizer st = new StringTokenizer(br.readLine());
      int n = Integer.parseInt(st.nextToken());
      int[] cows = new int[n];
      st = new StringTokenizer(br.readLine());
      for(int i = 0; i < n; i++){
        cows[i] = Integer.parseInt(st.nextToken());
      }
      Arrays.sort(cows);
      int inline = 0;
      int biggestindex = n-1;
      for(int i = 0; i < n; i++){ // loop through the smallest cows
        if(i == biggestindex){ // if i is the index of the cow that are already on the line
          break;
        }
          for(int j = 0; j < cows[i]+1; j++ ) {// for each member of the smallest cow, if the biggest cows are willing to wait, put them on the line. For example, if w=1 for the smallest cow, then if the biggest two cows have w>=2, put them on the line and the smallest cow will walk away
            if(cows[biggestindex] >= inline){
              inline++;
              biggestindex--;
            }
          }
        }


      pw.println(inline);
      pw.close();



    }
}
