#include <stdio.h>
#include <math.h>
/* Calculate the number of digits in base N */
int getDigitBaseN(int number, int N){
    /*
    if (number == 0) return 0;
    return 1+getDigitBaseN(number/N, N);
    */
    int ret = 0;
    while (number) {
	ret++;
	number /= N;
    }
    return ret;
}
/* Print out a number in base N */
void printBaseN(int number, int N){
    int digit = getDigitBaseN(number, N);
    int i, j;
    int cur, res;
    for (i=digit; i; i--) { /* loop through each digit to print */
	cur = 1; /* N^(i-1) */
	res = 0; /* number / cur */
	for (j=0; j<i-1; j++) /* computes the N^(i-1) iteratively */
	    cur *= N;
	while (number >= cur) { /* computes number / cur by repeated sub */
	    number -= cur;
	    res++;
	}
	/* above loop has the side effect of setting number = number % cur */
	printf("%d", res); /* prints number/cur, which is current digit */
    }
    printf("\n");
}
int main(){
    int number, N;
    printf("type number: ");
    scanf("%d", &number);
    printf("type base N: ");
    scanf("%d", &N);

    printf("number of digits: %d\n", getDigitBaseN(number, N));
    printBaseN(number, N);

    return 0;
}

