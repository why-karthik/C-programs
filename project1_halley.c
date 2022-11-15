#include<stdio.h>

int main(){

  int n_of_items, cost_per_item, dollars_avble, money_req;

  printf("Enter item price:");
  scanf("%d", &cost_per_item); 

  if(cost_per_item < 1){
    printf("Invalid price %d\n", cost_per_item);
    printf("Price must be greater than 0\n");
    return 0;
  }
  else{
    printf("Enter number of units:");
    scanf("%d", &n_of_items);

    if(n_of_items < 1){
      printf("Invalid number of units %d\n", n_of_items);
      printf("Number of units must be greater than 0\n");
      return 0;
    }

    else{
      printf("Enter money amount:");
      scanf("%d", &dollars_avble);
      
      if(dollars_avble < 0){
        printf("Invalid money amount %d\n", n_of_items);
        printf("Money amount must be greater than or equal to 0\n");
        return 0;
      }

    }

  }

  
  for(int i = 1; i <= n_of_items; i++){

    money_req += i * cost_per_item;

  }

  if (dollars_avble >= money_req){
    printf("Has enough money!\n");

  }
  else {
    printf("Needs %d dollar(s) to complete the purchase!\n", (money_req - dollars_avble));
  }

return 0;
}