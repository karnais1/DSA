#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    float price;
    char status[15];
};

struct Book *b;
int n;

void create() {
    int i;
    printf("Enter number of books: ");
    scanf("%d", &n);
    b = (struct Book *)malloc(n * sizeof(struct Book));
    for(i = 0; i < n; i++) {
        printf("\nBook %d\n", i + 1);
        printf("Enter ID: ");
        scanf("%d", &b[i].id);
        printf("Enter Title: ");
        scanf(" %[^\n]", b[i].title);
        printf("Enter Author: ");
        scanf(" %[^\n]", b[i].author);
        printf("Enter Price: ");
        scanf("%f", &b[i].price);
        strcpy(b[i].status, "Available");
    }
}

void display() {
    int i;
    printf("\nAvailable Books:\n");
    for(i = 0; i < n; i++) {
        if(strcmp(b[i].status, "Available") == 0) {
            printf("\nID: %d\nTitle: %s\nAuthor: %s\nPrice: %.2f\nStatus: %s\n", 
                   b[i].id, b[i].title, b[i].author, b[i].price, b[i].status);
        }
    }
}

void search() {
    int id, i;
    printf("Enter Book ID: ");
    scanf("%d", &id);
    for(i = 0; i < n; i++) {
        if(b[i].id == id) {
            printf("\nID: %d\nTitle: %s\nAuthor: %s\nPrice: %.2f\nStatus: %s\n", 
                   b[i].id, b[i].title, b[i].author, b[i].price, b[i].status);
            return;
        }
    }
    printf("Book not found.\n");
}

void issueBook() {
    int id, i;
    printf("Enter Book ID: ");
    scanf("%d", &id);
    for(i = 0; i < n; i++) {
        if(b[i].id == id) {
            if(strcmp(b[i].status, "Available") == 0) {
                strcpy(b[i].status, "Issued");
                printf("Book issued successfully.\n");
            } else {
                printf("Book is already issued.\n");
            }
            return;
        }
    }
    printf("Book not found.\n");
}

void returnBook() {
    int id, i;
    printf("Enter Book ID: ");
    scanf("%d", &id);
    for(i = 0; i < n; i++) {
        if(b[i].id == id) {
            if(strcmp(b[i].status, "Issued") == 0) {
                strcpy(b[i].status, "Available");
                printf("Book returned successfully.\n");
            } else {
                printf("Book is already available.\n");
            }
            return;
        }
    }
    printf("Book not found.\n");
}

int main() {
    int choice;
    do {
        printf("\n===== LIBRARY MENU =====\n");
        printf("1. Add Book Records\n2. Display All Book Records\n3. Search Book by ID\n");
        printf("4. Issue a Book\n5. Return a Book\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: printf("Exit\n"); break;
            default: printf("Invalid choice\n");
        }
    } while(choice != 6);
    free(b);
    return 0;
}