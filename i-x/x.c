#include <stdio.h>
#define LIMIT 2000000
/*
Problem: The sum of the primes below $10$ is 2 + 3 + 5 + 7 = 17
Find the sum of all the primes below two million.
*/

/*
Solution:  We use the sieve of erastothenes to implement an efficient method of finding primes. 
When checking for prime numbers up to a limit we only need to check to the square root of the limit
as we have already found the smallest prime factor of each composite up to that limit. 
Any remaining numbers that haven't been crossed out must be prime since:
if a > sqrt(limit) then b has to be < sqrt(limit)
*/


int main(){
	
	static int primes[LIMIT];

	for(int i = 0; i < LIMIT + 1;i++)
		primes[i] = 1; // all numbers marked as prime iniitially
	
	primes[0] = primes[1] = 0;
	int p = 2;

	while(p * p < LIMIT){
		if (primes[p])
			for(int n = p * p; n <= LIMIT ;n += p)
					primes[n] = 0;
		p++;
	}

    unsigned long long sum = 0;
	for(int i = 0; i < LIMIT + 1; i++)
		if(primes[i])
			sum += i;
    printf("Sum of primes up to 2 million is: %llu",sum);
	
    return 0;
}
