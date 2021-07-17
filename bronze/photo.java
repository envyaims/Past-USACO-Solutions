import java.util.*;
import java.io.*;

// http://usaco.org/index.php?page=viewproblem2&cpid=988#

public class photo{
    public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(new File("photo.in"));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(new File("photo.out"))));

        int n = scan.nextInt();
        int[] nums = new int[n-1];
        for(int x = 0; x < n-1; x++){
            nums[x] = scan.nextInt();
        }
        for(int x = 1; x <= n; x++){
            boolean[] status = new boolean[n];
            int[] a = new int[n];
            a[0] = x;
            for(int y = 1; y < n;y++){
                a[y] = nums[y-1] - a[y-1];
                if(a[y] < 1 || a[y] > n|| status[a[y]-1]){
                    a[y] = 0;
                    break;
                }
                status[a[y]-1] = true;
            }
            if(a[a.length -1 ] == 0){
                continue;
            }
            else{
                for(int z = 0; z < a.length-1;z++){
                    pw.print(a[z]+" ");

                }
                pw.print(a[n-1]);
                pw.println();
            }
        }
        pw.close();
    }
}
