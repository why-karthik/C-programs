/*This program takes the input furniture type and the number of years rented from the user and calculated the total rent for the furniture
Name: Karthik Yechuri*/

#include<stdio.h>

int main(){

  int furniture_type, months_rent, due_amount, minimum_rent, rent_per_month ,max_rent_year;


  /* printing the information to let the user know the numbers assigned to furniture types*/
  printf("Please select from the following menu: 1. Sofa, 2. Loveseat, 3. 4 Post Bed, 4. Dresser 5. Kitchen Table\n");


  printf("Enter furniture selection:"); 
  scanf("%d", &furniture_type); /* taking the input from the user for furniture type*/



  if (furniture_type > 0 && furniture_type <=5){ 
    /*input validation for furniture type using if-else*/
    printf("Enter months rented:");
    scanf("%d", &months_rent); /* taking input from the user for no of months to calculate the rent*/

    if (months_rent <= 0){ 
      /* input validation for months rented using if*/
      printf("Invalid input. Enter a positive number for months rented\n");
      return 0; /*Exits the code*/
    }
  }
  else{
    printf("Invalid input. The input should be in the range of 1 to 5\n");
    return 0;
  }

  switch(furniture_type){ 
    /* using switch for assigning the min rent, maximum rent and rent per month for their respective furniture type.*/

    case 1:
      rent_per_month = 45;
      minimum_rent = 60;
      max_rent_year = 450;
      break;

    case 2:
      rent_per_month = 30;
      minimum_rent = 45;
      max_rent_year = 280;
      break;

    case 3:
      rent_per_month = 38;
      minimum_rent = 55;
      max_rent_year = 350;
      break;

    case 4:
      rent_per_month = 25;
      minimum_rent = 28;
      max_rent_year = 200;
      break;

    case 5:
      rent_per_month = 20;
      minimum_rent = 35;
      max_rent_year = 220;
      break;

  }

    
    
    /*calculating the the due amount for the user inputed data*/

    /* using if and else statements to calculate due_amount to satisy all the conditions*/

    if (months_rent < 12){
      /* calculating rent if months is less than 12*/

      due_amount = minimum_rent + rent_per_month * (months_rent - 1);

      if (due_amount > max_rent_year){
        due_amount = max_rent_year;
      }
      
    }

    else {
      /* calculating the rent if months is greater than or equal to 12*/
      due_amount = max_rent_year * (months_rent/12) + rent_per_month * (months_rent % 12);

      if (max_rent_year < (rent_per_month * (months_rent % 12))){
        due_amount = max_rent_year * (months_rent/12 + 1);
      }
    }

    printf("Amount due ($): %d\n", due_amount);/* prints the final rent due*/

  

  return 0;




}