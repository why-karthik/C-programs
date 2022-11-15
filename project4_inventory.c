// Name: Karthik Yechuri
// This program takes in the input for number of parts, number of part types and the list of parts.
//This program calculates the number of computers that a factory can build with its inventory.

int find_minimum(int *a, int n);//function to find min value

#include <stdio.h>
int main()
{
  int N, K; // N is the number of parts,  K is the number of part types

  printf("Enter number of parts (N):");

  scanf("%d", &N); //Taking the input for N from user
 
  if (N >= 1 && N <= 1000000)
  //input validation using if else statements
  {
    printf("Enter number of part types (K):");
    scanf("%d", &K);//Taking the input for number of part types

    if (K < 1 || K > 10000)
    //Validating the input for K, using if-else statements
    {
      printf("Invalid number of part types %d\n", K);//printing the error message for wrong input
      printf("Must be in the range [1,10000]\n");
      return 0;
    }
  }
  else
  {
    printf("Invalid number of parts %d\n",N);//printing the error message for wrong input
    printf("Must be in the range [1,1000000]\n");
    return 0;
  }

  int parts[N], counter[K];
  // Initializing the arrays, parts whicch stores all the parts values and counter- which stores the total number of same parts

  for (int j = 0; j < K; j++)
  //asigning the initial values to zero
  {
    counter[j] = 0;
  }

  printf("Enter part list:\n");

  for (int i = 0; i < N; i++)
  {
    scanf("%d", &parts[i]);//storing all the values of parts in parts array using for loop
  }

  for (int i = 0; i < N; i++)
  //using for loop for input validation of parts
  {
    if (parts[i] < 1 || parts[i] > K)
    {
      printf("Invalid list of parts\n");
      printf("Part codes must be in the range [1,%d]\n", K);
      return 0;
    }
  }

  //using two for loops to calculate the same type of elements in to counter
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < K; j++)
    {
      if (parts[i] == (j + 1))
      {
        counter[j]++;
      }
    }
  }

  printf("The factory can build %d computer(s)\n", find_minimum(counter, K));
  //printing the final message and the number of computers we can make with the inventory
  return 0;//exiting the main with return code 0
}

int find_minimum(int *a, int n){//declaring the function
    int b,min;//decalring variables
  //assuming that the first element is small for convinience
  min = *a;

  //using for loop to find the smallest number counter array, because with the inventory we can make that number of computers
  for (int i = 0; i < n; i++)
  b = *(a++);
  {
    if (b < min)
    {
      min = b;// changing the value of small for a value smaller than "small" using if statement
    }
  }
    return min;
}