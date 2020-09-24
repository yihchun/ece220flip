#include <stdio.h>

int maxk(int n){
    /*
    if (n == 1) return 0;
    return 1+maxk(n/2);
    */
    int i;
    for (i=0; (1<<i)<=n; i++)
	;
    return i-1;
}

int main(){
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    printf("Maximum k that satisfies 2^k<=n is %d\n", maxk(n));
    return 0;
}
