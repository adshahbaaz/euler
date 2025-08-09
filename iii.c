#include <stdio.h>
//#include <limits.h>

// What is the largest prime factor of the number 600851475143?

/* 
We use the fundamental theorem of arithmetic which states that any positive natural number 
can be expressed as a unique set of primes. the upper imit we need to check to is bounded by the numbers square root,
as once we are past this we will have already checkedf ir the corresponding multiple.  
*/ 

int main(){
	//printf("Maximum value of int: %d\n", INT_MAX);
	int f;
	unsigned long long n;
	printf("Enter a number: ");
	scanf("%llu",&n);

	for(f = 2; n > 1 && f * f <= n; f++) // prime factorisation
		while(n % f == 0)
			n /= f; 
	if(n == 1)
		printf("Largest prime factor is: %d",f - 1); 
	else
		printf("Largest prime factor is: %d", n); //number itself is prime
	return 0;
}


