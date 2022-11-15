// The program takes and int input list from the user and computes the factorial for each number and displays it
// Name: Karthik Yechuri
#include <stdio.h>

//declaring the functions fact and calculate_fact
int fact(int n);
void calculate_fact(int a[], int n, int b[]);

int main()
{

  int array_len; //length of the array
  printf("Enter the length of the array:");
  scanf("%d", &array_len); //taking the input for length of the array

  int elements[array_len], factorials[array_len];
  //Creating array elements to store the input and factorials to store the factorials of the input
  printf("Enter the elements of the array:");

  int i = 0;
  while (i < array_len)
  {
    //using while loop to store the input in elements array
    scanf("%d", &elements[i]);
    i++;
  }

  calculate_fact(elements, array_len, factorials); //calling the calculate_fact function to calculate the factorial of input and store it in a array

  printf("Output array: ");
  for (int i = 0; i < array_len; i++)
  {
    // printing the final output using the for loop
    printf("%d ", factorials[i]);
  }
  printf("\n");

  return 0;
}

int fact(int n)
{
  if (n == 1 || n == 0)
  {
    //initializing the value of factorial 1 and 0 to 1
    return 1;
  }
  else
  {
    return n * fact(n - 1);
    //using recursive function to calculate the factorial
  }
}

void calculate_fact(int a[], int n, int b[])
{
  for (int i = 0; i < n; i++)
  {
    // using the for loop to call fact function for each element in the list and store the values in the factorial array
    int number = a[i];

    b[i] = fact(number);
  }
}
