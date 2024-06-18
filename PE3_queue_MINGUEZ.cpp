// Errol James B. Minguez
// 1 - BSCS
// CMSC 28 - PE 3 - Queue Application and Implementation

// header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// STRUCTURE FOR CUSTOMER INFORMATION NODE
typedef struct customer {
    char surname[30];
    float pay;
    struct customer *next;
} Customer;

// STRUCTURE FOR QUEUE NODE
typedef struct queue {
    Customer *front;
    Customer *rear;
} Queue;    


// INITIALIZES AN EMPTY QUEUE AND RETURNS A POINTER TO THE NEWLY CREATED QUEUE
Queue *INIT() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Returns true if the queue is empty, otherwise false
bool empty(Queue *queue) {
    return (queue->front == NULL);
}

// This function displays the next order to be served
void Front(Queue *queue) {
    if (empty(queue)) {
        printf("\nThe QUEUE is EMPTY. No orders to serve.\n");
    } else {
        Customer *name = queue->front;
        printf("\nNext order: For [%s] with total amount payable of [%.2f].\n", name->surname, name->pay);
    }
}

// Function that adds a customer to the queue
void enqueue(Queue *queue, char surname[], float pay) {
    
    // newCustomer node
    Customer *newCustomer = (Customer*)malloc(sizeof(Customer));
    if (newCustomer == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // The customer's surname and pay are copied to the new customer node
    strcpy(newCustomer->surname, surname);
    newCustomer->pay = pay;
    newCustomer->next = NULL;

    // If the queue is empty, the new customer will be the front and rear
    if (queue->rear == NULL) {
        queue->front = newCustomer;
        queue->rear = newCustomer;
    } else {
        // Otherwise, the new customer will be the rear
        queue->rear->next = newCustomer;
        queue->rear = newCustomer;
    }
}

// Function that serves the customer who is first in line
void dequeue(Queue *queue) {
    if (empty(queue)) {
        printf("\nThe QUEUE is EMPTY. No orders to serve.\n");
    } else {
        Customer *temp = queue->front;
        printf("\nNow serving [%s] with total amount payable of [%.2f].\n", temp->surname, temp->pay);
        queue->front = queue->front->next;
        free(temp);
    }
}

// Function that displays the description of the program
void description(){
    printf("||-------------------------------------------------------------||\n");
    printf("||           WELCOME TO MINGUEZ.CO SHOPPING! ENJOY!            ||\n");
    printf("||-------------------------------------------------------------||\n");
}

// Display menu, then return the user's choice
int menu(int choice) {
    printf("\nPlease select an option: \n");
    printf("[1] Fall in line\n[2] Serve customer\n[3] Next Customer\n[4] Closing time\n[0] Exit\nEnter choice: ");
    scanf("%d", &choice);
    return choice;
}

// This is the main function
int main() {
    int choice;
    // Initializes the queue
    Queue *queue = INIT();
    description();
    struct customer info;

    // Do-while loop that displays the menu and executes the user's choice
    do {
        choice = menu(choice);
        switch (choice)
        {
        case 1:
            // Adds a customer to the queue
            printf("\nEnter surname: ");
            scanf("%s", info.surname);
            printf("Enter amount to pay: ");
            scanf("%f", &info.pay);
            enqueue(queue, info.surname, info.pay);
            break;
    
        case 2:
            dequeue(queue);
            break;

        case 3:
            Front(queue);
            break;

        case 4:
            // If the queue is not empty, the program will serve all customers, and loops until the queue is empty
            do {
                dequeue(queue);
            } while (!empty(queue));
            printf("\nThe QUEUE is EMPTY. No customer/s to serve.\n");
            break;

        case 0:
            system("cls");
            printf("||-------------------------------------------------------------||\n");
            printf("||           THANK YOU FOR SHOPPING AT MINGUEZ.CO!             ||\n");
            printf("||-------------------------------------------------------------||\n");
            break;

        default:
            printf("\nPlease select a valid option.\n");
            break;
        }
    } while (choice != 0);

    return 0;
}