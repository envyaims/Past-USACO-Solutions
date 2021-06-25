import java.util.*;
import java.io.*;

public class social1{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("socdist1.in"));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        String spots = st.nextToken();
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(new File("socdist1.out"))));

        for(int x = 0; x < 2; x++){
          int maxstart = 0;
          int maxend = 0;
          int tempstart = 0;
          int tempend = 0;
          int cow1;
          for(int i = 0; i < n-1; i++){
                if(spots.charAt(i) == '0'){
                  tempstart = i;

                  for(int j = i+1; j < n; j++){
                      if(spots.charAt(j) == '1' || j == n-1){
                        tempend = j-1;
                        break;
                      }
                  }

                  if(tempend-tempstart > maxend-maxstart){
                    maxstart = tempstart;
                    maxend = tempend;
                  }


                }
            }


          cow1 = (maxstart+maxend)/2;
          spots = spots.substring(0,cow1) + '1' + spots.substring(cow1+1);


        }
        int output = 5001;
        for(int i = 0; i < n-1; i++){
          if(spots.charAt(i) == '1'){
            for(int j = i+1; j < n; j++){
              if(spots.charAt(j) == '1'){
                  output = Math.min(output,j-i);
              }
            }
          }
        }


        pw.println(output);
        pw.close();


    }
}
