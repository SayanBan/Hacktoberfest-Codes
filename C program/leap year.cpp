    /*

     * C program to find whether a given year is leap year or not

     */
    #include<stdio.h>
    #include<conio.h>
    #include<math.h>
    int main()

    {

        int year;

     

        printf("Enter a year \n");

        scanf("%d", &year);

        if ((year % 400) == 0)

            printf("%d is a leap year \n", year);

        else if ((year % 100) == 0)

            printf("%d is a not leap year \n", year);

        else if ((year % 4) == 0)

            printf("%d is a leap year \n", year);

        else

            printf("%d is not a leap year \n", year);

    }
