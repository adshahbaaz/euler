#include <stdio.h>

// Find the difference between the sum of the squares of the first one 
// hundred natural numbers and the square of the sum

/* The sum of the squares of the first n natural numbers is given by:
n(n+1)(2n + 1)/6 = 1^2 + 2^2 + 3^2 + 4^2 + ... n^2
and from earlier we know ,
n * (n + 1) / 2 = 1 + 2 + 3 + 4 +..n 
All we need to do is sum the results.
*/


int main(){
    int n = 100;
    int sum = n * (n + 1) / 2;
    int square_of_sum = sum * sum;
    int sum_of_squares = n * (n + 1) * (2*n + 1) / 6;

    printf("%d",square_of_sum - sum_of_squares);
    return 0;
}