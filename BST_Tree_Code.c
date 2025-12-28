#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>  
#include <fcntl.h> // Added for _setmode

#ifdef _WIN32
#include <windows.h>
#include <conio.h> // Includes _getch() for single character input
#define SLEEP(ms) Sleep(ms)
#else
#define SLEEP(ms) usleep(ms * 1000)
#include <termios.h>
#include <unistd.h>

// Non-Windows getch implementation
int getch()
{
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
#endif

// Clear screen function
void clear()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// ANSI color codes for cross-platform
#ifdef _WIN32
// Windows color definitions
#define RESET 7
#define RED 12
#define GREEN 10
#define YELLOW 14
#define BLUE 9
#define MAGENTA 13
#define CYAN 11
#define WHITE 15

void setColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Windows-specific getch wrapper
int getch_wrapper()
{
    return _getch();
}
#else
// ANSI color codes for Unix-like systems
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

void setColor(const char *color)
{
    printf("%s", color);
}

// Unix-specific getch wrapper
int getch_wrapper()
{
    return getch();
}
#endif

// Typing animation effect
void typewriter(const char *text, int delay)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        printf("%c", text[i]);
        fflush(stdout);
        SLEEP(delay);
    }
}

// Loading animation
void loadingAnimation(const char *message, int duration)
{
    printf("\n");
    for (int i = 0; i < duration; i++)
    {
        printf("\r%s [", message);
        for (int j = 0; j < 20; j++)
        {
            if (j < i * 20 / duration)
            {
#ifdef _WIN32
                setColor(GREEN);
                printf("#");
                setColor(RESET);
#else
                printf(GREEN "#" RESET);
#endif
            }
            else
            {
                printf(" ");
            }
        }
        printf("] %d%%", (i * 100) / duration);
        fflush(stdout);
        SLEEP(50);
    }
    printf("\t\r%s [####################] 100%%\n", message);
}

// Data Structure Definitions

// Node for linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Stack structure
typedef struct
{
    int *array;
    int top;
    int capacity;
} Stack;

// Queue structure
typedef struct
{
    int *array;
    int front;
    int rear;
    int capacity;
} Queue;

// Binary Tree Node
typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function prototypes
void printHeader();
void printMenu();
void linkedListDemo();
void stackDemo();
void queueDemo();
void binaryTreeDemo();
void visualizeLinkedList(Node *head);
void visualizeStack(Stack *stack);
void visualizeQueue(Queue *queue);
void visualizeBinaryTree(TreeNode *root, int space);
void printRetroBox(const char *title, const char *content);
void flashText(const char *text, int times, int delay);

// Main function
int main()
{
    int choice;

#ifdef _WIN32
    system("chcp 65001 > nul");
#endif

    do
    {
        clear();
        printHeader();
        printMenu();

#ifdef _WIN32
        setColor(CYAN);
#else
        setColor(CYAN);
#endif

        printf("\n\tEnter your choice (0-4): ");

#ifdef _WIN32
        setColor(RESET);
#else
        setColor(RESET);
#endif

        // Use scanf for integer input, which works well
        if (scanf("%d", &choice) != 1)
        {
            // Handle non-integer input to prevent infinite loop
            while (getchar() != '\n')
                ;
            choice = -1; // Set to invalid choice
        }

        switch (choice)
        {
        case 1:
            linkedListDemo();
            break;
        case 2:
            stackDemo();
            break;
        case 3:
            queueDemo();
            break;
        case 4:
            binaryTreeDemo();
            break;

        case 0:
            clear();
            printHeader();
            flashText("Thank you for using Data Structures Console Application!", 3, 200);
            printf("\n\n");
            loadingAnimation("\tExiting program", 50);
            clear();
            break;
        default:
#ifdef _WIN32
            setColor(RED);
#else
            setColor(RED);
#endif
            printf("\n\t\t\tInvalid choice! Please try again.");
#ifdef _WIN32
            setColor(RESET);
#else
            setColor(RESET);
#endif
            SLEEP(1000);
        }
    } while (choice != 0);

    return 0;
}

void printHeader()
{
    clear();

// ASCII Art Header with animation
#ifdef _WIN32
    setColor(MAGENTA);
#else
    setColor(MAGENTA);
#endif

    printf("\n");
    // These extended characters should now display correctly on Windows
    printf("\t╔══════════════════════════════════════════════════════════╗\n");
    printf("\t║                                                          ║\n");

    // Animated title text
    char title[] = "\t║     ADVANCED DATA STRUCTURES CONSOLE APPLICATION         ║";
    typewriter(title, 30);

    printf("\n\t║                                                          ║\n");
    printf("\t╚══════════════════════════════════════════════════════════╝\n\n");

#ifdef _WIN32
    setColor(CYAN);
#else
    setColor(CYAN);
#endif

    char subtitle[] = "\t   \t    Eat Code Coode Coooode Sleep!";
    typewriter(subtitle, 35);

    printf("\n");

#ifdef _WIN32
    setColor(RESET);
#else
    setColor(RESET);
#endif
}

void printMenu()
{
    printRetroBox("Main Menu",
                  "1. Linked List Demonstration\n"
                  "2. Stack Implementation\n"
                  "3. Queue Implementation\n"
                  "4. Binary Tree Visualization\n"
                  "0. Exit Program");
}

void printRetroBox(const char *title, const char *content)
{
#ifdef _WIN32
    setColor(YELLOW);
#else
    setColor(YELLOW);
#endif

    // These extended characters should now display correctly on Windows
    printf("\n\t┌──────────────────────────────────────────────────────────┐\n");
    printf("\t│ %-56s │\n", title);
    printf("\t├──────────────────────────────────────────────────────────┤\n");

#ifdef _WIN32
    setColor(WHITE);
#else
    setColor(WHITE);
#endif

    // Split content by lines and print
    char contentCopy[1000];
    strncpy(contentCopy, content, 999); // Use strncpy for safety
    contentCopy[999] = '\0';
    char *line = strtok(contentCopy, "\n");

    while (line != NULL)
    {
        printf("\t│ %-56s │\n", line);
        line = strtok(NULL, "\n");
    }

#ifdef _WIN32
    setColor(YELLOW);
#else
    setColor(YELLOW);
#endif

    printf("\t└──────────────────────────────────────────────────────────┘\n");

#ifdef _WIN32
    setColor(RESET);
#else
    setColor(RESET);
#endif
}

void flashText(const char *text, int times, int delay)
{
    for (int i = 0; i < times; i++)
    {
#ifdef _WIN32
        setColor(GREEN);
#else
        setColor(GREEN);
#endif
        printf("\n\t\t%s", text);
        fflush(stdout);
        SLEEP(delay);

        // This line resets the text with spaces (back to transparent)
        printf("\r\t\t%*s", (int)strlen(text), " ");
        fflush(stdout);
        SLEEP(delay);
    }

#ifdef _WIN32
    setColor(GREEN);
#else
    setColor(GREEN);
#endif
    printf("\r\t\t%s\n", text);

#ifdef _WIN32
    setColor(RESET);
#else
    setColor(RESET);
#endif
}

// Linked List Functions
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteNode(Node **head, int data)
{
    if (*head == NULL)
        return;

    if ((*head)->data == data)
    {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node *current = *head;
    while (current->next != NULL && current->next->data != data)
    {
        current = current->next;
    }

    if (current->next != NULL)
    {
        Node *temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}

void visualizeLinkedList(Node *head)
{
    printf("\n\tLinked List Visualization:\n");
    printf("\t");

#ifdef _WIN32
    setColor(CYAN);
#else
    setColor(CYAN);
#endif

    Node *current = head;
    while (current != NULL)
    {
        printf("[%d]", current->data);
        if (current->next != NULL)
        {
            printf(" -> ");
        }
        current = current->next;
    }
    printf(" -> NULL\n");

#ifdef _WIN32
    setColor(RESET);
#else
    setColor(RESET);
#endif
}

void linkedListDemo()
{
    clear();
    // printHeader();
    printRetroBox("Linked List Demonstration",
                  "This section demonstrates Linked List operations\n"
                  "with visual animations.");

    loadingAnimation("\tInitializing Linked List", 30);

    Node *head = NULL;
    int choice, value;

    do
    {
        clear();
        printRetroBox("Linked List Operations",
                      "1. Insert Node\n"
                      "2. Delete Node\n"
                      "3. Animate Linked List Traversal\n"
                      "0. Back to Main Menu");

        visualizeLinkedList(head);

#ifdef _WIN32
        setColor(CYAN);
#else
        setColor(CYAN);
#endif

        printf("\n\tEnter operation choice: ");

#ifdef _WIN32
        setColor(RESET);
#else
        setColor(RESET);
#endif

        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ;
            choice = -1;
        }

        switch (choice)
        {
        case 1:
            printf("\t\tEnter value to insert: ");
            if (scanf("%d", &value) != 1)
            {
                while (getchar() != '\n')
                    ;
                printf("\t\tInvalid input!\n");
                SLEEP(1000);
                break;
            }
            insertNode(&head, value);

#ifdef _WIN32
            setColor(GREEN);
#else
            setColor(GREEN);
#endif

            printf("\t\tNode with value %d inserted successfully!\n", value);

#ifdef _WIN32
            setColor(RESET);
#else
            setColor(RESET);
#endif

            SLEEP(1000);
            break;

        case 2:
            printf("\t\tEnter value to delete: ");
            if (scanf("%d", &value) != 1)
            {
                while (getchar() != '\n')
                    ;
                printf("\t\tInvalid input!\n");
                SLEEP(1000);
                break;
            }
            deleteNode(&head, value);

#ifdef _WIN32
            setColor(RED);
#else
            setColor(RED);
#endif

            printf("\t\tNode with value %d deleted if it existed!\n", value);

#ifdef _WIN32
            setColor(RESET);
#else
            setColor(RESET);
#endif

            SLEEP(1000);
            break;

        case 3:
            printf("\n\t\tAnimating traversal...\n\t\t");
            Node *current = head;
            while (current != NULL)
            {
#ifdef _WIN32
                setColor(GREEN);
#else
                setColor(GREEN);
#endif

                printf("[%d]", current->data);
                fflush(stdout);
                SLEEP(300);

                if (current->next != NULL)
                {
                    printf(" -> ");
                    fflush(stdout);
                    SLEEP(1500);
                }

                current = current->next;
            }
            printf(" -> NULL\n");

#ifdef _WIN32
            setColor(RESET);
#else
            setColor(RESET);
#endif

            printf("\n\t\tTraversal complete! Press any key...");
            getch_wrapper();
            break;
        case 0:
            break; // Exit loop
        default:
            printf("\t\tInvalid choice!\n");
            SLEEP(1000);
        }
    } while (choice != 0);

    // Free memory
    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

// Stack Functions
Stack *createStack(int capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(capacity * sizeof(int));
    if (stack->array == NULL)
    {
        free(stack);
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return stack;
}

int isStackEmpty(Stack *stack)
{
    return stack->top == -1;
}

int isStackFull(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

void push(Stack *stack, int item)
{
    if (isStackFull(stack))
    {
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(Stack *stack)
{
    if (isStackEmpty(stack))
    {
        return -1;
    }
    return stack->array[stack->top--];
}

void visualizeStack(Stack *stack)
{
    printf("\n\tStack Visualization (Top to Bottom):\n");
    printf("\t┌───────┐\n");

    for (int i = stack->top; i >= 0; i--)
    {
#ifdef _WIN32
        setColor(YELLOW);
#else
        setColor(YELLOW);
#endif

        printf("\t│ %5d │", stack->array[i]);

        if (i == stack->top)
        {
            printf("  ← TOP");
        }

        printf("\n");

#ifdef _WIN32
        setColor(RESET);
#else
        setColor(RESET);
#endif

        printf("\t├───────┤\n");
    }

    printf("\t└───────┘\n");
}

void stackDemo()
{
    clear();
    printHeader();
    printRetroBox("Stack Implementation",
                  "This section demonstrates Stack operations\n"
                  "with visual animations.");

    loadingAnimation("Initializing Stack", 30);

    int capacity = 10;
    Stack *stack = createStack(capacity);
    int choice, value;

    do
    {
        clear();

        printRetroBox("Stack Operations",
                      "1. Push Element\n"
                      "2. Pop Element\n"
                      "0. Back to Main Menu");

        visualizeStack(stack);

#ifdef _WIN32
        setColor(CYAN);
#else
        setColor(CYAN);
#endif

        printf("\n\t\tEnter operation choice: ");

#ifdef _WIN32
        setColor(RESET);
#else
        setColor(RESET);
#endif

        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ;
            choice = -1;
        }

        switch (choice)
        {
        case 1:
            if (isStackFull(stack))
            {
#ifdef _WIN32
                setColor(RED);
#else
                setColor(RED);
#endif

                printf("\t\tStack Overflow! Cannot push more elements.\n");

#ifdef _WIN32
                setColor(RESET);
#else
                setColor(RESET);
#endif
            }
            else
            {
                printf("\t\tEnter value to push: ");
                if (scanf("%d", &value) != 1)
                {
                    while (getchar() != '\n')
                        ;
                    printf("\t\tInvalid input!\n");
                    SLEEP(1000);
                    break;
                }
                push(stack, value);

#ifdef _WIN32
                setColor(GREEN);
#else
                setColor(GREEN);
#endif

                printf("\t\tValue %d pushed onto stack!\n", value);

#ifdef _WIN32
                setColor(RESET);
#else
                setColor(RESET);
#endif
            }
            SLEEP(1000);
            break;

        case 2:
            if (isStackEmpty(stack))
            {
#ifdef _WIN32
                setColor(RED);
#else
                setColor(RED);
#endif

                printf("\t\tStack Underflow! Stack is empty.\n");

#ifdef _WIN32
                setColor(RESET);
#else
                setColor(RESET);
#endif
            }
            else
            {
                value = pop(stack);

#ifdef _WIN32
                setColor(MAGENTA);
#else
                setColor(MAGENTA);
#endif

                printf("\t\tValue %d popped from stack!\n", value);

#ifdef _WIN32
                setColor(RESET);
#else
                setColor(RESET);
#endif
            }
            SLEEP(1000);
            break;
        case 0:
            break; // Exit loop
        default:
            printf("\t\tInvalid choice!\n");
            SLEEP(1000);
        }
    } while (choice != 0);

    free(stack->array);
    free(stack);
}

// Queue Functions
Queue *createQueue(int capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (queue == NULL)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (int *)malloc(capacity * sizeof(int));
    if (queue->array == NULL)
    {
        free(queue);
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return queue;
}

int isQueueEmpty(Queue *queue)
{
    return queue->front == -1;
}

int isQueueFull(Queue *queue)
{
    return (queue->rear + 1) % queue->capacity == queue->front;
}

void enqueue(Queue *queue, int item)
{
    if (isQueueFull(queue))
    {
        return;
    }

    if (isQueueEmpty(queue))
    {
        queue->front = queue->rear = 0;
    }
    else
    {
        queue->rear = (queue->rear + 1) % queue->capacity;
    }

    queue->array[queue->rear] = item;
}

int dequeue(Queue *queue)
{
    if (isQueueEmpty(queue))
    {
        return -1;
    }

    int item = queue->array[queue->front];

    if (queue->front == queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    else
    {
        queue->front = (queue->front + 1) % queue->capacity;
    }

    return item;
}

void visualizeQueue(Queue *queue)
{
    printf("\n\tQueue Visualization:\n");
    printf("\t");

    if (isQueueEmpty(queue))
    {
        printf("[EMPTY QUEUE]\n");
        return;
    }

#ifdef _WIN32
    setColor(YELLOW);
#else
    setColor(YELLOW);
#endif

    int i = queue->front;
    printf("FRONT → ");

    while (1)
    {
        printf("[%d]", queue->array[i]);

        if (i == queue->rear)
        {
            break;
        }

        printf(" → ");
        i = (i + 1) % queue->capacity;
    }

    printf(" ← REAR\n");

#ifdef _WIN32
    setColor(RESET);
#else
    setColor(RESET);
#endif
}

void queueDemo()
{
    clear();
    printHeader();
    printRetroBox("Queue Implementation",
                  "This section demonstrates Queue operations\n"
                  "with visual animations.");

    loadingAnimation("Initializing Queue", 30);

    int capacity = 10;
    Queue *queue = createQueue(capacity);
    int choice, value;

    do
    {
        clear();
        printRetroBox("Queue Operations",
                      "1. Push Element\n"
                      "2. Pop Element\n"
                      "3. Animate Queue Operations\n"
                      "0. Back to Main Menu");

        visualizeQueue(queue);

#ifdef _WIN32
        setColor(CYAN);
#else
        setColor(CYAN);
#endif

        printf("\n\tEnter operation choice: ");

#ifdef _WIN32
        setColor(RESET);
#else
        setColor(RESET);
#endif

        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ;
            choice = -1;
        }

        switch (choice)
        {
        case 1:
            if (isQueueFull(queue))
            {
#ifdef _WIN32
                setColor(RED);
#else
                setColor(RED);
#endif

                printf("\t\tQueue is Full! Cannot enqueue more elements.\n");

#ifdef _WIN32
                setColor(RESET);
#else
                setColor(RESET);
#endif
            }
            else
            {
                printf("\t\tEnter value to enqueue: ");
                if (scanf("%d", &value) != 1)
                {
                    while (getchar() != '\n')
                        ;
                    printf("\t\tInvalid input!\n");
                    SLEEP(1000);
                    break;
                }
                enqueue(queue, value);

#ifdef _WIN32
                setColor(GREEN);
#else
                setColor(GREEN);
#endif

                printf("\t\tValue %d added to queue!\n", value);

#ifdef _WIN32
                setColor(RESET);
#else
                setColor(RESET);
#endif
            }
            SLEEP(1000);
            break;

        case 2:
            if (isQueueEmpty(queue))
            {
#ifdef _WIN32
                setColor(RED);
#else
                setColor(RED);
#endif

                printf("\t\tQueue is Empty! Nothing to dequeue.\n");

#ifdef _WIN32
                setColor(RESET);
#else
                setColor(RESET);
#endif
            }
            else
            {
                value = dequeue(queue);

#ifdef _WIN32
                setColor(MAGENTA);
#else
                setColor(MAGENTA);
#endif

                printf("\t\tValue %d removed from queue!\n", value);

#ifdef _WIN32
                setColor(RESET);
#else
                setColor(RESET);
#endif
            }
            SLEEP(1000);
            break;

        case 3:
            printf("\n\t\tAnimating queue operations...\n");

            // Clear any existing queue
            while (!isQueueEmpty(queue))
            {
                dequeue(queue);
            }

            // Animate enqueuing
            for (int i = 1; i <= 5; i++)
            {
                if (!isQueueFull(queue))
                {
                    enqueue(queue, i * 10);
                    printf("\t\tEnqueuing %d...\n", i * 10);
                    visualizeQueue(queue);
                    SLEEP(1000);
                    if (i < 5)
                    {
                        clear();
                        printHeader();
                    }
                }
            }

            // Animate dequeuing
            for (int i = 0; i < 3; i++)
            {
                if (!isQueueEmpty(queue))
                {
                    int val = dequeue(queue);
                    printf("\t\tDequeuing %d...\n", val);
                    visualizeQueue(queue);
                    SLEEP(500);
                    if (i < 2)
                    {
                        clear();
                        printHeader();
                    }
                }
            }

            printf("\n\t\tAnimation complete! Press any key...");
            getch_wrapper();
            break;
        case 0:
            break; // Exit loop
        default:
            printf("\t\tInvalid choice!\n");
            SLEEP(1000);
        }
    } while (choice != 0);

    free(queue->array);
    free(queue);
}

// Binary Tree Functions---------------------------------------------------------------
TreeNode *createTreeNode(int data)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    if (newNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode *insertTreeNode(TreeNode *root, int data)
{
    if (root == NULL)
    {
        return createTreeNode(data);
    }

    if (data < root->data)
    {
        root->left = insertTreeNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertTreeNode(root->right, data);
    }

    return root;
}

void visualizeBinaryTree(TreeNode *root, int space)
{
    if (root == NULL)
    {
        return;
    }

    space += 5;

    visualizeBinaryTree(root->right, space);

    printf("\n");
    for (int i = 5; i < space; i++)
    {
        printf(" ");
    }

#ifdef _WIN32
    setColor(GREEN);
#else
    setColor(GREEN);
#endif

    printf("[%d]", root->data);

#ifdef _WIN32
    setColor(RESET);
#else
    setColor(RESET);
#endif

    visualizeBinaryTree(root->left, space);
}

void inorderTraversal(TreeNode *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        fflush(stdout); // Added for animation effect
        SLEEP(100);     // Added for animation effect
        inorderTraversal(root->right);
    }
}

void preorderTraversal(TreeNode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        fflush(stdout); // Added for animation effect
        SLEEP(100);     // Added for animation effect
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(TreeNode *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
        fflush(stdout); // Added for animation effect
        SLEEP(100);     // Added for animation effect
    }
}

void freeTree(TreeNode *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

void binaryTreeDemo()
{
    clear();
    printHeader();
    printRetroBox("Binary Tree Visualization",
                  "This section demonstrates Binary Tree operations\n"
                  "with visual animations and traversal demonstrations.");

    loadingAnimation("Initializing Binary Tree", 30);

    TreeNode *root = NULL;
    int choice, value;

    do
    {
        clear();
        
        printRetroBox("Binary Tree Operations",
                      "1. Insert Node\n"
                      "2. Inorder Traversal\n"
                      "3. Preorder Traversal\n"
                      "4. Postorder Traversal\n"
                      "5. Animate Tree Traversal\n"
                      "0. Back to Main Menu");

        printf("\n\tCurrent Binary Tree Structure:\n");
        visualizeBinaryTree(root, 0);
        printf("\n\n");

#ifdef _WIN32
        setColor(CYAN);
#else
        setColor(CYAN);
#endif

        printf("\t\tEnter operation choice: ");

#ifdef _WIN32
        setColor(RESET);
#else
        setColor(RESET);
#endif

        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ;
            choice = -1;
        }

        switch (choice)
        {
        case 1:
            printf("\t\tEnter value to insert: ");
            if (scanf("%d", &value) != 1)
            {
                while (getchar() != '\n')
                    ;
                printf("\t\tInvalid input!\n");
                SLEEP(1000);
                break;
            }
            root = insertTreeNode(root, value);

#ifdef _WIN32
            setColor(GREEN);
#else
            setColor(GREEN);
#endif

            printf("\t\tNode with value %d inserted successfully!\n", value);

#ifdef _WIN32
            setColor(RESET);
#else
            setColor(RESET);
#endif

            SLEEP(1000);
            break;

        case 2:
            printf("\n\t\tInorder Traversal: ");

#ifdef _WIN32
            setColor(YELLOW);
#else
            setColor(YELLOW);
#endif

            inorderTraversal(root);

#ifdef _WIN32
            setColor(RESET);
#else
            setColor(RESET);
#endif

            printf("\n\t\tTraversal complete! Press any key...");
            getch_wrapper();
            break;

        case 3:
            printf("\n\t\tPreorder Traversal: ");

#ifdef _WIN32
            setColor(YELLOW);
#else
            setColor(YELLOW);
#endif

            preorderTraversal(root);

#ifdef _WIN32
            setColor(RESET);
#else
            setColor(RESET);
#endif

            printf("\n\t\tTraversal complete! Press any key...");
            getch_wrapper();
            break;

        case 4:
            printf("\n\t\tPostorder Traversal: ");

#ifdef _WIN32
            setColor(YELLOW);
#else
            setColor(YELLOW);
#endif

            postorderTraversal(root);

#ifdef _WIN32
            setColor(RESET);
#else
            setColor(RESET);
#endif

            printf("\n\t\tTraversal complete! Press any key...");
            getch_wrapper();
            break;

        case 5:
            printf("\n\t\tAnimating tree traversal...\n");

            printf("\t\tInorder (L Root R): ");
            inorderTraversal(root);
            printf("\n");

            printf("\t\tPreorder (Root L R): ");
            preorderTraversal(root);
            printf("\n");

            printf("\t\tPostorder (L R Root): ");
            postorderTraversal(root);
            printf("\n");

            printf("\n\n\t\tAnimation complete! Press any key...");
            getch_wrapper();
            break;
        case 0:
            break; // Exit loop
        default:
            printf("\t\tInvalid choice!\n");
            SLEEP(2000);
        }
    } while (choice != 0);

    // Free tree memory
    freeTree(root);
}
