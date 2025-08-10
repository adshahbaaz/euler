#include <stdio.h>
#define LIMIT 1000000
/* Which starting number, under one million, produces the longest Collatz sequence?*/

/* 
As many 'chains' will be reencountered we cache the values and calculate each collatz value as a sum of collatz[n/2] or collatz[3n+1].
This is aprgramming technique known as memoisation.
The first time a value is encountered we recursively call the collatz function(?). 
some quick induction shows us that: 
    - if n is even then collatz[n] = collatz[n/2] + 1 thus collatz[2k] > collatz[k] for all k. ie. for any k we go from 
      2k => k in a step.
    - if n is odd then 3n + 1 will always be even, thus collatz(n) = collatz[3n + 1 / 2] + 2 (+2 counts the additional odd to even steps) 
*/
int collatz(long long n);
static short collatz_chain[LIMIT];
   
int main(){
    int max_count = 0;
    int largest_chain_number = 1;

    for(int n = 1; n < 1e6; n++){
        int current_chain_length = collatz(n);
        
        if( current_chain_length > max_count){
            max_count = current_chain_length;
            largest_chain_number = n;
        }
    } 
    printf("The number with the largest collatz chain is: %d\n",largest_chain_number);
    printf("The length of the chain is: %d\n",max_count);
    return 0;
}



int collatz(long long n){
    if(n == 1) // base case
        return 1;
    
    if(n < LIMIT && collatz_chain[n] != 0) 
        return collatz_chain[n];
    long long next_n;
    
    if(n % 2 == 0)
        next_n = n / 2;
    else
        next_n = 3 * n + 1;
    
    int length = collatz(next_n) + 1;
    if(n < LIMIT)
        collatz_chain[n] = length;
    return length;
}

