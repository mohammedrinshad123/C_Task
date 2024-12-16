// Write a C program that takes two integers as input and checks if one of them is divisible by the other. if so, print "Divisible", otherwise print "Not Divisible".
#include <stdio.h>

int main()
{
    int num1, num2;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    if (num2 != 0 && num1 % num2 == 0)
    {
        printf("Divisible\n"); // 10, 5
    }
    else if (num1 != 0 && num2 % num1 == 0)
    {
        printf("Divisible\n"); // 7, 3
    }
    else
    {
        printf("Not Divisible\n");
    }

    return 0;
}

// Write a C program that checks if a given number is divisible by both 4 and 6 using logical operators.
#include <stdio.h>

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num % 4 == 0 && num % 6 == 0)
    {
        printf("The number is divisible by both 4 and 6. \n"); // 12
    }
    else
    {
        printf("The number is not divisible by both 4 and 6. /n"); // 14
    }

    return 0;
}

////write a c program to reverse a queue using two queues

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a queue node
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Define the structure of the queue
typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

// Function to create a new queue
Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue *queue)
{
    return queue->front == NULL;
}

// Function to enqueue an element into the queue
void enqueue(Queue *queue, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if (queue->rear == NULL)
    {
        queue->front = queue->rear = temp;
        return;
    }
    queue->rear->next = temp;
    queue->rear = temp;
}

// Function to dequeue an element from the queue
int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue underflow\n");
        return -1;
    }
    Node *temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

// Function to reverse a queue using two additional queues
void reverseQueue(Queue *queue)
{
    Queue *tempQueue1 = createQueue();
    Queue *tempQueue2 = createQueue();

    // Dequeue all elements from the original queue and enqueue into tempQueue1
    while (!isEmpty(queue))
    {
        enqueue(tempQueue1, dequeue(queue));
    }

    // Dequeue from tempQueue1 and enqueue into tempQueue2
    while (!isEmpty(tempQueue1))
    {
        enqueue(tempQueue2, dequeue(tempQueue1));
    }

    // Dequeue from tempQueue2 and enqueue back into the original queue
    while (!isEmpty(tempQueue2))
    {
        enqueue(queue, dequeue(tempQueue2));
    }

    // Free temporary queues
    free(tempQueue1);
    free(tempQueue2);
}

// Function to display the queue
void displayQueue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return;
    }
    Node *temp = queue->front;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main()
{
    Queue *queue = createQueue();

    // Enqueue elements into the queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("Original Queue: ");
    displayQueue(queue);

    // Reverse the queue
    reverseQueue(queue);

    printf("Reversed Queue: ");
    displayQueue(queue);

    return 0;
}

//// implement a stack using arrays and perform push,pop,and peek operations in c.

#include <stdio.h>
#include <stdlib.h>

#define MAX 10 

struct Stack {
    int arr[MAX];
    int top;
};

void initStack(struct Stack* stack) {
    stack->top = -1; 
}

int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %d\n", value);
    } else {
        stack->arr[++stack->top] = value;
        printf("Pushed %d to stack\n", value);
    }
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop\n");
        return -1;
    } else {
        int poppedValue = stack->arr[stack->top--];
        printf("Popped %d from stack\n", poppedValue);
        return poppedValue;
    }
}

int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! Cannot peek\n");
        return -1; 
    } else {
        return stack->arr[stack->top];
    }
}

void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack contents: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack);

    printf("Top element is: %d\n", peek(&stack));

    pop(&stack);
    display(&stack);

    printf("Top element after pop is: %d\n", peek(&stack));

    return 0;
}
 /// write a c program to implement a singly linked list and perform insertion, deletion, and traversal operations.

 #include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;          
    struct Node* next; 
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = value; 
    newNode->next = NULL;    
    return newNode;
}

void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (newNode == NULL) {
        return;
    }
    newNode->next = *head;  
    *head = newNode;       
    printf("Inserted %d at the beginning\n", value);
}

void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (newNode == NULL) {
        return;
    }
    
    if (*head == NULL) {
        *head = newNode;  
        printf("Inserted %d at the end\n", value);
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;  
    }
    temp->next = newNode;  
    printf("Inserted %d at the end\n", value);
}

void deleteNode(struct Node** head, int value) {
    if (*head == NULL) {
        printf("The list is empty\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == value) {
        *head = temp->next;  
        free(temp);         
        printf("Deleted %d from the list\n", value);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list\n", value);
        return;
    }

    prev->next = temp->next;  
    free(temp);               
    printf("Deleted %d from the list\n", value);
}

void traverseList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    
    struct Node* temp = head;
    printf("List contents: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    traverseList(head);

    deleteNode(&head, 20); 
    deleteNode(&head, 50);  

    traverseList(head);

    return 0;
}
