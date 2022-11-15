//Name: Karthik Yechuri
/*This program suffix.x takes in the command line argument as input and opens the each inputed file and 
displays the output concattinating the words in the file, max number is taken as the input
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int M; // max number of letters in the suffix
  char str[21]; // str of length 21
  FILE *pf; //file pointer

  printf("Enter the value of M:"); //takes the input for M
  scanf("%d", &M);

  char str1[M + 1];
  char suffix[M + 1];
  strcpy(suffix, "\0");

  for (int i = 1; i < argc; i++)// using for loop to calculate and display suffix
  {
    pf = fopen(argv[i], "r");

    fscanf(pf, "%s", str1);

    while (fscanf(pf, "%s", str) == 1) // using while loop to concatinate and rewind the suffix accordingly
    {
      if (strlen(str1) + strlen(str) <= M)
      {
        strcat(str1, str);
        strcpy(suffix, str1);
      }
      else
        strcpy(suffix, str);
      strcpy(str1, suffix);// copying suffix to str1 for length comparison
    }

    strcpy(str1, "\0");//resetting str1
    printf("%s: %s\n", argv[i], suffix);
    strcpy(suffix, "\0"); // reseting suffix
    fclose(pf); // closing the opend file
  }
  return 0;// program ends with return code 0
}