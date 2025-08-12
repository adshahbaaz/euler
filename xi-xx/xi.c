#include <stdio.h>
#define GRID 20
#define WINDOW 4

void get_numbers(int numbers[][GRID]);
int max(int,int);
int max_of_four(int a, int b, int c, int d);

int numbers[GRID][GRID];

int main(){
    get_numbers(numbers);

    int max_prod = 0;
    
    for (int i = 0; i < GRID; i++){
        for (int j = 0; j < GRID; j++){ 
            if(numbers[i][j] == 0)
                continue;
            // vertical
            int hprod = 1,vprod = 1,dprod = 1,adprod = 1;
            if (i <= GRID - WINDOW)
                for(int k = 0; k < WINDOW; k++)
                    vprod *= numbers[i + k][j];
            // horizontal
            if (j <= GRID - WINDOW)
                for(int k = 0; k < WINDOW; k++)
                    hprod *= numbers[i][j + k];
            // diagonal - down & to the right
            if (i <= GRID - WINDOW && j <= GRID - WINDOW)
                for(int k = 0; k < WINDOW; k++)
                    dprod *= numbers[i + k][j + k];
 
            // anti-diagonal - down & to the left
            if (i <= GRID - WINDOW && j >= WINDOW - 1)
                for(int k = 0; k < WINDOW; k++)
                    adprod *= numbers[i + k][j - k];
            int p;
            if((p = max_of_four(hprod,vprod,dprod,adprod)) > max_prod)
                max_prod = p; 
            }
        }
        printf("Greatest product is: %d\n",max_prod);
        return 0;
     }

void get_numbers(int numbers[][GRID]){ // Populates array of ints from file
    FILE *ifp;

    if ((ifp = fopen("product_grid.txt", "r")) == NULL)
        printf("%s", "cant open file");

    for (int i = 0; i < GRID; i++)
        for (int j = 0; j < GRID; j++)
            if (fscanf(ifp, "%d", &numbers[i][j]) != 1)
            {
                fprintf(stderr, "Error reading integer from file");
                fclose(ifp);
                return;
            }; // fscanf deals with leading zeroes, whitespaces and newlines
    fclose(ifp);
}

int max(int a, int b) {
    return a > b ? a : b;
}

int max_of_four(int a,int b,int c,int d){
    return max(max(a,b),max(c,d));
}
