/* This program takes the input for unit price of an item, number of items and the money available near the purchaser and returns the more money required to purchase the items if they are short of money else it will print they have enough money*/
/* Karthik Yechuri*/
#include <stdio.h>

int main()
{

  int n_of_items, cost_per_item, dollars_avble, money_req;
  /* declaring the variables in int type*/

  printf("Enter item price:");
  scanf("%d", &cost_per_item); /* Taking the input from user for unit price of item*/

  if (cost_per_item < 1)
  {
    /* Validating the input for the prices has to be greater than zero*/
    printf("Invalid price %d\n", cost_per_item);
    printf("Price must be greater than 0\n");
    return 0;
  }
  else
  {
    printf("Enter number of units:");
    scanf("%d", &n_of_items);
    /* taking the input for no of units*/

    if (n_of_items < 1)
    {
      /* validating the input for no of items to be greater than zero*/
      printf("Invalid number of units %d\n", n_of_items);
      printf("Number of units must be greater than 0\n");
      return 0;
    }

    else
    {
      printf("Enter money amount:");
      scanf("%d", &dollars_avble);
      /* taking the input for dollars available*/

      if (dollars_avble < 0)
      {
        /* exiting the program if the dollars available are less than zero*/
        printf("Invalid money amount %d\n", dollars_avble);
        printf("Money 0 samount must be greater than or equal to 0\n");
        return 0;
      }
    }
  }

  for (int i = 1; i <= n_of_items; i++)
  {
    /* calculating the total cost for the items purchased using for loop to change the price*/

    money_req += i * cost_per_item;
    /* cost of the item changes for the no of items purchased, it is increased by the nth item it was purchased*/
  }

  if (dollars_avble >= money_req)
  {
    printf("Has enough money!\n");
    /* prints the message if the user has enough money to purchase*/
  }
  else
  {
    printf("Needs %d dollar(s) to complete the purchase!\n", (money_req - dollars_avble));
    /* prints the remaining amount required to purchase the total no of desired items*/
  }

  return 0;
}
