#include <stdio.h> 
#define DIGITS 50
#define TERMS 100

int get_digits(int *digits);

int sum[DIGITS + 2];
int digits[DIGITS * TERMS];

int main(){
	
    get_digits(digits);


	int s = 0, carry = 0;

	for(int i = DIGITS - 1; i >= 0; i--){
        s = carry;
        for(int j = i; j < DIGITS * TERMS; j += DIGITS){
            s += digits[j];
        }
        sum[DIGITS - 1 - i] = s % 10; //reverse the order we accumalate the sum for last carry
        carry = s / 10;
    }
    int n = DIGITS;

    while(carry > 0){ //handle remaining carries
        sum[n++] = carry % 10;
        carry /= 10; 
    }
    printf("The sum is: ");
    int m = n;
    while(--m > 0)
        printf("%d",sum[m]);

    printf("\nThe first ten digits are: ");
    for(int i = n - 1; i > (n - 1 - 10); i--)
        printf("%d",sum[i]);
	return 0;
}

int  get_digits(int *digits){  // Populates array of digits from file  
	FILE *ifp;
	
	if ((ifp = fopen("large_sum.txt","r")) == NULL)  
		printf("%s","cant open file");
	
	int c = 0, n = 0;
	
	 while ((c = getc(ifp)) != EOF)
		if(c == '\n')
			;
		else
			digits[n++] = c - '0';

	fclose(ifp);
	return 0;
}
