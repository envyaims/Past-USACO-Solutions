import java.util.*;
import java.io.*;

// http://www.usaco.org/index.php?page=viewproblem2&cpid=615
public class pails {
    public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new FileReader("pails.in"));
      PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("pails.out")));
	    StringTokenizer st = new StringTokenizer(br.readLine());
      int x = Integer.parseInt(st.nextToken());
      int y = Integer.parseInt(st.nextToken());
      int z = Integer.parseInt(st.nextToken());

      int first = z/x;
      int second = z/y;

      int abs = 1001;
      for(int i = 1; i <= first; i++){
        for(int j = 1; i <= second;j++){
          int current = (i * first) + (j*second);
          if(z-current < abs){
            abs = z-current;
          }
        }
      }
      pw.print(z-abs);
      pw.close();


    }
}
