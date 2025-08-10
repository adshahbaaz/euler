#include <stdio.h>
#define LIMIT 4e6
// By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.

/* 
We calculate the fib numbers up to 4 millionth term, check if term is even
and add. There is a known property of fib numbers that every third 
number term is even, but we will not use this to optimise 
*/


int main(){
    int a = 0, b = 1;
    int sum, c;

    for(; ;){ // infinite loop till limit exceeded	
        c = a + b;
        a = b;
        b = c;
               
        if (c >= LIMIT)
            break;

        if(c % 2 == 0) // sum only even terms
            sum += c;
       }
    printf("%d",sum);
    return 0;
}


