#include <stdio.h>
#include <string.h>

/* If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used? Do not count spaces or hyphens. */

/* we need to define an array that stores the number of letters fore ach of the 
base words for numbers.
Additionally:
    - if num_digits == 3 && n != 100 then and and is added after 100s place

*/


const char* units_and_teens[] = {"one","two","three","four","five","six","seven","eight","nine","ten","eleven",
                "twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen", "nineteen"};

const char* tens[] = {"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};

const char* hundred = "hundred";
const char* thousand = "thousand";

size_t nchars(int n);

int main(){
//    printf("Number of letters in number is: %zu\n",nchars(101));

    size_t sum = 0;
    for(int i = 1; i <= 1000; i++)
         sum += nchars(i);
    printf("Number of letters in number is: %zu\n",sum);
    return 0;
}

size_t nchars(int n){
        
    size_t total_length = 0;
    
    if(n == 100)
        return strlen("one") + strlen(hundred);

    if(n == 1000)
        return strlen("one") + strlen(thousand);

    if(n > 100 && n < 999){
        total_length += strlen(units_and_teens[(n / 100) - 1]) + strlen(hundred) + strlen("and");
        n %= 100;
    }
    if(n < 100 && n >= 20){
        total_length += strlen(tens[(n / 10) - 2]);
        n %= 10;
    }
    if(n == 0)
        return total_length;
     
    if(n < 20)
        total_length += strlen(units_and_teens[n - 1]);
   
    return total_length;

}