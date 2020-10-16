import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;


class Difference {
  	private int[] elements;
  	public int maximumDifference;
    Difference(int a[])
    {
        elements=a;
    }
	// Add your code here
    int max=0,diff=0,p;
    void computeDifference()
    {
        for(int i=0;i<elements.length-1;i++)
        {
            p=elements[i];
            for(int j=i+1;j<elements.length;j++)
            {
                 diff=p-elements[j];
                if(diff<0)
                {
                     diff=diff*(-1);
                }
                if(diff>=max)
                {
                    max=diff;
                    elements[i]=diff;
                }
            }
        }
        maximumDifference=0;
        for(int i=0;i<elements.length-1;i++)
        {
            if(elements[i]>maximumDifference)
            {
                maximumDifference=elements[i];
            }
        }
    }
} // End of Difference class

public class Day14 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        sc.close();

        Difference difference = new Difference(a);

        difference.computeDifference();

        System.out.print(difference.maximumDifference);
    }
}
