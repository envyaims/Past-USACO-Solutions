import java.util.*;
import java.io.*;

public class whereami {
    public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new FileReader("whereami.in"));
      StringTokenizer st = new StringTokenizer(br.readLine());
      // loop through every substring for length i=2, i < n. If there is another substring that is the same, we continue going up.
      // have another loop and see if the same substring exists in the rest of the satring

      int n = Integer.parseInt(st.nextToken());
      st = new StringTokenizer(br.readLine());
      String location = st.nextToken();
      PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("whereami.out")));
      boolean found = false;
      for(int size = 1; size <= n; size++){
        for(int i = 0; i <= n-size; i++){
            String sub = location.substring(i,i+size);
            found = false;
            // pw.println(sub);
            // pw.println("Above sub");
            for(int j = i+1; j <= n-size; j++){
              // pw.println(location.substring(j,j+size));
              if (sub.equals(location.substring(j,j+size))){
                found = true;
                break;
              }
            }
            if(found){
              break;
            }

          }
      if(!found){
          pw.println(size);
          pw.close();
          System.exit(0);
      }
      // else{
      //   break;
    // }
}
  }
}
