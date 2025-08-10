#include <stdio.h>


int main(){

    int carry = 0, num_digits = 1;
    int product[1000];
    int prod = 0;

    product[0] = 1;
    int n = 0;
    for(int i = 2; i <= 100; i++){
        carry = 0;
        for(int j = 0; j < num_digits; j++){
            prod = i * product[j] + carry;
            product[j] = prod % 10;
            carry = prod / 10;
        }
        while(carry > 0){
            product[num_digits++] = carry % 10;
            carry /= 10;
        }
    }
    int sum = 0;

    for(int i = num_digits - 1; i >= 0; i--)
        sum += product[i];

    printf("The sum of the digits of 100! is: %d",sum);
    return 0;

}