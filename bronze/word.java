import java.util.*;
import java.io.*;
public class word {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("word.in"));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        String[] word = br.readLine().split(" ");
        int lcount = 0;
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("word.out")));
        for(int i = 0; i < n; i++){
            if(lcount + word[i].length() <= k){
              lcount += word[i].length();
              if(i == 0){
                pw.print(word[i]);
              }
              else{
                pw.print(" "+word[i]);
              }
            }
            else{
              pw.println();
              pw.print(word[i]);
              lcount = word[i].length();
            }


        }
        pw.close();

    }
}
