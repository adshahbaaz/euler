#include <stdio.h>
// What is the value of the first triangular number to have over five hundred divisors?

/*
Calculate the tirangular numbers for n > 500 then run prime fatorisation on
each, while ocunting exponents of each prime factor. Since the exponent will equal the number 
of ways we can represent that prime factor we can use the the product rule of combanatorics to give us the number od divisores d(n):

d(n) = (e1 + 1)(e2 + 1)..(em + 1)

To find the prime factors we e use the fundamental theorem of arithmetic which states that any positive natural number 
can be expressed as a unique set of primes. the upper imit we need to check to is bounded by the numbers square root,
as once we are past this we will have already checkedf for each of the factors higher than it.  
*/ 

int main(){    
    const int DIVISOR_LIMIT = 500;
    int f,n;
   
    for(n = 2; ; ++n){
	    int n_divisors = 1;
        //printf("%d\n",n);
        int triangular_number = n * (n + 1) / 2;
        int m = triangular_number;
        for(f = 2; m > 1 && f * f <= m; f++){
            int raise = 0; 
		    while(m % f == 0){
			    m /= f; // prime factorisation
                raise++;        
            }
            if (raise > 0)
                n_divisors *= (raise + 1);
        }
        if (m > 1) // triangular number is prime
            n_divisors *= 2;
            
        if(n_divisors > DIVISOR_LIMIT){
        printf("First triangular number to have more than 500 factors is: %d\n",triangular_number);             
        return 0;
        }   
    }
    return 0;
}
