#include <stdio.h>
#define GRID_SIZE 20

/* 
Given an n x n grid - to  move from top left to bottom right will reuqire a total of 2n moves.
Additionally, these 2 n moves will consist of n 'right' moves and n 'down' moves. 
Therefore, we can frame our problem as "how many ways are there to choose n moves from a total of 2n moves where order doesn't matter?". 
We need only choose n moves as the remaining n places will necessarily be occupied by the other type of move.

Thus the general formula is: 

n! / k!(n - k)! = (n * n - 1 * n - 2 ... * n - k + 1 ) / k!

where n represents the total choices and k the number of choices to be made.
However, since we have a perfect square and the number of total choices is 2n, this means that k = n. So:

$\prod_{i = 1}^{n} (i + n) / i$ 

gives us the answer.
Notice how with a single index we multiply from n + 1 and upwards in the numerator upto 2n while also dividing by n! in the denominator.
*/


int main(){
    unsigned long long prod = 1;
    int n = GRID_SIZE;
    for(int i = 1; i <= n; i++)
        prod = prod * (n + i) / i; // we need to multiply first then divide using *= would be wrong because of integer division whereas (n + i) / i is guaranteed to be divisible by i 
    printf("Number of ways is: %llu\n",prod);
    return 0;
}


