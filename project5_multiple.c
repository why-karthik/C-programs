//This program multiple.c will determine whether the inputed number is multiple of 11 or not
//Name: KARTHIK YECHURI
#include <stdio.h>
#include <string.h>

int main()
{
  int odd_sum = 0, even_sum = 0, total; //total(used for difference between odd and even place)
  char num[1001];                       //num array using 1001,, because we can take a max of 1000 charecters
  printf("Enter the value of X:");
  scanf("%s", num); //taking the input in to num

  for (int i = 0; num[i] != num[1000]; i++)
  {
    if (i % 2 == 0)
    {                                       //If position is even, add it to even sum
      even_sum = even_sum + (num[i] - '0'); //Calculating the sum of even positions
    }
    else                                  //If position is odd, add it to odd sum
      odd_sum = odd_sum + (num[i] - '0'); //Calculating the sum of odd positions
  }

  total = even_sum - odd_sum; //difference

  if (total % 11 == 0)
  { //Checking if difference is a multiple of 11
    for (int i = 0; num[i] != num[1000]; i++)//If divisible by 11, prints until white space or"\0"
    {
      printf("%c", num[i]);
    }
    printf(" is a multiple of 11\n"); 
  }
  else
  {
    for (int i = 0; num[i] != num[1000]; i++) // If not divisible by 11
    {
      printf("%c", num[i]);
    }
    printf(" is not a multiple of 11\n");
  }
  return 0;
}