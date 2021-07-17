import java.util.*;
import java.io.*;

public class sleepy {
    public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("sleepy.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("sleepy.out")));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		
		int n = Integer.parseInt(st.nextToken());
		int[] nums = new int[n];
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++){
			nums[i] = Integer.parseInt(st.nextToken());
		}
		
		int output = n-1; // max changes 
		for(int i = n-1; i >= 1; i--){ // loop back
			if(nums[i] < nums[i-1]){
				output = i; // if it is not in ascending order, all the cows before need to be moved.
				break;
			}
			 
		}
		pw.println(output);
		pw.close();


		
	}
}
