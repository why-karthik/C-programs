///////////////////////////// -------> Author: Karthik Yechuri <--------- ///////////////////
//-----------------------------------------------------------------------------------------//

/* Summary: This project tshirt_store.c can store the organization names, and the inventory of their t-shirts. The user can add the items to the inventory.
 The program repeatedly asks the user for commands one after one, until user presses 'q'.
It can also display the inventory of an organization, or it can display the t-shirts of specific size in the whole inventorry, and it can display the whole inventory. 
If user presses the 'q' command the program clears the inventory and exits the program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//////////////////////
// data definitions //
//////////////////////

#define ORG_NAME_LEN 50
#define SIZE_LEN 3

struct tshirt {
	char org_name[ORG_NAME_LEN+1];
	char size[SIZE_LEN+1];
	double price;
	int quantity;
	struct tshirt *next;
};

/////////////////////////
// function prototypes //
/////////////////////////

struct tshirt * add_to_inventory(struct tshirt *inventory);
void search_by_organization(struct tshirt *inventory);
void search_by_size(struct tshirt *inventory);
void print_inventory(struct tshirt *inventory);
void clear_inventory(struct tshirt *inventory);
int read_line(char str[], int n);
void help();

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

//////////////////////////
// function definitions //
//////////////////////////


// Prints the information that tells about the functions of each command
void help() {
	printf("List of operation codes:\n");
	printf("\t'a' for adding a t-shirt to the inventory;\n");
	printf("\t'h' for help;\n");
	printf("\t'o' for searching t-shirts by organization;\n");
	printf("\t's' for searching t-shirts by size;\n");
	printf("\t'p' for printing the inventory;\n");
	printf("\t'q' for quit.\n");
}


// Adds the information inputed by the user in to the inventory
struct tshirt * add_to_inventory(struct tshirt *inventory) {

	struct tshirt *new_node;
	new_node = malloc(sizeof(struct tshirt));

	if( new_node == NULL){
		printf("Out of memory malloc failed\n");
		return inventory;
	}

	printf("Enter student organization name: ");
	read_line(new_node->org_name, ORG_NAME_LEN+1);

	printf("Enter t-shirt size: ");
	read_line(new_node->size, SIZE_LEN+1);

	struct tshirt *p;
	
	// Searches whether the specific organization name and t-shirt already exists
	for(p = inventory; p != NULL ; p = p -> next){

		if((strcmp(p->size, new_node->size) == 0) && (strcmp(p->org_name, new_node->org_name) == 0) ){
			printf("T-shirt already exists in the inventory!\n");
			return inventory;
		}

	}

	printf("Enter price: ");
	scanf("%lf", &new_node->price);

	printf("Enter the quantity: ");
	scanf("%d", &new_node->quantity);

	if(inventory == NULL){
		new_node -> next = NULL;
		return new_node;
	}
	// Adding the inputed values to the inventory at the end of the inventory

	struct tshirt *q;

	for(q = inventory; q->next != NULL; q = q->next);
	
	q->next = new_node;
	new_node->next = NULL;

	return inventory;
}


// Prints the inventory of the inputed organization from the user
void search_by_organization(struct tshirt *inventory) {

	struct tshirt *new_node;
	new_node = malloc(sizeof(struct tshirt));

	if( new_node == NULL){
		printf("Out of memory malloc failed\n");
		return;
	}

	printf("Enter student organization name: ");
	read_line(new_node->org_name, ORG_NAME_LEN+1);

	if(inventory == NULL){
		printf("No t-shirt found!\n");
		return;
	}

	struct tshirt *p;
	// Searching whether the inputed organization exists
	for(p = inventory; p != NULL; p = p -> next){

		if(strcmp(p->org_name, new_node->org_name) != 0){
			if((p->next) == NULL){
				printf("No t-shirt found!\n");
				return ;
			}
			else{
			continue;
			}
		}
		else{
			new_node = p;
			break;
		}

	}
	
	printf("|----------------------------------------------------|-----|-------|------|\n");
	printf("| Student organization                               | Sz. | Price | Qty. |\n");
	printf("|----------------------------------------------------|-----|-------|------|\n");
	for(p = inventory; p != NULL; p = p -> next){
		if(strcmp(p->org_name, new_node->org_name) == 0){
			printf("| %-50s | %-3s | %5.2f | %4d |\n", p->org_name, p->size, p->price, p->quantity);
		}
	}
	printf("|----------------------------------------------------|-----|-------|------|\n");


}

// Prints the inventory based on the size inputed by the user
void search_by_size(struct tshirt *inventory) {
	

	struct tshirt *new_node;
	new_node = malloc(sizeof(struct tshirt));

	if( new_node == NULL){
		printf("Out of memory malloc failed\n");
		return;
	}
 
	printf("Enter t-shirt size:");
	read_line(new_node->size, SIZE_LEN+1);

	
	if(inventory == NULL){
		printf("No t-shirt found!\n");
		return;
	}

	struct tshirt *p;

	// Searching whether the inputed size exists in the inventory
	for(p = inventory; p != NULL; p = p->next){
		if(strcmp(p->size, new_node->size) != 0){
			if(p->next == NULL){
				printf("No t-shirt found!\n");
				return ;
			}
		}
		else{
			break;
		}
	}

	printf("|----------------------------------------------------|-----|-------|------|\n");
	printf("| Student organization                               | Sz. | Price | Qty. |\n");
	printf("|----------------------------------------------------|-----|-------|------|\n");
	for(p = inventory; p!= NULL; p = p->next){
		if(strcmp(p->size, new_node->size) == 0){
			printf("| %-50s | %-3s | %5.2f | %4d |\n", p->org_name, p->size, p->price, p->quantity);
		}
	}
	printf("|----------------------------------------------------|-----|-------|------|\n");
}

// Prints the whole inventory
void print_inventory(struct tshirt *inventory) {

	
	if(inventory == NULL){
		printf("No t-shirt found!\n");
		return;
	}

	struct tshirt *p;

	// printing the whole inventory

	printf("|----------------------------------------------------|-----|-------|------|\n");
	printf("| Student organization                               | Sz. | Price | Qty. |\n");
	printf("|----------------------------------------------------|-----|-------|------|\n");
	for(p = inventory; p!= NULL; p = p->next){	
		printf("| %-50s | %-3s | %5.2f | %4d |\n", p->org_name, p->size, p->price, p->quantity);
	}
	printf("|----------------------------------------------------|-----|-------|------|\n");
}

// Clears the inventory
void clear_inventory(struct tshirt *inventory) {

	struct tshirt *p;

	while(inventory != NULL){
		p = inventory;
		inventory = inventory->next;
		free(p); 
		// clearing the inventory using free()
	}
}

// Used to read the input from the user
int read_line(char str[], int n) {
	int ch, i=0;

	while (isspace(ch = getchar()))
		;
	str[i++] = ch;
	while ((ch = getchar()) != '\n') {
		if (i < n)
			str[i++] = ch;    
	}
	str[i] = '\0';
	return i;
}

