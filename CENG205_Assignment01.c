// CENG205 Data Structures Assignment 1
// Alper Kara 181180042

#include <stdio.h>

// Global definition for maximum size of queues.
#define SIZE 10

// User defined struct called "element".
typedef struct{
    int value;
}element;

// Created a queue as an array from type element.
// Assigned the rear and front of the queue to -1.
element queue[SIZE];
int front = -1;
int rear = -1;

// Prints the values in the queue.
// Checks if the queue is empty each time.
void print_queue(){
    if(front == rear){
        printf("Queue is Empty.\n");
    }
    else{
        
        for (int i = 0; i < rear+1 ; i++) {
            printf("%d", queue[i]);
        }
    }
}

// Enqueues elements to the queue.
// PS: I couldn't figure out how to enqueue in ascending order 
//     without using any sorting function. 
int enqueue(element item){    
    if(rear == SIZE-1){
        printf("Queue is full. %d wasn't added.\n", item);
        return 0;

    }else{
        queue[++rear]=item;
        return 1;
    }
    
}

// Dequeues element from queue. 
void dequeue(){
    if(front == rear){
        printf("Queue is Empty.\n");
    }
    queue[++front];
    rear = rear -1;

}

int main(){

    int selection;
    do{
        // Item to be added into the queue.
        element addItem;

        // Menu
        printf("\n---------OPTIONS--------\n");
        printf("0- Print all elements of the queue.\n");
        printf("1- Add an element into the queue.\n");
        printf("2- Remove element from the queue.\n");
        printf("3- Exit\n");
        printf("Select (0-3)? : ");
        scanf("%d", &selection);
        switch(selection)
        {
            case 0:
                print_queue();
                break;
            case 1:
                printf("Add element : ");
                scanf("%d", &addItem);
                enqueue(addItem);
                if(enqueue(addItem) == 1){
                    printf("The element has been successfully added.\n");
                }else if(enqueue(addItem) == 0){
                    printf("The element adding is failed.\n");
                }
                break;
            case 2:
                dequeue();
                break;
            case 3:
                return 0;
            
        }

    }while(selection != 3);
}