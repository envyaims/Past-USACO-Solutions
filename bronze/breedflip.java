import java.util.*;
import java.io.*;

public class breedflip {
    public static void main(String[] args) throws Exception {
      // loop through each of the string
      // find their differences
      // if there differences are consecutive and are the same way (ie. H -> G) one flip is needed
      // find every differences and add up the number of flips

      //http://usaco.org/index.php?page=viewproblem2&cpid=1012

      BufferedReader br = new BufferedReader(new FileReader("breedflip.in"));
      StringTokenizer st = new StringTokenizer(br.readLine());

      int n = Integer.parseInt(st.nextToken());
      st = new StringTokenizer(br.readLine());
      String a = st.nextToken();
      st = new StringTokenizer(br.readLine());
      String b = st.nextToken();

      int output = 0;
      for(int i = 0; i < n; i++){
          if(a.charAt(i) != b.charAt(i)){
            output++;
              while(true){
                  if(a.charAt(i+1) != b.charAt(i+1)){
                    i++;
                  }
                  else{
                    break;
                  }
                  }
              }
          }
          PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("breedflip.out")));
          pw.println(output);
          pw.close();
      }




  }
