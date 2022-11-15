//Name: Karthik Yechuri
// This program takes in the input for length of the array and the elements of the array displays whether the inputted elements are even, odd, or not good(If both).
#include <stdio.h>

void find_parity(int *a, int n, int *all_even, int *all_odd);
//Declaring the find_parity void function

int main()
{

  int length, *even, *odd, all_even, all_odd; //initializing the length of the array(length), even and odd pointers, and int type to store if all elements are even or odd
  printf("Enter the length of the array: ");
  scanf("%d", &length); //Taking the input for length

  even = &all_even; //pointer even is pointing towards all_even
  odd = &all_odd;   //pointer odd is pointing towards all_odd

  int numbers[length]; //intializing the array numbers with "length" number of elements

  printf("Enter the elements of the array:");

  for (int i = 0; i < length; i++) //using for loop to store the inputted elements in numbers array
  {
    scanf("%d", &numbers[i]);
  }
  find_parity(numbers, length, even, odd); // calling the void function to know whether the elements are odd, even, or not good

  //Using the if and else statements to print whethere the elements are odd or even
  if (all_odd)
  {
    printf("Good, all elements are odd\n"); //prints good if all elements are odd
    return 0;
  }
  else if (all_even)
  {
    printf("Good, all elements are even\n"); //prints good if all elements are even
    return 0;
  }

  else
  {
    printf("Not good\n"); //prints not good if both the even and odd elememts
    return 0;
  }
}


void find_parity(int *a, int n, int *all_even, int *all_odd)
{
  int b;
  //using for loop to caculate and store in even and odd
  for (int i = 0; i < n; i++)
  {
    b = (*(a++)) % 2; //calculate whethere the element is odd or even

    if (b == 0)
    {
      *all_even = 1; // if it is even it will store 1 in place where pointer all_even is pointing
    }
    else
    {
      *all_odd = 1; // if it is odd it will store 1 in place where pointer all_odd is pointing
    }
  }

  if (*all_even == *all_odd)
  {
    *all_even = 0; // if it is odd and even it will store 0 in place where pointer all_odd and all_even is pointing
    *all_odd = 0;
  }
}
