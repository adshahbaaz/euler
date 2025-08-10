#include <stdio.h>
#define POWER 1000
/*What is the sum of the digits of the number 2^1000*/

int main(){


    int carry = 0, num_digits = 1;
    int product[1000];

    product[0] = 1;
    int n = 0;
    while(n < POWER){
        carry = 0;
    for(int i = 0; i < num_digits;i++){
            int powers = 2 * product[i] + carry;
            product[i] = powers % 10;
            carry = powers / 10;
        }
        if(carry > 0)
            product[num_digits++] = carry;
        n++;
    }

    int i = 0, sum = 0;
    while(i < num_digits)
        sum += product[i++];
    
        printf("The sum of the digits of 2^1000 is: %d\n",sum);
    return 0;
}