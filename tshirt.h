/*************************************************************
// HEADER FILE
*************************************************************/

/*THINGS INCLUDED
    - include libraries
    - function declarations
    - structures, global variables, macro definitions
*/

// Include gaurds
#ifndef TSHIRT_H
#define TSHIRT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


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
void help();

#endif