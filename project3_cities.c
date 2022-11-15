//This program takes input for no of citites, no of drones, and a list of location of drones and distance the drone can move. Then it displays the cities that drones can reach.
//Name: Karthik Yechuri
#include <stdio.h>

int main()
{
  int i = 0, N, M; // N is the number of cities, M is the number of drones.

  printf("Enter number of cities (N):");
  scanf("%d", &N); // Taking the input for number of cities(N)

  if (0 >= N || N > 100)
  //validating the input N to be in the range[1,100]
  {
    printf("Invaid number of cities %d\n", N);
    printf("Must be in range[1,100]\n");
    return 0; //The program exits by printing the error message
  }

  printf("Enter number of drones (M):");
  scanf("%d", &M); // Taking the input for number of drones(M)

  if (0 >= M || M > 100)
  //validating the input M to be in the range[1,100]
  {
    printf("Invaid number of drones %d\n", M);
    printf("Must be in range[1,100]\n");
    return 0; //The program exits by printing the error message
  }

  int C[N], D[N], city[N];
  // Arrays C is used to store the city in which drone present and D is used to store the distance that the drone can travel, the city is an array with length equal to no of cities

  while (i < N)
  {
    // initializing all the elements of the array to zero
    city[i] = 0;
    i++;
  }

  printf("Enter drone list:\n");

  for (int i = 0; i < M; i++)
  // using the for loop to take the input into C, D arrays
  {
    scanf("%d%d", &C[i], &D[i]);
    city[C[i] - 1] = 1; //storing that vaule in the city that the drone is present
    if (0 >= C[i] || N < C[i] || 0 >= D[i] || N < D[i])
    {
      // Validating the input for city the drone present and the distance drone can move
      printf("Invaid list of drones\n");
      printf("Drone location and travel distance must be in the range [1,%d]\n", N);
      return 0; //exiting the program displaying the error message
    }
  }

  for (int i = 0; i < M; i++)
  {
    //using the for loop to move the drone to the right and storing the city in array city
    int x = C[i] + D[i];
    while (x <= N)
    {
      city[x - 1] = 1;
      x = x + D[i];
    }
  }

  for (int i = 0; i < M; i++)
  {
    //using the for loop to move the drone to the left and storing the city in array city
    int x = C[i] - D[i];
    while (x >= 0)
    {
      city[x - 1] = 1;
      x = x - D[i];
    }
  }

  int j = 0; //initializing value to zero
  printf("Cities reached by drone:\n");
  while (j < N)
  {
    // using while loop to print the cities in which the drones can travel
    if (city[j] == 1)
    {
      printf("%d ", (j + 1));
    }
    j++;
  }

  printf("\n");

  return 0;
}
