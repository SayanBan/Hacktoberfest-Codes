import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Day28 {



    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int N = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");
        String s[]=new String[N];
        for(int i=0;i<N;i++){
            s[i]="";
        }
        int j=0;
        String g="@gmail.com";
        for (int NItr = 0; NItr < N; NItr++) {
            String[] firstNameEmailID = scanner.nextLine().split(" ");

            String firstName = firstNameEmailID[0];

            String emailID = firstNameEmailID[1];

            int l=emailID.length();
            String a=emailID.substring(l-10);
            if(g.equalsIgnoreCase(a)){
                s[j]=firstNameEmailID[0];
                j++;
            }
        }
        Arrays.sort(s);
        for(int i=0;i<N;i++){
            if(s[i].equalsIgnoreCase("")){
                
            }
            else{
                System.out.println(s[i]);
            }
        }
        scanner.close();
    }
}

