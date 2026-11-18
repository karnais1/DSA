#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void addJob() {
    int job;
    if(rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        printf("Enter Print Job ID: ");
        scanf("%d", &job);
        if(front == -1)
            front = 0;
        queue[++rear] = job;
        printf("Print job added successfully.\n");
    }
}

void processJob() {
    if(front == -1 || front > rear) {
        printf("Queue Underflow\n");
    } else {
        printf("Processed Print Job: %d\n", queue[front]);
        front++;
        if(front > rear)
            front = rear = -1;
    }
}

void countJobs() {
    if(front == -1)
        printf("Number of waiting jobs: 0\n");
    else
        printf("Number of waiting jobs: %d\n", rear - front + 1);
}

int main() {
    int choice;
    do {
        printf("\n===== PRINTER QUEUE MENU =====\n");
        printf("1. Add Print Job\n2. Process Print Job\n3. Number of Waiting Jobs\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addJob(); break;
            case 2: processJob(); break;
            case 3: countJobs(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while(choice != 4);
    return 0;
}