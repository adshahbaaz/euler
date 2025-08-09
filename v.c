#include <stdio.h>

int find_prime_factors(int n);
int factors[20 + 1] = {0};

int main(){

	int n = 2, lcm;

	while(n <= 20)
		find_prime_factors(n++);

	lcm = 1;
	for (int n = 20 ; n >= 0 ; n--) 
		while( factors[n]-- > 0)
			lcm *= n;	
	printf("Lowest common multiple of numbers 1 to 20 is: %d\n",lcm);
	return 0;
}

int find_prime_factors(int n){
int count,f;

	for(f = 2; n > 1 && f * f <= n; f++){
		count = 0;
		while(n % f == 0){
			n /= f;
			count++;
		}

		if(factors[f] < count)
			factors[f] = count;		
	}
	if(n > 1)		
		factors[n] = 1; //number itself is prime
		
	return 0;
}