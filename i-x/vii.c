#include <stdio.h>

// what is the 10001st prime?

/* We use the sieve of erastothenes to find primes up to a certain number.
we first initialise an array of 1s upto 
*/


int main(){

	int sieve_limit = 110000; // a good approximation for the limit we will need is ln(nprime) * nprime 
							 // however this number was chosen wafter trial and error 
	int primes[sieve_limit + 1];

	for(int i = 0; i < sieve_limit + 1;i++)
		primes[i] = 1;
	
	primes[0] = primes[1] = 0;
	
	int p = 2;
	
	while(p * p < sieve_limit){
		if (primes[p])
			for(int n = p * p; n <= sieve_limit ;n += p)
					primes[n] = 0;	
		p++;
	}

	int i, nprime = 0;
	for(i = 0; i < sieve_limit + 1; i++)
		if(primes[i])
			if (++nprime == 10001)
				break;
	printf("10001st prime number is: %d\n",i);
	return 0;
}







