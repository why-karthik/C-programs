//          Author: Karthik Yechuri
//          
//Summary of the program project7_demographics.c :-  The program takes an input file and sorts it according to percentage of population whose ages are equal or greater than 65 years old

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 150 // Maximum number of charecters for a city name

struct state 
// declaring a struct state to store all the data from the input file
{
    char city[M + 1]; 
    // to store city

    int population_2020, populataion_2010;
    // to store the population of 2020 and 2010

    double pop_5, pop_18, pop_65; 
    //percentage of population of ages under 5, 18 and greater than or equal to 65
};

int int_compare(const void *p, const void *q);
// To compare the elements sent by qsort


int main()
{

    char input_file[M+1];
    // to store the input file name

    int i = 0;

    struct state list[M];


    printf("Enter the file name:");
    scanf("%s", input_file);
    //Taking the input for file name

    FILE *pfile = fopen(input_file, "r");
    // opening the input file in read ony format

    int k = fscanf(pfile, "%[^,], %d, %d, %lf, %lf, %lf\n", list[i].city, &list[i].population_2020, &list[i].populataion_2010, &list[i].pop_5, &list[i].pop_18, &list[i].pop_65);
 
    //storing the data from the input file into list using fscanf

    while (k == 6)
    // validatimg the input, because it reads 6 types of data from each sentence
    {
        i++;
        // counting the total number of states in the data
        k = fscanf(pfile, "%[^,], %d, %d, %lf, %lf, %lf\n", list[i].city, &list[i].population_2020, &list[i].populataion_2010, &list[i].pop_5, &list[i].pop_18, &list[i].pop_65);
        //reading all the lines using while loop
        
    }
   

    qsort(list, i, sizeof(struct state), int_compare);
    // calling selection_sort to sort the data
    
    char output_file[M+1];
    // to store the output file name

    strcpy(output_file, "sorted_");
    strcat(output_file, input_file); 
    // adding to sorted_ infront of the input file name

    FILE *wfile = fopen(output_file, "w");
    // opening the output file in "w" format, it creates one of file doesn't exist

    for (int a = 0; a < i; a++)
    {
        fprintf(wfile, "%s,%d,%d,%0.1lf,%0.1lf,%0.1lf\n", list[a].city, list[a].population_2020, list[a].populataion_2010, list[a].pop_5, list[a].pop_18, list[a].pop_65);
        //using fprintf to print the sorted data 
    }

    fclose(pfile);
    // closing the input file
    fclose(wfile);
    // closing the out put file

    return 0;
    //terminating the code with return code zero

}

int int_compare(const void *p, const void *q){
    const struct state *A = p;
    const struct state *B = q;
    
    // Comparing the percent of population above 65
    if (A->pop_65 > B->pop_65){
        return -1;
    }
    else if(A->pop_65 == B->pop_65){
        return 0;
    }
    else{
        return 1;
    }
    
}





