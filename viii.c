#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

// Find the thirteen adjacent digits in the 1000-digit number in largest_product.txt that have the greatest product. What is the value of this product?

/* 
instead of calculating the entire product, we use a sliding window approach that calculates the current product 
by dividing it by the  number 'leaving' the window and multiplying by the number 'entering' it. 
We have to deal with the case of when our window contains a zero as the entire product wull just be 0 - we reset our product every time this happens.
*/

int get_digits(char *d); 

int main(){
	char digits[1000];  
	get_digits(digits);	// reads file to digits
	int k;
	printf("Enter a number of adjacent digits: ");
    scanf("%d",&k);
	
	int N = strlen(digits);
	
	if(N < k)
		return 0;
	
	unsigned long long product = 1;
	
	for(int i = 0 ; i < k ; i++){

		if(digits[i] == '0'){
			printf("theres a zero.");
			product = 1;
			//m += i + 1;
		}else{
			product *= digits[i] - '0';
		}	
	}     

	unsigned long long max_product = product;
	
	for(int i = k ; i < N ; i++){
		int new = digits[i] - '0';
		int old = digits[i - k] - '0';
		
		if(old == 0){
	  		product = 1;
			for(int j = 1 ; j <= k; j++)
				product *= digits[i -k + j] - '0';
		} else{
			product = (product / old) * new;	
			//printf("%d\n",product);
		}
		
		if(product > max_product)
				max_product = product;
	}
	printf("Max product: %lld",max_product);
	
	return 0;

}
	

int  get_digits(char *digits){  // Populates array of character digits from file  
	FILE *ifp;
	
	if ((ifp = fopen("largest_product.txt","r")) == NULL)  
		printf("%s","cant open file");
	
	int c = 0, n = 0;
	
	 while ((c = getc(ifp)) != EOF)
		if(c == '\n')
			;
		else
			digits[n++] = c;
	
	digits[n] = '\0';

	fclose(ifp);
	return 0;
}

