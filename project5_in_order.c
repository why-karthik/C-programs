//This program in_order.c will determine whether the inputed word has letters in alphabetical order
//Name: KARTHIK YECHURI
#include <stdio.h>
#include <string.h>

int in_order(char *word); //in_order funtion declaration

int main(int argc, char *argv[])//Taking the argument from the command line
{ 
  if (argc != 2) //if there are more than or less than 2 arguments program exits
  {
    printf("Incorrect number arguments passed\n");
    return 0;
  }
  
  if (in_order(argv[1]))//Calling in_order, if all letters in order then prints in order, else not in order
  {
    printf("In order\n");
  }
  else
  {
    printf("Not in order\n");
  }

  return 0;//exits program with return code 0
}

int in_order(char *word)
{
  int i = strlen(word);//Takes the legth of the word
  for (int j = 0; j < i; j++)//using for loop to compare and format the letters
  {
    if (((strcmp(&word[j], "A") >= 0) && (strcmp(&word[j], "Z") <= 0)) || ((strcmp(&word[j], "a") >= 0) && (strcmp(&word[j], "z") <= 0)))
    //validating the letters are alphabets from a-z or A-Z
    {
      if (((strcmp(&word[j], "A") >= 0) && (strcmp(&word[j], "Z") <= 0)))
      {
        word[j] = word[j] - 'A' + 'a';//changing capital letters to small
      }
    }
    else
    {
      return 0;
    }
  }
  for (int j = 1; j < i; j++)//using for and if loops to check the order of the letters
  {
    if (word[j - 1] > word[j])
    { 
      return 0;//if not in order returns 0
    }
    else
    {
      continue;
    }
  }
  return 1;//if the letters are in order returns 1
}