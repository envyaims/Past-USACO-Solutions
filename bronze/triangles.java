import java.util.*;
import java.io.*;
public class triangles {
    public static void main(String[] args) throws Exception {
      // http://usaco.org/index.php?page=viewproblem2&cpid=1011
      BufferedReader br = new BufferedReader(new FileReader("triangles.in"));
      StringTokenizer st = new StringTokenizer(br.readLine());
      PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("triangles.out")));

      int n = Integer.parseInt(st.nextToken());

      int[][] triangles = new int[n][2];
      for(int i = 0; i < n; i++){
          st = new StringTokenizer(br.readLine());
          triangles[i][0] = Integer.parseInt(st.nextToken());
          triangles[i][1] = Integer.parseInt(st.nextToken());
      }

      int output = 0;
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
          for(int k = 0; k < n; k++){
              if(triangles[i][0] == triangles[j][0] && triangles[j][1] == triangles[k][1]){
                  int area =  Math.abs((triangles[j][1]-triangles[i][1])) * Math.abs((triangles[k][0]-triangles[j][0]));
                  output = Math.max(output,area);
              }



          }
        }
      }

      pw.println(output);
      pw.close();
  }
}
