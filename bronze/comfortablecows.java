import java.util.*;
import java.io.*;

public class comfortablecows {
    public static void main(String[] args) throws Exception {
      // add the cows coordinates to a 2d array
      // for each cow, if a cow is to the left, right, up, down of the cow, count++
      // if count == 3, output++
      // if count == 4 for the cow, output--;
      int[] dx = {0,0,-1,1};
      int[] dy = {-1,1,0,0};
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
      StringTokenizer st = new StringTokenizer(br.readLine());
      int n = Integer.parseInt(st.nextToken());
      int[][] cows = new int[n][2];
      boolean[][] grid = new boolean[1001][1001];
      int[][] counts = new int[1001][1001];
      int output = 0;
      for(int i = 0; i < n; i++){
        st = new StringTokenizer(br.readLine());
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        cows[i][0] = x;
        cows[i][1] = y;
        grid[x][y] = true;
        // if(grid[x-1][y]){
        //   counts[x][y]++;
        // }
        // if(grid[x][y-1]){
        //   counts[x][y]++;
        // }
        // if(grid[x+1][y]){
        //   counts[x][y]++;
        // }
        // if(grid[x][y+1]){
        //   counts[x][y]++;
        // }
        for(int j = 0; j < dx.length; j++){
          if(x+dx[j] < 0 || x+dx[j] > 1000 ||y+dy[j] < 0 || y+dy[j] > 1000 ){
            continue;
          }
          if(grid[x+dx[j]][y+dy[j]]){
            counts[x][y]++;
            counts[x+dx[j]][y+dy[j]]++;
            if(counts[x+dx[j]][y+dy[j]] == 3){
              output++;
            }
            else if(counts[x+dx[j]][y+dy[j]] == 4){
              output--;
            }
          }
        }
        if(counts[x][y] == 3){
          output++;
        }
        pw.println(output);



      }



      pw.close();
    }
}
