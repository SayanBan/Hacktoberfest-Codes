import java.util.Scanner;
public class GCD 
{

    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        int num1, num2;
        System.out.println("Enter the value of 1st number :");
        num1=sc.nextInt();
        System.out.println("Enter the value of 2nd number :");
         num2=sc.nextInt();
        int gcd = gcd1(num1, num2);

        System.out.println("G.C.D of num1 and num2 is= "+gcd);
    }

    public static int gcd1(int num1, int num2)
    {
        if (num2 != 0)
            return gcd1(num2, num1 % num2);
        else
            return num1;
    }
}