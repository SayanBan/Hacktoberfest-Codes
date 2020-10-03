import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Day10 {



    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int l,a,max=0;
        String s="";
        char c;
        while(n!=0)
        {
            a=n%2;
            s=a+s;
            n=n/2;
        }
        l=s.length();
        a=0;
        for(int i=0;i<l;i++)
        {
            c=s.charAt(i);
            if(c=='1')
            {
                a++;
            }
            else
            {
                if(a>max)
                {
                    max=a;
                }
                a=0;
            }
        }
        if((a!=0 && max==0) || a>max)
        {
            max=a;
        }
        System.out.println(max);        
        scanner.close();
    }
}

