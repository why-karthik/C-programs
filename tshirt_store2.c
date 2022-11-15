///////////////////////////// -------> Author: Karthik Yechuri <--------- ///////////////////
//-----------------------------------------------------------------------------------------//

/* Summary: This project tshirt_store.c can store the organization names, and the inventory of their t-shirts. The user can add the items to the inventory.
 The program repeatedly asks the user for commands one after one, until user presses 'q'.
It can also display the inventory of an organization, or it can display the t-shirts of specific size in the whole inventorry, and it can display the whole inventory. 
If user presses the 'q' command the program clears the inventory and exits the program */

#include "readline.h" //impoting contents from readline.h header file
#include "tshirt.h"   //impoting contents from tshirt.h header file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main() {
	char code;

	struct tshirt *inventory = NULL;

	help();
	printf("\n");

	for (;;) {
		// read operation code
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while(getchar() != '\n') /* skips to end of line */
			;

		// run operation
		switch (code) {
			case 'a':
				inventory = add_to_inventory(inventory);
				break;
			case 'h':
				help();
				break;
			case 'o':
				search_by_organization(inventory);
				break;
			case 's':
				search_by_size(inventory);
				break;
			case 'p':
				print_inventory(inventory);
				break;
			case 'q':
				clear_inventory(inventory);
				return 0;
			default:
				printf("Illegal operation code!\n");
		}
		printf("\n");
	}
}