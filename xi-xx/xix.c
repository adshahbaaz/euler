#include <stdio.h>

char daytab[2][12] = {
{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};


int main(){

    int leap = 0;
    int day = 6; // first sunday of year 1901
    int sundays = 0;

    for(int year = 1901; year <= 2000; year++){
        if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0 )
            leap = 1;
        else
            leap = 0;	   
        
        int month = 0;

        while(month < 12){
            if(day > daytab[leap][month])
                day -= daytab[leap][month++]; 
            if(day == 1)
                sundays++;
            day += 7;
        }    
    }
    printf("sundays : %d\n",sundays);

    return 0;
}