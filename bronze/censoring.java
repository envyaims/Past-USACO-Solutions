import java.util.*;
import java.io.*;

public class censoring {
    public static void main(String[] args) throws Exception {
      // http://usaco.org/index.php?page=viewproblem2&cpid=526#
      BufferedReader br = new BufferedReader(new FileReader("censor.in"));
      StringTokenizer st = new StringTokenizer(br.readLine());
      String main = st.nextToken();
      st = new StringTokenizer(br.readLine());
      String delete = st.nextToken();

      while(main.contains(delete)){
        int subindex = main.indexOf(delete);
        main = main.substring(0,subindex) + main.substring(subindex+delete.length());
      }


      PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("censor.out")));
      pw.println(main);
      pw.close();

    }
  }
