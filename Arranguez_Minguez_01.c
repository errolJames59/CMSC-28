#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void menu(void);


// Main Function
int main () {
    menu();

    return 0;
}


// Function Def'ns
void menu() {
    // LIST MENU
    int choice;
    puts("============================\n");
    printf("[1] Add Item\n");
    printf("[2] Delete Item\n");
    printf("[3] Display List\n");
    printf("[4] Delete List\n");
    printf("[0] Exit Program\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);
}