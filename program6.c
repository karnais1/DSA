#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

void createTree() {
    int n, i;
    struct Node *newnode;
    struct Node *queue[100];
    int front = 0, rear = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if(n <= 0 || n > 100)
        return;
    printf("Enter elements in level order:\n");
    newnode = (struct Node *)malloc(sizeof(struct Node));
    scanf("%d", &newnode->data);
    newnode->left = NULL;
    newnode->right = NULL;
    root = newnode;
    queue[rear++] = root;
    for(i = 1; i < n; i++) {
        newnode = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &newnode->data);
        newnode->left = NULL;
        newnode->right = NULL;
        if(queue[front]->left == NULL) {
            queue[front]->left = newnode;
        } else {
            queue[front]->right = newnode;
            front++;
        }
        queue[rear++] = newnode;
    }
    printf("Binary tree created successfully.\n");
}

void preorder(struct Node *temp) {
    if(temp == NULL)
        return;
    printf("%d ", temp->data);
    preorder(temp->left);
    preorder(temp->right);
}

void inorder(struct Node *temp) {
    if(temp == NULL)
        return;
    inorder(temp->left);
    printf("%d ", temp->data);
    inorder(temp->right);
}

void postorder(struct Node *temp) {
    if(temp == NULL)
        return;
    postorder(temp->left);
    postorder(temp->right);
    printf("%d ", temp->data);
}

int main() {
    int choice;
    do {
        printf("\n===== BINARY TREE MENU =====\n");
        printf("1. Create Binary Tree\n2. Display Preorder Traversal\n3. Display Inorder Traversal\n4. Display Postorder Traversal\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: createTree(); break;
            case 2:
                if(root == NULL) printf("Tree is Empty\n");
                else { printf("Preorder Traversal: "); preorder(root); printf("\n"); }
                break;
            case 3:
                if(root == NULL) printf("Tree is Empty\n");
                else { printf("Inorder Traversal: "); inorder(root); printf("\n"); }
                break;
            case 4:
                if(root == NULL) printf("Tree is Empty\n");
                else { printf("Postorder Traversal: "); postorder(root); printf("\n"); }
                break;
            case 5: printf("Exit\n"); break;
            default: printf("Invalid choice\n");
        }
    } while(choice != 5);
    return 0;
}