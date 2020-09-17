/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int part1(){
    int date;
    printf("Enter a date in September 2020: ");
    scanf("%d", &date);
    if (date < 1 || date > 30) {
        printf("Invalid date.\n");
        return 0;
    }
    printf("9/%d/2020 is a ", date);
    switch (date%7) {
        case 0: printf("Monday\n"); break;
        case 1: printf("Tuesday\n"); break;
        case 2: printf("Wednesday\n"); break;
        case 3: printf("Thursday\n"); break;
        case 4: printf("Friday\n"); break;
        case 5: printf("Saturday\n"); break;
        case 6: printf("Sunday\n"); break;
    }

    return 0;
}

int part2(){
    int n, i, num, sum=0;
    double average = 0;
    printf("Enter how many numbers to input: ");
    scanf("%d", &n);

    printf("Enter the numbers\n");
    for (i=0; i<n; i++) {
        scanf("%d", &num);
        sum += num;
    }
    if (n) {
        average = (double)sum / n;
    }

    printf("The average of the numbers: %lf\n", average);
}

int part3() {
    int num, i;
    while (1) {
        printf("Enter a number: ");
        scanf("%d", &num);
        if (num == 0) break;
        if (num > 10 || num < 0) continue;
        while (num--) printf("*");
        printf("\n");
    }
}

int main()
{
    part1();
    part2();
    part3();

    return 0;
}
