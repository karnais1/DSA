#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff, power;
    struct node *next;
};

struct node* create() {
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->next = head;
    return head;
}

void insert(struct node *head, int c, int p) {
    struct node *newNode, *temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->coeff = c;
    newNode->power = p;
    temp = head;
    while (temp->next != head)
        temp = temp->next;
    newNode->next = head;
    temp->next = newNode;
}

void read(struct node *head) {
    int n, i, c;
    printf("Enter degree: ");
    scanf("%d", &n);
    for (i = n; i >= 0; i--) {
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &c);
        if (c != 0)
            insert(head, c, i);
    }
}

void display(struct node *head) {
    struct node *temp = head->next;
    if (temp == head) {
        printf("0\n");
        return;
    }
    while (temp != head) {
        printf("%dx^%d", temp->coeff, temp->power);
        temp = temp->next;
        if (temp != head)
            printf(" + ");
    }
    printf("\n");
}

void add(struct node *p, struct node *q, struct node *sum) {
    struct node *a = p->next;
    struct node *b = q->next;
    while (a != p && b != q) {
        if (a->power == b->power) {
            int sumCoeff = a->coeff + b->coeff;
            if (sumCoeff != 0)
                insert(sum, sumCoeff, a->power);
            a = a->next;
            b = b->next;
        } else if (a->power > b->power) {
            insert(sum, a->coeff, a->power);
            a = a->next;
        } else {
            insert(sum, b->coeff, b->power);
            b = b->next;
        }
    }
    while (a != p) {
        insert(sum, a->coeff, a->power);
        a = a->next;
    }
    while (b != q) {
        insert(sum, b->coeff, b->power);
        b = b->next;
    }
}

int main() {
    struct node *poly1, *poly2, *polysum;
    poly1 = create();
    poly2 = create();
    polysum = create();
    printf("Enter POLY1\n");
    read(poly1);
    printf("\nEnter POLY2\n");
    read(poly2);
    printf("\nPOLY1 = ");
    display(poly1);
    printf("POLY2 = ");
    display(poly2);
    add(poly1, poly2, polysum);
    printf("POLYSUM = ");
    display(polysum);
    return 0;
}