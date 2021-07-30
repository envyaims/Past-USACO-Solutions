// Problem: Problem 2. The Great Revegetation
// Contest: USACO - USACO 2019 February Contest, Bronze
// URL: http://usaco.org/index.php?page=viewproblem2&cpid=916
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Input: file revegetate.in
// Output: file revegetate.out
// Attempted: Sun, 7/25/2021 2:02:21 PM

import java.util.*;
import java.io.*;

public class revegetation {
	
	public static void main (String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new FileReader("revegetate.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("revegetate.out")));
		StringTokenizer st = new StringTokenizer(br.readLine());	
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		boolean[][] graph = new boolean[n][n];
		for(int i = 0; i < m; i++){
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken()) -1;
			int b = Integer.parseInt(st.nextToken()) -1;
			graph[a][b] = true;
			graph[b][a] = true;
		}
		

		int[] ans = new int[n];
		
		for(int i = 0; i < n; i++){
			boolean[] grass = new boolean[4];
			for(int j = 0; j < i; j++){
				if(graph[i][j]){
					grass[ans[j]] = true;
				}
			}
			for(int j = 0; j < 4; j++){
				if(grass[j] == false){
					ans[i] = j;
					break;
				}
			}
		}
		
		for(int i: ans){
			pw.print(i+1);
		}
		pw.close();
		
		

		
		
	}
}

