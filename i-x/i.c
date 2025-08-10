#include <stdio.h>
#define LIMIT 999
// Find the sum of all the multiples of 3 or 5 below 1000 

/* 
sum of numbers from 1 to n is given by n * (n + 1) / 2.
this is known as the nth triangular number.

Thus:
n * (n + 1) / 2 = 1 + 2 + 3 + 4 +..n

then,
f * (n * (n +1) / 2) = f + 2f + 3f + 4f ..nf

so for any f  - the sum of the multiples of f up to n is:
f * (l * (l+1) / 2) 
where l =  floor(n / f)
eg. 5 * (l * (l+1) / 2) #  sum of all multiples of 5
*/

int sum_of_multiples(int);

int main(){

    int sum = (sum_of_multiples(3) + sum_of_multiples(5)) - sum_of_multiples(15); //we need to subtract the sum of lcm 
    printf("sum of multiples of 3 or 5 below 1000: %d",sum); 
    return 0;
}

int sum_of_multiples(int f){
    int l = LIMIT / f;
    return f * l * (l + 1) / 2 ;
}