import java.util.*;
import java.io.*;

public class acowdemia3 {
    public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
      StringTokenizer st = new StringTokenizer(br.readLine());
      int n = Integer.parseInt(st.nextToken());
      int m = Integer.parseInt(st.nextToken());
      char[][] grid = new char[n][m];
      boolean[][][] alrfriends = new boolean[n][m][2];
      for(int i = 0; i < n; i++){
        st = new StringTokenizer(br.readLine());
        String in = st.nextToken();
        for(int j = 0; j < m; j++){
          grid[i][j] = in.charAt(j);
        }
      }
      int output = 0;
      int[] dy = {0,0,1,-1};
      int[] dx = {-1,1,0,0};

    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(grid[i][j] == 'G'){
          // pw.println(i + " "+j);
          // pw.println(output);
          if(j > 0 && j < m-1 && grid[i][j-1] == 'C' && grid[i][j+1] == 'C'){
              output++;
            }
          else if(i > 0 && i < n-1 && grid[i+1][j] == 'C' && grid[i-1][j]=='C'){
            output++;

          }
          else{
            int numcows = 0;
            boolean[] tempcows = new boolean[4];
            for(int k = 0; k < dy.length; k++){
              if(i+dy[k] >= 0 && i+dy[k] < n && j+dx[k] >= 0 && j+dx[k] < m && grid[i+dy[k]][j+dx[k]] == 'C'){
                numcows++;
                tempcows[k] = true;
              }
            }

            if(numcows == 2){
              boolean triggered = false;
              if(tempcows[0] && tempcows[3] && !alrfriends[i+dy[0]][j+dx[0]][0]){
                alrfriends[i+dy[0]][j+dx[0]][0] = true;
                triggered = true;
              }
              if(tempcows[0] && tempcows[2] && !alrfriends[i+dy[0]][j+dx[0]][1]){
                alrfriends[i+dy[0]][j+dx[0]][1] = true;
                triggered = true;

              }
              if(tempcows[1] && tempcows[2] && !alrfriends[i+dy[2]][j+dx[2]][0]){
                alrfriends[i+dy[2]][j+dx[2]][0] = true;
                triggered = true;

              }
              if(tempcows[1] && tempcows[3] && !alrfriends[i+dy[3]][j+dx[3]][1]){
                alrfriends[i+dy[3]][j+dx[3]][1] = true;
                triggered = true;

              }

              if(triggered){
                output++;
              }
            }
          }

          }

        }
        
      }
      pw.println(output);
      pw.close();
      }
    }



//       int[] dy = {1,-1,1,-1}; // every pair in next to it x-axis
//       int[] dx = {-1,-1,1,1}; // every pair next to it y-axis
//
//       for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//           if(grid[i][j] == 'C'){
//             // first scenario CGC
//             if(grid[i][j+1] == 'G' && grid[i][j+2] == 'C'){
//               grid[i][j+1] = '.';
//               output++;
//             }
//             // test vertical
//             // second scenario
//             for(int k = 0; k < dx.length; k++){
//
//               try{
//                 if(grid[i+dy[k]][j+dx[k]] == 'C' && !alrfriends[i+dy[k]][j+dx[k]]){
//                   if(grid[i+dy[k]][j] == 'G'){
//                     grid[i+dy[k]][j] = '.';
//                     output++;
//                     alrfriends[i][j] = true;
//                     // pw.println((i+1)+" "+(j+1));
//                     // pw.println((i+dy[k]+1)+" "+(j+dx[k]+1));
//                     // pw.println((i+dy[k]+1)+" "+(j+1));
//                     // pw.println(grid[i+dy[k]][j]);
//                   }
//                   else if(grid[i][j+dx[k]] == 'G'){
//                     grid[i][j+dx[k]] = '.';
//                     output++;
//                   }
//                 }
//               }
//               catch (ArrayIndexOutOfBoundsException ex){
//                 continue;
//               }
//
//           }
//         }
//
//
//         }
//       }
//
//       pw.println(output);
//       pw.close();
//
//     }
// }
