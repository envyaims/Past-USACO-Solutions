import java.util.*;
import java.io.*;

public class pours {
    public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("mixmilk.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("mixmilk.out")));
		
		int[] cap = new int[3];
		int[] amt = new int[3];
		for(int i = 0; i < 3; i++){
			StringTokenizer st = new StringTokenizer(br.readLine());
			cap[i] = Integer.parseInt(st.nextToken());
			amt[i] = Integer.parseInt(st.nextToken());
		}
		
		for(int i = 0; i < 100; i++){
			int from = i % 3;
			int to = (i+1) % 3;
			int pour = Math.min(amt[from], cap[to] - amt[to]);
			
			amt[to] += pour;
			amt[from] -= pour;
			
			/*if(amt[from] + amt[to] > cap[to]){
				amt[from] -= (cap[to] - amt[to]);
				amt[to] = cap[to];
				
			}
			else{
				amt[to] += amt[from];
				amt[from] = 0;
			}*/
			
		}
		for(int i:amt){
			pw.println(i);
		}
		pw.close();
		
		
		
		
	}
}
