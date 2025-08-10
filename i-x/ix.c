#include <stdio.h>

/*
Problem: A Pythagorean triplet is a set of three natural numbers, a < b < c for which,
a^2 + b^2 = c^2
There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc. 
*/

/*
Solution: 

We use a straightforward approach - although there is a parametrisation of triplets we can use, 
it is overkill for a small s.

-  s = 1000
- rearranging gives us c = 1000 - b - a
- we need to check for when c^2 = a^2 + b^2
- the conditions imply that:
    a < (s - 3)/3 
    and 
    b < (s - a) / 2 as there is a c remaining that is larger than b.

We simply iterate over the range of a and b combos using a double loop 
and check  if they satisfy the pythagorean theorem. 
*/

int main(){
    const int s = 1000;

    for(int a = 3 ; a < (s-3) / 3; a++){
        for(int b = a + 1; b < (s-a) / 2; b++){
            int c = s - b - a;
            if(c * c == a * a + b * b){
                printf("Product of the the Pythagorean triplet is: %d",a * b * c);
                return 0;
            }
        }
    }
}