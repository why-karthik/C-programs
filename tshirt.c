/*************************************************************
//SOURCE FILE FOR OTHER FUNCTIONS
*************************************************************/


#include "tshirt.h"
#include "readline.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ORG_NAME_LEN 50
#define SIZE_LEN 3

void help() {
	printf("List of operation codes:\n");
	printf("\t'a' for adding a t-shirt to the inventory;\n");
	printf("\t'h' for help;\n");
	printf("\t'o' for searching t-shirts by organization;\n");
	printf("\t's' for searching t-shirts by size;\n");
	printf("\t'p' for printing the inventory;\n");
	printf("\t'q' for quit.\n");
}

//////////////////////////
// function definitions //
//////////////////////////

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

	struct tshirt *cur;
    struct tshirt *pre;
	//used to point to the nodes
	
	// Searches whether the specific organization name and t-shirt already exists
	for(cur = inventory; cur != NULL ; cur = cur -> next){

		if((strcmp(cur->size, new_node->size) == 0) && (strcmp(cur->org_name, new_node->org_name) == 0) ){
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
	// Adding the inputed values to the inventory in alphabetical order

    for(pre = NULL, cur = inventory; cur != NULL && (strcmp(cur->org_name, new_node->org_name) < 0); pre = cur, cur = cur->next);

    if(cur == NULL){
        pre->next = new_node;
        new_node->next = NULL;
        return inventory;
    }   

    if(strcmp(cur->org_name, new_node->org_name) == 0){
        for( ; cur != NULL && (strcmp(cur->size, new_node->size) < 0); pre = cur, cur = cur->next);

        if(pre == NULL){
            new_node->next = inventory;
            return new_node;
        }

        pre->next = new_node;
        new_node->next = cur;
        return inventory;

    }
    
    if(pre == NULL){
        new_node->next = inventory;
        return new_node;
    }

    pre->next = new_node;
    new_node->next = cur;
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

