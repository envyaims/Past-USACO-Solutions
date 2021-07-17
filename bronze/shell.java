import java.util.*;
import java.io.*;

public class shell {
    public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("shell.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("shell.out")));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		HashMap<Integer, String> location = new HashMap<Integer, String>();
		location.put(1,"a");
		location.put(2,"b");
		location.put(3,"c");
		
		int acount = 0;
		int bcount = 0;
		int ccount = 0;
		
		for(int i = 0; i < n; i++){
			st = new StringTokenizer(br.readLine());
			int swap1 = Integer.parseInt(st.nextToken());
			int swap2 = Integer.parseInt(st.nextToken());
			int guess = Integer.parseInt(st.nextToken());
			
			String marbleswap = location.get(swap1);
			location.put(swap1,location.get(swap2));
			location.put(swap2,marbleswap);
			String guessed = location.get(guess);
			if(guessed.equals("a")){
				acount++;
			}
			else if(guessed.equals("b")){
				bcount++;
			}
			else{
				ccount++;
			}
			
			
		}
		pw.println(Math.max(acount,Math.max(bcount,ccount)));
		pw.close();
		
		
		
	}
}
