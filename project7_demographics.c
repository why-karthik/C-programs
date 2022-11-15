//          Author: Karthik Yechuri
//          
//Summary of the program project7_demographics.c :-  The program takes an input file and sorts it according to percentage of population whose ages are equal or greater than 65 years old

#include <stdio.h>
#include<string.h>
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

void selection_sort(struct state list[], int n); 
// selection sort function to sort the data from the input file

int find_largest(struct state list[], int n); 
// find largest function to recursively call it and find the largest element from the data

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

    selection_sort(list, i);
    // calling selection_sort to sort the data

    char output_file[M+1];
    // to store the output file name

    strcpy(output_file, "sorted_");
    strcat(output_file, input_file);
    // adding to sorted_ infront of the input file name

    FILE *wfile = fopen(output_file, "w");
    // opening the output file in "w" format, it creates one of file doesn't exist

    for (int a = i - 1; a >= 0; a--)
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

void selection_sort(struct state list[], int n)
{
    struct state temp;
    // temp is used to temporarily store the list elements

    int largest = 0;

    if (n == 1){
        // if n = 1, return to main
        return;
    }

    largest = find_largest(list, n);
    // calling find_largest to find the largest element of pop_65 in list

    if(largest < n-1){
        temp = list[n-1]; // storing the list[n-1] in temp
        list[n-1] = list[largest]; // storing the largest pop_65 group in to n-1 list
        list[largest] = temp;// replacing back that line with the data from the list[n-1]
    }

    selection_sort(list, n - 1); // calling selection sort reccursively to sort the data
}

int find_largest(struct state list[], int n){

    int largest_index = 0;

    for(int i = 1; i < n; i++)
    {
        if (list[i].pop_65 > list[largest_index].pop_65)
            //comparing all the pop_65 elements and finding the position of largest element
            largest_index = i;

    }

    return largest_index;
    // returning the position of the largest pop_65 from the data in n elements



}
