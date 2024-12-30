// Write a C program to implement a stack using an array.
#include <stdio.h>
#include <stdlib.h>

#define MAX 5  

int stack[MAX];
int top = -1; 

int isFull() {
    if (top == MAX - 1)
        return 1; 
    return 0;
}

int isEmpty() {
    if (top == -1)
        return 1; 
    return 0;
}

void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Unable to push %d\n", value);
    } else {
        stack[++top] = value;  
        printf("Pushed %d onto the stack\n", value);
    }
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Unable to pop\n");
        return -1;  
    } else {
        int value = stack[top--];  
        printf("Popped %d from the stack\n", value);
        return value;
    }
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty! No element to peek\n");
        return -1;  
    } else {
        return stack[top];  
    }
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);  

    display();  

    printf("Peek: %d\n", peek()); 

    pop(); 
    pop(); 

    display(); 

    return 0;
}

// Write a C program to find the maximum element in a linked list.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int findMax(struct Node* head) {
    if (head == NULL) {
        printf("The linked list is empty.\n");
        return -1;  
    }
    int max = head->data;
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    append(&head, 10);
    append(&head, 20);
    append(&head, 35);
    append(&head, 15);
    append(&head, 50);

    display(head);

    int max = findMax(head);
    if (max != -1) {
        printf("The maximum element in the linked list is: %d\n", max);
    }

    return 0;
}

// Give an array of integers, find the second largest element.
// Return -1 if there is no second largest element.
#include <stdio.h>

int findSecondLargest(int arr[], int n) {
    if (n < 2) {
        return -1;
    }

    int firstLargest = -1, secondLargest = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > firstLargest) {
            secondLargest = firstLargest; 
            firstLargest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != firstLargest) {
            secondLargest = arr[i];
        }
    }

    return secondLargest == -1 ? -1 : secondLargest;
}

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = findSecondLargest(arr, n);
    if (result == -1) {
        printf("No second largest element.\n");
    } else {
        printf("Second largest element is: %d\n", result);
    }

    return 0;
}
