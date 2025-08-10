#include <stdio.h>

/*Find the largest palindrome made from the product of two-digit numbers.*/

/* We write a function is palindrome that uses arithmetic operations
to reverse a number. We also use the fact that any 6 digit palindromic number 
is divisible by 11 (assuming a palindrome exists in 6 digits which is also a multiple of two three 
digit numbers)*/

int ispalindrome(int n);

int main(){
	int p = 0,max_p = 0;
	
	for(int i = 999; i > 100; i--)
		for( int j = i; j > 100; j--)
				if( (p = i * j) % 11 == 0 && ispalindrome(p)) // check for divisibility by 11 *before* running ispalindrome - reduces required calls to it.
					if( p > max_p)
						max_p = p;
	if(max_p == 0)
		printf("None found.");
			
	printf("found: %d", max_p);
	return 0;
}

int ispalindrome(int n){	
	int m = n,p = 0;
	while(m > 0){
		p = p * 10 + m % 10;
		m /= 10;
	} 
	return p == n;
}


