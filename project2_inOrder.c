/* This program takes the input word from the user and returns whether the alphabets entered are in order or not*/
/* Karthik Yechuri*/
#include <stdio.h>

int main()
{

  printf("Input:");
  /* declaring the variable type of the word inputed */
  char input_letter = getchar();
  int letter_count = 0;
  /* used to count the number of letters that are read */

  while (input_letter != '\n')
  /* loop comtinues until the the user presses the new line*/
  {

    letter_count++;
    /*increases the letter count every time the loop occurs*/
    char ch_1, ch_2;
    /* declarathing two char type variables to store the letters read by the input_letter*/

    if (input_letter >= 'A' && input_letter <= 'Z')
    {
      /* using if statements to change the given alphabet in to a small letter*/
      input_letter = input_letter - 'A' + 'a';
    }

    if (input_letter < 'a' || input_letter > 'z')
    {
      /* if the given input is not a alphabet then the function exits with retuen 0 and printing not in order*/
      printf("Output: Not in order\n");
      return 0;
    }

    ch_1 = input_letter;
    /* storing the input letter in to ch_1*/

    if (letter_count > 1)
    {
      /*using the if statements to compare the letters and determine the order*/

      if (ch_1 < ch_2)
      {
        printf("Output: Not in order\n");
        return 0;
      }
    }

    ch_2 = input_letter;
    /* storing the input letter in ch_2 to compare it with ch_1 initialized before the if statements*/

    input_letter = getchar();
    /* reads the letter from the input*/
  }

  printf("Output: In order\n");
  return 0;
}
