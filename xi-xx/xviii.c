#include <stdio.h>
#define ROWS 15
#define TOTAL_ELEMENTS (ROWS * (ROWS + 1) / 2) //15 rows in a triangle => 15 * 16 / 2

void get_numbers(int *);
int max(int a,int b);

int numbers[TOTAL_ELEMENTS];


int main(){    
    get_numbers(numbers);
    int r_node_pos,l_node_pos = 0;

    for(int row = ROWS - 2; row >= 0; row--){
        int start = row * (row + 1) / 2; //trinagular number fromula gives us starting idex of row
        for(int col = start; col < start + row + 1; col++){ 
            r_node_pos = col + (row + 1);
            l_node_pos = r_node_pos + 1;
            numbers[col] += max(numbers[r_node_pos],numbers[l_node_pos]);    
        }
    }
    printf("The maximum possible sum is: %d\n",numbers[0]);
    return 0;
}


void get_numbers(int *numbers){  // Populates array of ints from file  
	FILE *ifp;
	
	if ((ifp = fopen("maximum-path-sum.txt","r")) == NULL)  
		printf("%s","cant open file");
	
    for (int i = 0; i < TOTAL_ELEMENTS; i++)
        fscanf(ifp,"%d",&numbers[i]); //fscanf deals with leading zeroes, whitespaces and newlines
	fclose(ifp);
}

int max(int a,int b){
    return (a > b) ? a : b;
}